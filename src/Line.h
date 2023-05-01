#ifndef PSE_METRO_SIMULATIE_LINE_H
#define PSE_METRO_SIMULATIE_LINE_H

#include "vector"
#include "iostream"
#include "Track.h"
#include "Tram.h"
#include "TramStop.h"
#include "Logger.h"
#include "algorithm"
#include "sstream"

/**
 * Line object that contains Tracks and Trams
 */
class Line {
public:
    /**
     * Creates a Line Object
     *
     * @ENSURE properlyInitialised(), "constructor must end in properlyInitialized state"
     * @param lineNumber is the lineNumber of the Line
     */
    explicit Line(int lineNumber);
    /**
     * Destructs a Line Object
     *
     * Destructs all the Trams and Tracks
     * @REQUIRE properlyInitialised(), "The line was not properly initialised."
     */
    virtual ~Line();

    bool properlyInitialised() const;

    /**
     * Updates/Moves the trams of the line object.
     *
     * @REQUIRE properlyInitialised(), "The line was not properly initialised."
     * @param os is the stream the printStats statements get send into
     */
    void update(std::ostream &os);

    /**
     * Returns the vector of tracks.
     *
     * @REQUIRE properlyInitialised(), "The line was not properly initialised."
     */
    const std::vector<Track *> &getTracks() const;

    /**
     * Returns the vector of trams.
     *
     * @REQUIRE properlyInitialised(), "The line was not properly initialised."
     */
    const std::vector<Tram *> &getTrams() const;

    /**
     * Returns the LineNumber.
     *
     * @REQUIRE properlyInitialised(), "The line was not properly initialised."
     */
    int getLineNumber() const;

    /**
     * Adds a TramStop to the Line \n
     * If the station is already in the Line, it does not get added again
     *
     * @REQUIRE properlyInitialised(), "The line was not properly initialised."
     * @param station is the TramStop that needs to get added
     */
    void addStation(TramStop *station);

    /**
     * Verifies a Line
     *
     * @REQUIRE properlyInitialised(), "The line was not properly initialised."
     * @param errorStream is the stream errors get output to
     * @return @b bool: returns true if verified, els false
     */

    bool verify(std::ostream &errorStream);

    /**
     * Returns the next TramStop* according to the connections
     *
     * @REQUIRE properlyInitialised(), "The line was not properly initialised."
     * @param station is the TramStop you want information from
     * @return @b TramStop*: to the next TramStop
     */
    TramStop* getNext(TramStop *station);

    /**
     * Returns the previous TramStop* according to the connections
     *
     * @REQUIRE properlyInitialised(), "The line was not properly initialised."
     * @param station is the TramStop you want information from
     * @return @b TramStop*: to the previous TramStop
     */
    TramStop* getPrev(TramStop *station);

    /**
     * Returns a TramStop* to a TramStop which has the given name
     *
     * @REQUIRE properlyInitialised(), "The line was not properly initialised."
     * @param name is the name of the demanded TramStop
     * @return @b TramStop*: to the demanded TramStop, if the TramStop does not exist on this line return NULL
     */
    TramStop* getStation(const std::string &name);

    /**
     * Returns all stations of a line
     *
     * @REQUIRE properlyInitialised(), "The line was not properly initialised."
     * @param name is the name of the demanded TramStop
     * @return @b TramStop*: to the demanded TramStop, if the TramStop does not exist on this line return NULL
     */
    const std::vector<TramStop *> &getStations() const;

    /**
     * Creates a connection between two Stations
     *
     * @REQUIRE properlyInitialised(), "The line was not properly initialised."
     * @param start is the name of the startStation
     * @param end is the name of the endStation
     * @param errorStream is the stream errors get output to
     */
    void connect(const std::string &start, const std::string &end, std::ostream &errorStream);

    /**
     * Deploys a tram to the given TramStop with the StationName
     *
     * @REQUIRE properlyInitialised(), "The line was not properly initialised."
     * @param newTram is the Tram that gets deployed
     * @param stationName is the name of a TramStop Corresponding to where the tram gets deployed to
     * @param errorStream is the stream errors get output to
     */
    void deployTram(Tram* newTram, const std::string &stationName, std::ostream &errorStream);
private:
    int lineNumber;
    std::vector<TramStop*> stations;
    std::vector<Track*> tracks;
    std::vector<Tram*> trams;
    Line* _initCheck;
    bool verified;
};


#endif //PSE_METRO_SIMULATIE_LINE_H
