#include "MetroRenderer.h"
#include "cmath"

RenderObject::RenderObject(double x, double y, double rotation, std::string type) : x(x), y(y), rotation(rotation), type(type) {}

void MetroRenderer::createIni(const MetroSystem &system, std::ostream &ostream) {
    createGeneral(ostream);
    createObjects(ostream, generateScene(system));
}

void MetroRenderer::createGeneral(std::ostream &ostream) {
    ostream << "[General]\n";
    ostream << "size = 1000\n";
    ostream << "backgroundcolor = (0, 0, 0)\n";
    ostream << "type = \"ZBuffering\"\n";
    ostream << "eye = (1000, 500, 1000)\n";
}

std::vector<RenderObject> MetroRenderer::generateScene(const MetroSystem &system) {
    std::vector<RenderObject> objects;
    std::vector<Line*> lines = system.getLines();
    std::vector<Line*>::iterator it = lines.begin();
    int spacing = 100;
    while (it!=lines.end()) {
        Line* line = *it;
        double x = 0;
        double y = 0;
        double angleStep = 360/static_cast<int>(line->getStations().size());
        double angle = 0;
        TramStop* first = line->getStations()[0];
        TramStop* current = first;
        do {
            x += spacing*cos(angle);
            y += spacing*sin(angle);
            angle+=angleStep;

            objects.push_back(RenderObject(x,y,0, "Station"));
            objects.push_back(RenderObject(x,y,angle,"Track"));

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
            ostream << "center = (" << objects[i].x << ", " << objects[i].y << ", 0)\n";
            ostream << "color = (0, 1, 0)\n";
            ostream << std::endl;
        }
        else if (objects[i].type == "Track") {
            ostream << "type = \"LineDrawing\"\n";
            ostream << "rotateX = " << -objects[i].rotation << "\n";
            ostream << "rotateY = 0\n";
            ostream << "rotateZ = 0\n";
            ostream << "scale = 100\n";
            ostream << "center = (" << objects[i].x << ", " << objects[i].y << ", 0)\n";
            ostream << "color = (1, 1, 0)\n";
            ostream << "nrPoints = 4\n";
            ostream << "nrLines = 2\n";
            ostream << "point0 = (-1.0, 0.0, 0.0)\n";
            ostream << "point1 = (-1.0, 1.0, 0.0)\n";
            ostream << "point2 = (1.0, 0.0, 0.0)\n";
            ostream << "point3 = (1.0, 1.0, 0.0)\n";
            ostream << "line0 = (0,1)\n";
            ostream << "line1 = (2,3)\n";
        }
    }
}
