#ifndef PSE_METRO_SIMULATIE_LINE_H
#define PSE_METRO_SIMULATIE_LINE_H

#include "vector"
#include "iostream"
#include "Track.h"
#include "Tram.h"
#include "Station.h"
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
     * @param os is the stream the print statements get send into
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
     * Adds a Station to the Line \n
     * If the station is already in the Line, it does not get added again
     *
     * @REQUIRE properlyInitialised(), "The line was not properly initialised."
     * @param station is the Station that needs to get added
     */
    void addStation(Station *station);

    /**
     * Verifies a Line
     *
     * @REQUIRE properlyInitialised(), "The line was not properly initialised."
     * @param errorStream is the stream errors get output to
     * @return @b bool: returns true if verified, els false
     */

    bool verify(std::ostream &errorStream);

    /**
     * Returns the next Station* according to the connections
     *
     * @REQUIRE properlyInitialised(), "The line was not properly initialised."
     * @param station is the Station you want information from
     * @return @b Station*: to the next Station
     */
    Station* getNext(Station *station);

    /**
     * Returns the previous Station* according to the connections
     *
     * @REQUIRE properlyInitialised(), "The line was not properly initialised."
     * @param station is the Station you want information from
     * @return @b Station*: to the previous Station
     */
    Station* getPrev(Station *station);

    /**
     * Returns the length of a track between two Stations
     *
     * @REQUIRE properlyInitialised(), "The line was not properly initialised."
     * @param start is a Station* to the start of the track
     * @param end is a Station* to the end of the track
     * @return @b int: length of the track
     */
    int getTrackLength(Station *start, Station *end);

    /**
     * Returns a Station* to a Station which has the given name
     *
     * @REQUIRE properlyInitialised(), "The line was not properly initialised."
     * @param name is the name of the demanded Station
     * @return @b Station*: to the demanded Station, if the Station does not exist on this line return NULL
     */
    Station* getStation(const std::string &name);

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
     * Deploys a tram to the given Station with the StationName
     *
     * @REQUIRE properlyInitialised(), "The line was not properly initialised."
     * @param newTram is the Tram that gets deployed
     * @param stationName is the name of a Station Corresponding to where the tram gets deployed to
     * @param errorStream is the stream errors get output to
     */
    void deployTram(Tram* newTram, const std::string &stationName, std::ostream &errorStream);

    /**
     * Stringifies a Line
     *
     * @REQUIRE properlyInitialised(), "The line was not properly initialised."
     * @return stringified version of a Line
     */
    operator std::string();
private:
    int lineNumber;
    std::vector<Station*> stations;
    std::vector<Track*> tracks;
    std::vector<Tram*> trams;
    Line* _initCheck;
    bool verified;
};


#endif //PSE_METRO_SIMULATIE_LINE_H
