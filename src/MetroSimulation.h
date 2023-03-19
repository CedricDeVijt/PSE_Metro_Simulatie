#ifndef PSE_METRO_SIMULATIE_METROSIMULATION_H
#define PSE_METRO_SIMULATIE_METROSIMULATION_H
#include "MetroSystem.h"

class MetroSimulation  {
public:
    // Constructor
    MetroSimulation(const std::string &inputFile, std::ostream &errorstream, unsigned int runtime);
    virtual ~MetroSimulation();

    MetroSystem *getSystem() const;
    void run(std::ostream &os);
private:
    bool properlyInitialized() const;

    MetroSystem *system;
    unsigned int runtime;
    unsigned int time;

    MetroSimulation* _initCheck;
};


#endif //PSE_METRO_SIMULATIE_METROSIMULATION_H
