#include "MetroRenderer.h"
#include "../src/MetroSystemOutput.h"
#include "fstream"
#include "string"
#include "RenderObject.h"
#include "Objects/Scene.h"
#include "Objects/Light.h"
#include "Include/ini_configuration.h"
#include "Include/easy_image.h"
#include "Objects/Renderer.h"
#include "Include/vector3d.h"


void MetroRenderer::renderSystem(const MetroSystem &system, const std::string &fileName) {
    Scene s;

    for (RenderObject * object : getObjects(system)) {
        s.objects3D.push_back(object->createRender());
        delete object;
    }

    s.camera = Camera(ini::DoubleTuple({2000,2000,1000}), false, ini::DoubleTuple({0,0,0}),0,0,0,0);

    InfLight *infL =new InfLight();
    infL->ambientLight = {1,1,1};
    infL->diffuseLight = {1,1,1};

    ini::DoubleTuple directionTuple({-1,-1,-1});
    Vector3D dir;
    dir.x = directionTuple[0];
    dir.y = directionTuple[1];
    dir.z = directionTuple[2];
    infL->ldVector = Vector3D::normalise(dir);
    s.lights.push_back(infL);

    s.triangulate();
    s.camera.eyePointTransform(s.objects3D);

    img::EasyImage image;
//    image = Renderer::drawZBufTriangles(img::Color(0,0,0),s.getTriangles(), s.project(1), 1000, s.lights);
    image = Renderer::draw2DLines(img::Color(0,0,0), s.project(1), 1000, true);
    std::string outputName = fileName;
    if(image.get_height() > 0 && image.get_width() > 0)
    {
        std::string::size_type pos = fileName.rfind('.');
        if(pos == std::string::npos)
        {
            //filename does not contain a '.' --> append a '.bmp' suffix
            outputName += ".bmp";
        }
        else
        {
            outputName = fileName.substr(0,pos) + ".bmp";
        }
        try
        {
            std::ofstream f_out(outputName.c_str(),std::ios::trunc | std::ios::out | std::ios::binary);
            f_out << image;

        }
        catch(std::exception& ex)
        {
            std::cerr << "Failed to write image to file: " << ex.what() << std::endl;
        }
    }
    else
    {
        std::cout << "Could not generate image for " << fileName << std::endl;
    }
}

std::string MetroRenderer::getSVGString(const MetroSystem &system) {
    MetroSystemOutput::createDotOutput(system,"renderer",".svg");

    std::ifstream file("./dots/renderer.svg");

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string ret = buffer.str();

    file.close();

    bool succesDelete = std::remove("./dots/renderer.svg")==0;
    REQUIRE(succesDelete, "Failed to delete renderer svg file.");

    return ret;
}

std::vector<RenderObject*> MetroRenderer::getObjects(const MetroSystem &system) {
    std::vector<RenderObject*> objects;

    std::string svg = getSVGString(system);

    std::istringstream svgStream;
    svgStream.str(svg);

    std::map<TramStop*,std::pair<double,double> > posMap;

    std::string line;
    bool obj = false;
    bool ignoreG = true;
    std::string objString;
    while (std::getline(svgStream, line)) {
        if (line.at(1)=='g' && !obj) {
            if (ignoreG) {
                ignoreG = false;
            } else {
                obj = true;
            }
        }
        else if (line.at(1)=='/' && line.at(2) == 'g' && obj) {
            obj = false;
            RenderObject* station = addStation(system,objString,posMap);
            if (station != nullptr) {
                objects.push_back(station);
            }
            objString = "";
            continue;
        }

        if (obj) objString += line + '\n';
    }
    std::vector<RenderObject*> connections = addConnections(system, posMap);
    std::vector<RenderObject*> trams = addTrams(system, posMap);

    objects.insert(objects.end(), connections.begin(), connections.end());
    objects.insert(objects.end(), trams.begin(), trams.end());
    return objects;
}

RenderObject* MetroRenderer::addStation(const MetroSystem &system, const std::string &inputAttrs, std::map<TramStop*, std::pair<double,double> > &posMap) {
    std::istringstream objStream;
    objStream.str(inputAttrs);

    std::string classLine;
    std::getline(objStream, classLine);

    bool station = classLine.at(classLine.size()-4) == 'd'; //match end of string with "node>" -> we have a station
    if (!station) return nullptr;

    double x = 0, y = 0, z = 0;
    std::string titleLine;
    std::string ellipseLine;
    std::getline(objStream, titleLine);
    std::getline(objStream, ellipseLine);

    std::string name;
    for (int i = 0; i < (int)titleLine.size(); i++) {
        if (titleLine.at(i)=='>') {
            i++;
            while (titleLine.at(i)!='<') {
                name += titleLine.at(i);
                i++;
            }
            break;
        }
    }

    TramStop *tramstop=nullptr;

    for (TramStop* t:system.getStations()) {
        if (t->getName()==name) {
            tramstop=t;
        }
    }

    if (tramstop==nullptr) return nullptr;

    for (int i = 0; i < (int)ellipseLine.size(); i++) {
        char c = ellipseLine.at(i);
        if (c == 'c') {
            i++;
            char axis = ellipseLine.at(i);
            if (axis != 'x' && axis != 'y') continue;
            i += 3;
            std::string num;
            while (ellipseLine.at(i)!='\"') {
                num += ellipseLine.at(i);
                i++;
            }
            int numInt = atoi(num.c_str());
            if (axis=='x') {
                x = numInt;
            } else {
                y = numInt;
            }
        }
    }
    posMap[tramstop] = std::pair<double,double>(x,y);
    RenderObject *object;
    if (dynamic_cast<Halte*>(tramstop)) {
        return new HalteRender(x, y ,z);
    }
    else if (dynamic_cast<Metrostation*>(tramstop)) {
        return new MetrostationRender(x, y, z);
    }
    return nullptr;
}

std::vector<RenderObject*> MetroRenderer::addConnections(const MetroSystem &system, std::map<TramStop *, std::pair<double, double> > &posMap) {
    std::vector<RenderObject*> connections;
    for (Line* line:system.getLines()) {
        for (TramStop* curr:line->getStations()) {
            TramStop *next = line->getNext(curr);
            if (next== nullptr) continue;

            double x1, x2, y1, y2, z1=0, z2=0;
            x1 = posMap[curr].first;
            y1 = posMap[curr].second;

            x2 = posMap[next].first;
            y2 = posMap[next].second;

            connections.push_back(new SpoorRender(x1, y1, z1, x2, y2, z2));
        }
    }
    return connections;
}

std::vector<RenderObject*> MetroRenderer::addTrams(const MetroSystem &system, std::map<TramStop *, std::pair<double, double> > &posMap) {
    std::vector<RenderObject*> trams;
    for (Line* line:system.getLines()) {
        for (Tram* tram:line->getTrams()) {
            double x, y , z;
            TramStop *curr = tram->getCurrentStation();
            x = posMap[curr].first;
            y = posMap[curr].second;
            z = MetroRenderer::stationSize+MetroRenderer::tramSize;

            RenderObject *obj;
            if (dynamic_cast<Albatros*>(tram)) {
                obj = new AlbatrosRender(x, y, z);
            }
            else if (dynamic_cast<PCC*>(tram)) {
                obj = new PCCRender(x, y, z);
            }
            else if (dynamic_cast<Stadslijner*>(tram)) {
                obj = new StadsLijnerRender(x, y, z);
            } else continue;
            trams.push_back(obj);
        }
    }
    return trams;
}
