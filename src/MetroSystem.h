#ifndef PSE_METRO_SIMULATIE_METROSYSTEM_H
#define PSE_METRO_SIMULATIE_METROSYSTEM_H

#include "vector"
#include "Line.h"
#include "Station.h"
#include "DesignByContract.h"
#include "Logger.h"

/**
 * System that represents a real life metro system with trams, stations and tracks
 */
class MetroSystem {
public:
    /**
     * Creates a MetroSystem
     *
     * @param filename is a .xml file that contains METRODATA
     * @param errorstream is the stream the errors get outputted to
     */
    explicit MetroSystem();

    /**
     * Destructs a Metrosystem
     *
     * @REQUIRE(properlyInitialized(), "Metrosimulation is not properly initialised.");
     */
    virtual ~MetroSystem();

    bool properlyInitialized() const;

    /**
     * Updates the lines of the MetroSystem
     *
     * @REQUIRE properlyInitialized(), "Metrosimulation is not properly initialised."
     * @param os The output stream where the updates of the system get written to
     */
    void updateSystem(std::ostream &os);

    /**
     * Outputs the system to the given output stream
     *
     * @REQUIRE properlyInitialized(), "Metrosimulation is not properly initialised."
     * @param os is the outputstream where the current metroSystem gets written to
     */
    void outputSystem(std::ostream &os);

    /**
     * Creates DOT file of the current metro-system
     *
     * @REQUIRE properlyInitialized(), "Metrosimulation is not properly initialised."
     * @param os is the outputstream where the current metroSystem gets written to
     * @outputs - URL to the visualizer with the DOT file loaded in \n
     *          - DOT file format
     */
    void createDotFile(std::ostream &os);

    void addLine(const int &lineNumber);

    void addStation(Station* newStation, const int &lineNumber);

    void deployTram(Tram* newTram, const std::string &startStation, const int &lineNumber, std::ostream &errorStream);

    void addConnection(const std::string &start, const std::string &end, const int &lineNumber, std::ostream &errorStream);

    void verify(std::ostream &errorStream);
private:
    std::vector<Line*> lines;
    std::vector<Station*> stations;
    MetroSystem* _initCheck;
};


#endif //PSE_METRO_SIMULATIE_METROSYSTEM_H
