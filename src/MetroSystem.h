#ifndef PSE_METRO_SIMULATIE_METROSYSTEM_H
#define PSE_METRO_SIMULATIE_METROSYSTEM_H

#include "vector"
#include "Line.h"
#include "Station.h"
#include "DesignByContract.h"
#include "MetroXMLParser.h"
#include "Logger.h"

/**
 * System that represents a real life metro system with trams, stations and tracks
 */
class MetroSystem {
public:
    // Constructor
    explicit MetroSystem(const std::string& filename, std::ostream &errorstream);

    // Other
    /**
     * Updates the lines of the metro-system
     * @REQUIRE(properlyInitialized(), "Metrosimulation is not properly initialised.");
     * @param os The output stream where the updates of the system get written to
     */
    void updateSystem(std::ostream &os);

    /**
     * Outputs the system to the given output stream
     * @REQUIRE(properlyInitialized(), "Metrosimulation is not properly initialised.");
     * @param os The outputstream where the current metro-system gets written to
     */
    void outputSystem(std::ostream &os);

    /**
     * Creates dot file of the current metro-system
     * @REQUIRE(properlyInitialized(), "Metrosimulation is not properly initialised.");
     * @param os
     */
    void createDotFile(std::ostream &os);

    bool properlyInitialized() const;

private:
    std::vector<Line*> lines;
    std::vector<Station*> stations;
    std::vector<Tram*> trams;
    MetroSystem* _initCheck;
//    std::ostream &errorstream;
};


#endif //PSE_METRO_SIMULATIE_METROSYSTEM_H
