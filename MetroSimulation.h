#ifndef PSE_METRO_SIMULATIE_METROSIMULATION_H
#define PSE_METRO_SIMULATIE_METROSIMULATION_H
#include "string"
#include "vector"

class Tram;
class Station;

class MetroSimulation {
public:
    explicit MetroSimulation(const std::string& filename);

    bool isProperlyInitialized() const;
private:
    std::vector<Tram*> trams;
    std::vector<Station*> stations;

    bool properlyInitialized;
};


#endif //PSE_METRO_SIMULATIE_METROSIMULATION_H
