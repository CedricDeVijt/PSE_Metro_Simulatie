#include "MetroRenderer.h"
#define _USE_MATH_DEFINES
#include "cmath"

RenderObject::RenderObject(double x, double y, std::string type) : x(x), y(y), x2(0),y2(0), type(type) {}

RenderObject::RenderObject(double x, double y, double x2, double y2, const std::string &type) : x(x), y(y), x2(x2),
                                                                                                y2(y2), type(type) {}

void MetroRenderer::createIni(const MetroSystem &system, std::ostream &ostream) {
    createGeneral(ostream);
    createObjects(ostream, generateScene(system));
}

void MetroRenderer::createGeneral(std::ostream &ostream) {
    ostream << "[General]\n";
    ostream << "size = 1000\n";
    ostream << "backgroundcolor = (0, 0, 0)\n";
    ostream << "type = \"Wireframe\"\n";
    ostream << "eye = (1000, 500, 1000)\n";
}

std::vector<RenderObject> MetroRenderer::generateScene(const MetroSystem &system) {
    std::vector<RenderObject> objects;
    std::vector<Line*> lines = system.getLines();
    std::vector<Line*>::iterator it = lines.begin();
    int spacing = 100;
    while (it!=lines.end()) {
        Line* line = *it;
        double centerX = 0;
        double centerY = 0;
        double angleStep = 360/(int)line->getStations().size();
        double angle = 0;
        TramStop* first = line->getStations()[0];
        TramStop* current = first;
        do {
            double x = centerX+spacing*cos(angle*M_PI/180);
            double y = centerY+spacing*sin(angle*M_PI/180);
            angle+=angleStep;
            double x2 = centerX+spacing*cos(angle*M_PI/180);
            double y2 = centerY+spacing*sin(angle*M_PI/180);

            objects.push_back(RenderObject(x,y, "Station"));
            objects.push_back(RenderObject(x,y,x2,y2,"Track"));

            current = line->getNext(current);
        } while (current!=first);
        it++;
    }
    return objects;
}

void MetroRenderer::createObjects(std::ostream &ostream, const std::vector<RenderObject> &objects) {
    int nrFigures = (int)objects.size();
    ostream << "nrFigures = " << nrFigures << "\n";
    ostream << std::endl;
    for (int i = 0; i < nrFigures; i++) {
        ostream << "[Figure" << i << "]\n";
        if (objects[i].type == "Station") {
            ostream << "type = \"Cube\"\n";
            ostream << "scale = 1\n";
            ostream << "rotateX = 0\n";
            ostream << "rotateY = 0\n";
            ostream << "rotateZ = 0\n";
            ostream << "center = (" << lround(objects[i].x) << ", " << lround(objects[i].y) << ", 0)\n";
            ostream << "color = (0, 1, 0)\n";
            ostream << std::endl;
        }
        else if (objects[i].type == "Track") {
            ostream << "type = \"LineDrawing\"\n";
            ostream << "rotateX = 0\n";
            ostream << "rotateY = 0\n";
            ostream << "rotateZ = 0\n";
            ostream << "scale = 1\n";
            ostream << "center = (0,0,0)\n";
            ostream << "color = (1, 1, 0)\n";
            ostream << "nrPoints = 2\n";
            ostream << "nrLines = 1\n";
            ostream << "point0 = ( " << lround(objects[i].x) << ", " << lround(objects[i].y) << ", -2)\n";
            ostream << "point1 = ( " << lround(objects[i].x2) << ", " << lround(objects[i].y2) << ", -2)\n";
            ostream << "line0 = (0,1)\n";
            ostream << std::endl;
        }
    }
}

