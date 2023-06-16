#ifndef PSE_METRO_SIMULATIE_RENDERER_H
#define PSE_METRO_SIMULATIE_RENDERER_H

#include "../src/MetroSystem.h"
#include "RenderObject.h"

class MetroRenderer {
public:
    static void renderSystem(const MetroSystem &system, const std::string &fileName);
    static std::vector<RenderObject*> getObjects(const MetroSystem &system);
    static std::string getSVGString(const MetroSystem &system);
    static RenderObject *addStation(const MetroSystem &system, const std::string &inputAttrs, std::map<TramStop *, std::pair<double, double>> &posMap);
    static std::vector<RenderObject *> addConnections(const MetroSystem &system, std::map<TramStop *, std::pair<double, double>> &posMap);
    static std::vector<RenderObject *> addTrams(const MetroSystem &system, std::map<TramStop *, std::pair<double, double>> &posMap);

    const static int tramSize = 10;
    const static int stationSize = 30;
    const static int spoorWidth = 5;
};


#endif //PSE_METRO_SIMULATIE_RENDERER_H
