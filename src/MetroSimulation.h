#ifndef PSE_METRO_SIMULATIE_METROSIMULATION_H
#define PSE_METRO_SIMULATIE_METROSIMULATION_H

#include "MetroSystem.h"


/**
 * Simulation system for metro-system
 */
class MetroSimulation {
//Init
public:
    /**
     * Initializes a Metrosimulation
     *
     * @param inputFile is a .xml file that contains METRODATA
     * @param errorstream is the stream the errors get outputted to
     * @param runtime is the time the simulation needs to run
     * @ENSURE properlyInitialized(), "constructor must end in properlyInitialized state"
     */
    MetroSimulation(const std::string &inputFile, std::ostream &errorstream, unsigned int runtime, bool createPng);
    /**
     * Destructs a Metrosimulation
     *
     * @REQUIRE properlyInitialized(), "Metrosimulation was not properly initialised."
     */
    virtual ~MetroSimulation();
    bool properlyInitialized() const;

//functions
public:
    /**
     * Updates the metro-system so all the trams will move to their next location
     *
     * @REQUIRE properlyInitialized(), "Metrosimulation was not properly initialised."
     * @param os is a @b std::ostream: where the movement of the the trams gets written to
     */
    void run(std::ostream &os);

    /**
     * Outputs the current evaluation of the metroSim
     *
     * @REQUIRE properlyInitialized(), "Metrosimulation was not properly initialised."
     * @param os is the outputstream
     */
    void evaluate(std::ostream &os);

//setters
public:
    /**
     * Stops the system from running
     *
     * @REQUIRE properlyInitialized(), "Metrosimulation was not properly initialised."
     * @ENSURE stoppedSystem, "Failed to stop system"
     */
    void stopSystem();

    /**
     * Increments the clock by one
     *
     * @REQUIRE properlyInitialized(), "Metrosimulation was not properly initialised."
     * @ENSURE timeBefore+1==time, "Failed to increment time"
     */
    void updateTime();

//getters
public:
    /**
     * Returns the metro-system that is used for the simulation
     *
     * @REQUIRE properlyInitialized(), "Metrosimulation was not properly initialised."
     */
    MetroSystem *getSystem() const;

    /**
     * Returns the current time of the simulation
     *
     * @REQUIRE properlyInitialized(), "Metrosimulation was not properly initialised."
     */
    unsigned int getTime() const;
private:
    MetroSystem *system;
    unsigned int runtime;
    unsigned int time;
    MetroSimulation* _initCheck;
    bool createPng;
    bool stoppedSystem;

    virtual void emitSimulationProgressed();
};


#endif //PSE_METRO_SIMULATIE_METROSIMULATION_H
