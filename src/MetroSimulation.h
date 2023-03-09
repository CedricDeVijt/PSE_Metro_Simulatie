#ifndef PSE_METRO_SIMULATIE_METROSIMULATION_H
#define PSE_METRO_SIMULATIE_METROSIMULATION_H
#include "string"
#include "vector"
#include "ostream"

class Tram;
class Station;
class Line;

class MetroSimulation {
public:
    explicit MetroSimulation(const std::string& filename, unsigned int runtime);
    bool isProperlyInitialized() const;
    void start(std::ostream &os);
    void update(std::ostream &os);

    // getters
    const std::vector<Station *> &getStations() const;
    const std::vector<Tram *> &getTrams() const;

    // Other
    void outputMetroSimulation(std::ostream &stream);

private:
    std::vector<Line*> lines;
    std::vector<Station*> stations;
    std::vector<Tram*> trams;

    bool properlyInitialized;
    unsigned int runtime;
    unsigned int time;
};


#endif //PSE_METRO_SIMULATIE_METROSIMULATION_H
