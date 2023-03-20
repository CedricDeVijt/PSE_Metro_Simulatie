#ifndef PSE_METRO_SIMULATIE_TRAM_H
#define PSE_METRO_SIMULATIE_TRAM_H
#include <ostream>
#include "Station.h"
#include "Track.h"

/**
 * Object that represents a tram
 */
class Tram {
public:
    /**
     * Creates a Tram object
     *
     * @param lineNumber is the LineNumber of the Tram
     * @param tramNumber is the Number of the Tram
     * @param speed is the Speed of the tram
     * @param startStation is the startstation of the tram
     *
     * @ENSURE properlyInitialized(), "constructor must end in properlyInitialized state"
     */
    Tram(int lineNumber, int tramNumber, int speed, Station *startStation);

    /**
     * Destructs a tram object
     *
     * @REQUIRE properlyInitialized(), "Tram was not properly initialised."
     */
    virtual ~Tram();

    bool properlyInitialized() const;

    /**
     * Converts Tram into a string
     *
     * @REQUIRE properlyInitialized(), "Station was not properly initialised."
     */
    operator std::string();

    /**
     * Gives the line number of the track on which the tram is driving
     *
     * @return @b int: line number of the line on which the tram is driving
     * @REQUIRE properlyInitialized(), "Station was not properly initialised."
     */
    int getLineNumber() const;

    /**
     * Gives the speed of which the tram is capable
     *
     * @return int: the speed of which the tram is capable
     * @REQUIRE properlyInitialized(), "Station was not properly initialised."
     */
    int getSpeed() const;

    /**
     * Gives the station where the track starts
     *
     * @return Station* to the station where the track starts
     * @REQUIRE properlyInitialized(), "Station was not properly initialised."
     */
    Station *getStartStation() const;

    /**
     * Gives the number of the tram
     *
     * @return int: the tram number of the tram
     * @REQUIRE properlyInitialized(), "Station was not properly initialised."
     */
    int getTramNumber() const;

    /**
     * Gives the station where the tram currently is
     *
     * @return Station* to the station where the tram currently is
     * @REQUIRE properlyInitialized(), "Station was not properly initialised."
     */
    Station *getCurrentStation() const;

    /**
     * Sets the speed of the tram
     *
     * @param speed int: speed of the tram
     * @REQUIRE properlyInitialized(), "Station was not properly initialised."
     */
    void setSpeed(int speed);

    /**
     * Sets the station where the train starts at the start of the system
     *
     * @param startStation Station *: station where the tram starts form
     * @REQUIRE properlyInitialized(), "Station was not properly initialised."
     */
    void setStartStation(Station *startStation);

    /**
     * Moves the tram to the next station
     *
     * @param os std::ostream: where the output of moving the train is written to
     * @REQUIRE properlyInitialized(), "Station was not properly initialised."
     */
    void drive(std::ostream &os);
private:
    friend std::ostream &operator<<(std::ostream &os, const Tram &tram);
    int lineNumber;
    int tramNumber;
    int speed;
    Station *startStation;
    Station *currentStation;
    Tram* _initCheck;
};


#endif //PSE_METRO_SIMULATIE_TRAM_H
