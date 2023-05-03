#ifndef PSE_METRO_SIMULATIE_METRORENDERER_H
#define PSE_METRO_SIMULATIE_METRORENDERER_H

#include "MetroSystem.h"
#include "Line.h"
#include "TramStop.h"
#include "Tram.h"
#include "Track.h"
#include "sstream"
#include "fstream"
#include "map"

class MetroRenderer {
public:
    static void createIni(MetroSystem *system, std::ostream &ostream);
    static void generateScene(MetroSystem *system, std::istringstream &svg, std::ostream &ostream);
    static void createGeneral(std::ostream &ostream);
    static std::string getSVGString(MetroSystem *system);
    static void addObject(MetroSystem *system, const std::string &inputAttrs, std::ostream &stream, int &figureCount, std::map<TramStop*, std::pair<double,double> > &posMap);
    static void addConnections(MetroSystem *system, std::map<TramStop*, std::pair<double,double> > &posMap, int &figureCount, std::ostream &stream);
    static void addTrams(MetroSystem *system, std::map<TramStop*, std::pair<double,double> > &posMap, int &figureCount, std::ostream &stream);
};


#endif //PSE_METRO_SIMULATIE_METRORENDERER_H
