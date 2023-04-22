#ifndef PSE_METRO_SIMULATIE_METRORENDERER_H
#define PSE_METRO_SIMULATIE_METRORENDERER_H

#include "MetroSystem.h"
#include "Line.h"
#include "TramStop.h"
#include "Tram.h"
#include "Track.h"

class RenderObject {
public:
    RenderObject(double x, double y, double rotation, std::string type);
    double x;
    double y;
    double rotation;
    std::string type;
};

class MetroRenderer {
public:
    static void createIni(const MetroSystem &system, std::ostream &ostream);
    static std::vector<RenderObject> generateScene(const MetroSystem &system);
    static void createGeneral(std::ostream &ostream);
    static void createObjects(std::ostream &ostream, const std::vector<RenderObject> &objects);
};


#endif //PSE_METRO_SIMULATIE_METRORENDERER_H
