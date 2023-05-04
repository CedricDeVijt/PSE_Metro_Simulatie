#ifndef PSE_METRO_SIMULATIE_METROSIMSTATISTICS_H
#define PSE_METRO_SIMULATIE_METROSIMSTATISTICS_H

#include "MetroSystem.h"
#include "MetroSimulation.h"
#include "DesignByContract.h"

/**
 * Object that gets the stats from a MetroSim at a certain state
 */
class MetroSimStatistics {
//init
public:
    /**
     * Initializes the statistics class
     *
     * @ENSURE properlyInitialized(), "constructor must end in properlyInitialized state"
     * @param sim is the given MetroSimulation
     */
    explicit MetroSimStatistics(MetroSimulation *sim);
    bool properlyInitialized() const;

//functions
public:
    /**
     * Prints the statistics to the given outputStream
     *
     * @REQUIRE properlyInitialized(), "MetroSimStatistics was not properly initialised."
     * @param os is the given outputStream
     */
    void printStats(std::ostream &os) const;

//getters
public:
    /**
     * Returns the time of the current stat-check
     *
     * @REQUIRE properlyInitialized(), "MetroSimStatistics was not properly initialised."
     */
    int getTime() const;

    /**
     * Returns the total cost of the current stat-check
     *
     * @REQUIRE properlyInitialized(), "MetroSimStatistics was not properly initialised."
     */
    int getTotalCost() const;

    /**
     * Returns the amount of defect trams of the current stat-check
     *
     * @REQUIRE properlyInitialized(), "MetroSimStatistics was not properly initialised."
     */
    int getDefectTrams() const;

    /**
     * Returns the amount of working trams of the current stat-check
     *
     * @REQUIRE properlyInitialized(), "MetroSimStatistics was not properly initialised."
     */
    int getWorkingTrams() const;
private:
    int time;
    int totalCost;
    int defectTrams;
    int workingTrams;
    MetroSimStatistics* _initCheck;
};


#endif //PSE_METRO_SIMULATIE_METROSIMSTATISTICS_H
