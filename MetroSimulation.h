#ifndef PSE_METRO_SIMULATIE_METROSIMULATION_H
#define PSE_METRO_SIMULATIE_METROSIMULATION_H
#include "string"
#include "vector"

class Tram;
class Station;
class Line;

class MetroSimulation {
public:
    explicit MetroSimulation(const std::string& filename);

    bool isProperlyInitialized() const;
private:
    std::vector<Tram*> trams;
    std::vector<Station*> stations;
    std::vector<Line*> lines;

    bool properlyInitialized;
};


#endif //PSE_METRO_SIMULATIE_METROSIMULATION_H
