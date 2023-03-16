#ifndef PSE_METRO_SIMULATIE_METROSIMULATION_H
#define PSE_METRO_SIMULATIE_METROSIMULATION_H
#include "string"
#include "vector"
#include "ostream"
#include "Tram.h"
#include "Station.h"
#include "Line.h"

class MetroSimulation {
public:
    // Constructor
    explicit MetroSimulation(const std::string& filename, std::ostream &errorstream, unsigned int runtime);

    // Destructor
    // TODO destructor maken

    // System operations
    void start(std::ostream &os);
    void update(std::ostream &os);

    // Getters
    const std::vector<Station *> &getStations() const;
    const std::vector<Tram *> &getTrams() const;

    // Other
    void outputMetroSimulation(std::ostream &stream);

private:
    // Other
    bool properlyInitialized() const;

    // Data
    std::vector<Line*> lines;
    std::vector<Station*> stations;
    std::vector<Tram*> trams;

    unsigned int runtime;
    unsigned int time;

    MetroSimulation* _initCheck;
    std::ostream &errorstream;
};


#endif //PSE_METRO_SIMULATIE_METROSIMULATION_H
