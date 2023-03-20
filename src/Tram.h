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
    // Constructor
    Tram(int lineNumber, int tramNumber, int speed, Station *startStation);

    // Destructor
    virtual ~Tram();

    // Operators
    /**
     * Converts Tram into a string
     * @REQUIRE(properlyInitialized(), "Station was not properly initialised.");
     */
    operator std::string();

    // Getters
    /**
     * Gives the line number of the track on which the tram is driving
     * @return int: line number of the track on which the tram is driving
     */
    int getLineNumber() const;

    /**
     * Gives the speed of which the tram is capable
     * @return int: the speed of which the tram is capable
     */
    int getSpeed() const;

    /**
     * Gives the station where the track starts
     * @return Station* to the station where the track starts
     */
    Station *getStartStation() const;

    /**
     * Gives the tram number of the tram
     * @return int: the tram number of the tram
     */
    int getTramNumber() const;

    /**
     * Gives the station where the tram currently is
     * @return Station* to the station where the tram currently is
     */
    Station *getCurrentStation() const;

    /**
     * Sets the speed of the tram
     * @param speed int: speed of the tram
     */
    void setSpeed(int speed);

    /**
     * Sets the station where the train starts at the start of the system
     * @param startStation Station *: station where the tram starts form
     */
    void setStartStation(Station *startStation);

    /**
     * Sets the tram number of the tram
     * @param tramNumber int: the tram number given to the tram
     */
    void setTramNumber(int tramNumber);

    /**
     * Moves the tram to the next station
     * @param os std::ostream: where the output of moving the train is written to
     */
    void drive(std::ostream &os);

private:
    int lineNumber;
    int tramNumber;
    int speed;
    Station *startStation;
    Station *currentStation;

    // OS
    friend std::ostream &operator<<(std::ostream &os, const Tram &tram);

    Tram* _initCheck;

    bool properlyInitialized() const;
};


#endif //PSE_METRO_SIMULATIE_TRAM_H
