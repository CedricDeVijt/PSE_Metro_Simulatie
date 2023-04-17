#ifndef PSE_METRO_SIMULATIE_METROSYSTEM_H
#define PSE_METRO_SIMULATIE_METROSYSTEM_H

#include "vector"
#include "Line.h"
#include "TramStop.h"
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

    /**
     * Creates a new Line in the MetroSystem \n
     * If a line with this number already exists, ignore \n
     *
     * @REQUIRE properlyInitialized(), "Metrosimulation is not properly initialised."
     * @param lineNumber is the Number for the new Line
     */
    void addLine(const int &lineNumber);

    /**
     * Adds a new TramStop to the proper Line and to the System \n
     * If the Line is not in the MetroSystem, an error gets written out to errorStream \n
     *
     * @REQUIRE properlyInitialized(), "MetroSystem is not properly initialised."
     * @param newStation is a TramStop* pointing to the new TramStop that needs to get added to the system
     * @param lineNumber is the LineNumber where the station should get added to
     * @param errorStream is the stream the errors get sent to
     */
    void addStation(TramStop* newStation, const int &lineNumber, std::ostream &errorStream);

    /**
     * Deploys a tram to the corresponding TramStop name and on the right Line \n
     *
     * @REQUIRE properlyInitialized(), "MetroSystem is not properly initialised."
     * @param newTram is a Tram* pointing to the tram that needs to get Deployed
     * @param startStation is the name of the station it needs to get Deployed on
     * @param lineNumber is the LineNumber of the line it needs to get Deployed on
     * @param errorStream is the stream the errors get sent to
     */
    void deployTram(Tram* newTram, const std::string &startStation, const int &lineNumber, std::ostream &errorStream);

    /**
     * Adds a connection between two Stations on the corresponding LineNumber
     *
     * @REQUIRE properlyInitialized(), "MetroSystem is not properly initialised."
     * @param start is the name of the station at the begin of the connection
     * @param end is the name of the station at the end of the connection
     * @param lineNumber is the LineNumber of the line the connection needs to get added onto
     * @param errorStream is the stream the errors get sent to
     */
    void addConnection(const std::string &start, const std::string &end, const int &lineNumber, std::ostream &errorStream);

    /**
     * Verifies all the Lines on the MetroSystem, if a line is not consisten it outputs an error to errorStream \n
     *
     * @REQUIRE properlyInitialized(), "MetroSystem is not properly initialised."
     * @param errorStream is the stream the errors get sent to
     */
    void verify(std::ostream &errorStream);

    //TODO comments
    const std::vector<Line *> &getLines() const;

    const std::vector<TramStop *> &getStations() const;

private:
    std::vector<Line*> lines;
    std::vector<int> takenTramNumbers;
    std::vector<TramStop*> stations;
    MetroSystem* _initCheck;
    bool consistent;
};


#endif //PSE_METRO_SIMULATIE_METROSYSTEM_H
