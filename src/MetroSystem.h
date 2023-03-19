#ifndef PSE_METRO_SIMULATIE_METROSYSTEM_H
#define PSE_METRO_SIMULATIE_METROSYSTEM_H

#include "vector"
#include "Line.h"
#include "Station.h"
#include "DesignByContract.h"
#include "MetroXMLParser.h"
#include "Logger.h"

class MetroSystem {
public:
    explicit MetroSystem(const std::string& filename, std::ostream &errorstream);

    void updateSystem(std::ostream &os);
    void outputMetroSystem(std::ostream &stream);
private:
    // Other
    bool properlyInitialized() const;

    // Data
    std::vector<Line*> lines;
    std::vector<Station*> stations;
    std::vector<Tram*> trams;

    unsigned int runtime;
    unsigned int time;

    MetroSystem* _initCheck;
    std::ostream &errorstream;

};


#endif //PSE_METRO_SIMULATIE_METROSYSTEM_H
