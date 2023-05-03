#include "MetroRenderer.h"
#define _USE_MATH_DEFINES
#include "cmath"
#include "MetroSystemOutput.h"

void MetroRenderer::createIni(MetroSystem *system, std::ostream &ostream) {
    std::string svg = getSVGString(system);

    std::istringstream svgStream;
    svgStream.str(svg);

    createGeneral(ostream);
    generateScene(system,svgStream, ostream);
}

std::string MetroRenderer::getSVGString(MetroSystem *system) {
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

void MetroRenderer::createGeneral(std::ostream &ostream) {
    ostream << "[General]\n";
    ostream << "size = 1000\n";
    ostream << "backgroundcolor = (0, 0, 0)\n";
    ostream << "type = \"ZBufferedWireframe\"\n";
    ostream << "eye = (1000, 200, 1000)\n";
}

void MetroRenderer::generateScene(MetroSystem *system, std::istringstream &svg, std::ostream &ostream) {
    std::map<TramStop*,std::pair<double,double> > posMap;

    int figureCount = 0;
    std::stringstream figures;
    std::string line;
    bool obj = false;
    bool ignoreG = true;
    std::string objString;
    while (std::getline(svg, line)) {
        if (line.at(1)=='g' && !obj) {
            if (ignoreG) {
                ignoreG = false;
            } else {
                obj = true;
            }
        }
        else if (line.at(1)=='/' && line.at(2) == 'g' && obj) {
            obj = false;
            addObject(system,objString, figures, figureCount, posMap);
            objString = "";
            continue;
        }

        if (obj) objString += line + '\n';
    }
    addConnections(system, posMap, figureCount, figures);
    addTrams(system, posMap, figureCount, figures);
    ostream << "nrFigures = " << figureCount << std::endl << std::endl;
    ostream << figures.str() << std::endl;
}

void MetroRenderer::addObject(MetroSystem *system, const std::string &inputAttrs, std::ostream &stream, int &figureCount, std::map<TramStop*, std::pair<double,double> > &posMap) {
    std::istringstream objStream;
    objStream.str(inputAttrs);

    std::string classLine;
    std::getline(objStream, classLine);

    bool station = classLine.at(classLine.size()-4) == 'd'; //match end of string with "node>" -> we have a station
    if (!station) return;

    stream << "[Figure" << figureCount++ << "]\n";
    stream << "type = \"Cube\"\n";
    stream << "scale = 20\n";
    stream << "rotateX = 0 \n";
    stream << "rotateY = 0 \n";
    stream << "rotateZ = 0 \n";
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

    TramStop *tram=NULL;
    std::vector<TramStop*> stations = system->getStations();
    std::vector<TramStop*>::iterator it = stations.begin();

    while (it!=stations.end()) {
        TramStop *t = *it;
        if (t->getName()==name) {
            tram=t;
        }
        it++;
    }

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
    posMap[tram] = std::pair<double,double>(x,y);
    stream << "center = (" << x << ", " << y << ", " << z << ")\n";
    stream << "color = (0,1,0)\n\n";
}

void MetroRenderer::addConnections(MetroSystem *system, std::map<TramStop *, std::pair<double, double> > &posMap, int &figureCount, std::ostream &stream) {
    std::map<TramStop*,int> indexes;

    std::stringstream connections;
    connections << "[Figure" << figureCount++ << "]\n";
    connections << "type = \"LineDrawing\"\n";
    connections << "scale = 1\n";
    connections << "rotateX = 0 \n";
    connections << "rotateY = 0 \n";
    connections << "rotateZ = 0 \n";
    connections << "nrPoints = " << posMap.size() << std::endl;
    std::map<TramStop *, std::pair<double, double> >::iterator it = posMap.begin();
    int count = 0;
    while (it!=posMap.end()) {
        std::pair<TramStop *, std::pair<double, double> > p = *it;
        indexes[p.first] = count;
        connections << "point" << count << " = (" << p.second.first << "," << p.second.second << ", 0)\n";
        count++;
        it++;
    }

    int connectionCount = 0;
    std::vector<Line*> lines = system->getLines();
    std::vector<Line*>::iterator lineIt = lines.begin();
    while (lineIt!=lines.end()) {
        Line* line = *lineIt;
        std::vector<TramStop*> stations = line->getStations();
        std::vector<TramStop*>::iterator stationIt = stations.begin();
        while (stationIt!=stations.end()) {
            TramStop *curr = *stationIt;
            TramStop *next = line->getNext(curr);
            if (next==NULL) continue;

            connections << "line" << connectionCount << " = (" << indexes[curr] << ", " << indexes[next] << ")\n";
            connectionCount++;
            stationIt++;
        }
        lineIt++;
    }
    connections << "center = (0,0,0)\n";
    connections << "color = (1, 0.5, 0)\n";
    connections << "nrLines = " << connectionCount << std::endl << std::endl;
    stream << connections.str();
}

void MetroRenderer::addTrams(MetroSystem *system, std::map<TramStop *, std::pair<double, double> > &posMap, int &figureCount, std::ostream &stream) {
    std::vector<Line *> lines = system->getLines();
    std::vector<Line *>::iterator lineIt = lines.begin();
    while (lineIt != lines.end()) {
        Line *line = *lineIt;
        std::vector<Tram*> trams = line->getTrams();
        std::vector<Tram*>::iterator tramIt = trams.begin();
        while (tramIt!=trams.end()) {
            Tram* tram = *tramIt;
            stream << "[Figure" << figureCount++ << "]\n";
            stream << "type = \"Torus\"\n";
            stream << "r = 10\n";
            stream << "R = 10\n";
            stream << "m = 36\n";
            stream << "n = 36\n";
            stream << "scale = 1\n";
            stream << "rotateX = 0 \n";
            stream << "rotateY = 0 \n";
            stream << "rotateZ = 0 \n";
            stream << "center = (" << posMap[tram->getCurrentStation()].first << "," << posMap[tram->getCurrentStation()].second << ",20)\n";
            stream << "color = (1, 0.5, 0)\n\n";
            tramIt++;
        }
        lineIt++;
    }
}
