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
     * Adds a track tot the line object.
     *
     * @REQUIRE properlyInitialised(), "The line was not properly initialised."
     * @param newTrack is the new Track that will be added to the Line
     */
    void addTrack(Track *newTrack);

    /**
     * Adds a tram tot the line object.
     *
     * @REQUIRE properlyInitialised(), "The line was not properly initialised."
     * @param newTram is the new Tram that will be added to the Line
     */
    void addTram(Tram *newTram);
    void addStation(Station *station);
    bool verify(std::ostream &errorstream);
    Station* getNext(Station *station);
    Station* getPrev(Station *station);
    int getTrackLength(Station *curr, Station *next);
    operator std::string();
private:
    int lineNumber;
    std::vector<Station*> stations;
    std::vector<Track*> tracks;
    std::vector<Tram*> trams;
    Line* _initCheck;
};


#endif //PSE_METRO_SIMULATIE_LINE_H
