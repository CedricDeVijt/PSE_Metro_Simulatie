#ifndef PSE_METRO_SIMULATIE_LINE_H
#define PSE_METRO_SIMULATIE_LINE_H
#include "vector"
#include "iostream"

class Track;
class Tram;

/**
 * Line object that contains Tracks and Trams
 */
class Line {
public:
    /**
     * Creates a Line Object
     *
     * \n @ENSURE properlyInitialised(), "constructor must end in properlyInitialized state"
     * \n @param lineNumber is the lineNumber of the Line
     */
    explicit Line(int lineNumber);
    /**
     * Destructs a Line Object
     *
     * \n Destructs all the Trams and Tracks
     * \n @REQUIRE properlyInitialised(), "The line was not properly initialised."
     */
    virtual ~Line();

    bool properlyInitialised() const;

    /**
     * Updates/Moves the trams of the line object.
     * \n @REQUIRE properlyInitialised(), "The line was not properly initialised."
     * \n @param os is the stream the print statements get send into
     */
    void update(std::ostream &os);

    /**
     * Returns the vector of tracks.
     * \n @REQUIRE properlyInitialised(), "The line was not properly initialised."
     */
    const std::vector<Track *> &getTracks() const;

    /**
     * Returns the vector of trams.
     * \n @REQUIRE properlyInitialised(), "The line was not properly initialised."
     */
    const std::vector<Tram *> &getTrams() const;

    /**
     * Returns the LineNumber.
     * \n @REQUIRE properlyInitialised(), "The line was not properly initialised."
     */
    int getLineNumber() const;

    /**
     * Adds a track tot the line object.
     * \n @REQUIRE properlyInitialised(), "The line was not properly initialised."
     * \n @param newTrack is the new Track that will be added to the Line
     */
    void addTrack(Track* newTrack);

    /**
     * Adds a tram tot the line object.
     * \n @REQUIRE properlyInitialised(), "The line was not properly initialised."
     * \n @param newTram is the new Tram that will be added to the Line
     */
    void addTram(Tram* newTram);
private:
    int lineNumber;
    std::vector<Track*> tracks;
    std::vector<Tram*> trams;
    Line* _initCheck;
};


#endif //PSE_METRO_SIMULATIE_LINE_H
