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
//Init
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

//Functions
public:
    /**
     * Updates the lines of the MetroSystem
     *
     * @REQUIRE properlyInitialized(), "Metrosimulation is not properly initialised."
     * @param os The output stream where the updates of the system get written to
     */
    void updateSystem();

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
     */
    void addStation(TramStop* newStation, const int &lineNumber);

    /**
     * Deploys a tram to the corresponding TramStop name and on the right Line \n
     *
     * @REQUIRE properlyInitialized(), "MetroSystem is not properly initialised."
     * @param newTram is a Tram* pointing to the tram that needs to get Deployed
     * @param startStation is the name of the station it needs to get Deployed on
     * @param lineNumber is the LineNumber of the line it needs to get Deployed on
     */
    void deployTram(Tram* newTram, const std::string &startStation, const int &lineNumber);

    /**
     * Adds a connection between two Stations on the corresponding LineNumber
     *
     * @REQUIRE properlyInitialized(), "MetroSystem is not properly initialised."
     * @param start is the name of the station at the begin of the connection
     * @param end is the name of the station at the end of the connection
     * @param lineNumber is the LineNumber of the line the connection needs to get added onto
     */
    void addConnection(const std::string &start, const std::string &end, const int &lineNumber);

    /**
     * Verifies all the Lines on the MetroSystem, if a line is not consisten it outputs an error to errorStream \n
     *
     * @REQUIRE properlyInitialized(), "MetroSystem is not properly initialised."
     */
    void verify();

    /**
     * Returns the route between two stations
     *
     * @REQUIRE properlyInitialized(), "MetroSystem is not properly initialised."
     * @param beginStopName
     * @param endStopName
     */
    std::pair<std::vector<TramStop *>, std::vector<Line *> > getRoute(const std::string &beginStopName, const std::string &endStopName);

//getters
public:
    /**
     * Returns the lines of the MetroSystem
     *
     * @REQUIRE properlyInitialized(), "MetroSystem is not properly initialised."
     */
    const std::vector<Line *> &getLines() const;

    /**
     * Returns the stations of the MetroSystem
     *
     * @REQUIRE properlyInitialized(), "MetroSystem is not properly initialised."
     */
    const std::vector<TramStop *> &getStations() const;

private:
    std::vector<Line*> lines;
    std::vector<int> takenTramNumbers;
    std::vector<TramStop*> stations;
    MetroSystem* _initCheck;
    bool consistent;
};


#endif //PSE_METRO_SIMULATIE_METROSYSTEM_H
