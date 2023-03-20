#ifndef PSE_METRO_SIMULATIE_METROSIMULATION_H
#define PSE_METRO_SIMULATIE_METROSIMULATION_H
#include "MetroSystem.h"

/**
 * Simulation system for metro-system
 */
class MetroSimulation  {
public:
    /**
     * Initializes a Metrosimulation
     *
     * @param inputFile is a .xml file that contains METRODATA
     * @param errorstream is the stream the errors get outputted to
     * @param runtime is the time the simulation needs to run
     * @ENSURE properlyInitialized(), "constructor must end in properlyInitialized state"
     */
    MetroSimulation(const std::string &inputFile, std::ostream &errorstream, unsigned int runtime);
    /**
     * Destructs a Metrosimulation
     *
     * @REQUIRE properlyInitialized(), "Metrosimulation was not properly initialised."
     */
    virtual ~MetroSimulation();

    bool properlyInitialized() const;

    /**
     * Gives the metro-system that is used for the simulation
     *
     * @return a MetroSystem object
     * @REQUIRE properlyInitialized(), "Metrosimulation was not properly initialised."
     */
    MetroSystem *getSystem() const;

    /**
     * Updates the metro-system so all the trams will move to their next location
     *
     * @param os is a @b std::ostream: where the movement of the the trams gets written to
     */
    void run(std::ostream &os);

private:
    MetroSystem *system;
    unsigned int runtime;
    unsigned int time;
    MetroSimulation* _initCheck;
};


#endif //PSE_METRO_SIMULATIE_METROSIMULATION_H
