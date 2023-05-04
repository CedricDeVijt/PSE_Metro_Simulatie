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

/**
 * Object that handles the rendering for a MetroSystem
 */
class MetroRenderer {
public:
    /**
     * Creates an ini file compatible with Computer Graphics Engine
     *
     * @param system is the MetroSystem you want created into an ini file
     * @param ostream is the stream the ini file gets written to
     */
    static void createIni(MetroSystem *system, std::ostream &ostream);
private:
    static void generateScene(MetroSystem *system, std::istringstream &svg, std::ostream &ostream);
    static void createGeneral(std::ostream &ostream);
    static std::string getSVGString(MetroSystem *system);
    static void addObject(MetroSystem *system, const std::string &inputAttrs, std::ostream &stream, int &figureCount, std::map<TramStop*, std::pair<double,double> > &posMap);
    static void addConnections(MetroSystem *system, std::map<TramStop*, std::pair<double,double> > &posMap, int &figureCount, std::ostream &stream);
    static void addTrams(MetroSystem *system, std::map<TramStop*, std::pair<double,double> > &posMap, int &figureCount, std::ostream &stream);
};


#endif //PSE_METRO_SIMULATIE_METRORENDERER_H
