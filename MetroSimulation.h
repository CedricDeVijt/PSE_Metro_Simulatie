#include "string"
#include "vector"
#ifndef PSE_METRO_SIMULATIE_METROSIMULATION_H
#define PSE_METRO_SIMULATIE_METROSIMULATION_H

class Tram;
class Station;

class MetroSimulation {
public:
    MetroSimulation(const std::string& filename);
private:
    std::vector<Tram*> trams;
    std::vector<Station*> stations;
};


#endif //PSE_METRO_SIMULATIE_METROSIMULATION_H
