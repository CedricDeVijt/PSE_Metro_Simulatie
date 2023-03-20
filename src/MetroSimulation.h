#ifndef PSE_METRO_SIMULATIE_METROSIMULATION_H
#define PSE_METRO_SIMULATIE_METROSIMULATION_H
#include "MetroSystem.h"

class MetroSimulation  {
public:
    // Constructor
    MetroSimulation(const std::string &inputFile, std::ostream &errorstream, unsigned int runtime);
    // Destructor
    virtual ~MetroSimulation();

    /**
     * Gives the metro-system that is used for the simulation
     * @return
     */
    MetroSystem *getSystem() const;

    /**
     * Updates the metro-system so all the trams will move to their next location
     * @param os std::ostream: Output stream where the movement of the the trams gets written to
     */
    void run(std::ostream &os);

private:
    bool properlyInitialized() const;

    MetroSystem *system;
    unsigned int runtime;
    unsigned int time;

    MetroSimulation* _initCheck;
};


#endif //PSE_METRO_SIMULATIE_METROSIMULATION_H
