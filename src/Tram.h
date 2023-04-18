#ifndef PSE_METRO_SIMULATIE_TRAM_H
#define PSE_METRO_SIMULATIE_TRAM_H
#include <ostream>
#include "TramStop.h"
#include "Track.h"

/**
 * Object that represents a tram
 */
class Tram {
public:
    /**
     * Creates a Tram object
     *
     * @param tramNumber is the Number of the Tram
     * @param speed is the Speed of the tram
     * @param startStation is the startstation of the tram
     *
     * @ENSURE properlyInitialized(), "constructor must end in properlyInitialized state"
     */
    Tram(int tramNumber, int speed, TramStop *startStation);

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
     * @REQUIRE properlyInitialized(), "TramStop was not properly initialised."
     */
    operator std::string();

    /**
     * Gives the speed of which the tram is capable
     *
     * @return int: the speed of which the tram is capable
     * @REQUIRE properlyInitialized(), "TramStop was not properly initialised."
     */
    int getSpeed() const;

    /**
     * Gives the station where the track starts
     *
     * @return TramStop* to the station where the track starts
     * @REQUIRE properlyInitialized(), "TramStop was not properly initialised."
     */
    TramStop *getStartStation() const;

    /**
     * Gives the number of the tram
     *
     * @return int: the tram number of the tram
     * @REQUIRE properlyInitialized(), "TramStop was not properly initialised."
     */
    int getTramNumber() const;

    /**
     * Gives the station where the tram currently is
     *
     * @return TramStop* to the station where the tram currently is
     * @REQUIRE properlyInitialized(), "TramStop was not properly initialised."
     */
    TramStop *getCurrentStation() const;

    /**
     * Gives the cost of the repairs of the tram.
     *
     * @return The cost in euro's of the repairs.
     * @REQUIRE properlyInitialized(), "TramStop was not properly initialised."
     */
    int getRepairCost() const;

    /**
     * Sets the speed of the tram
     *
     * @param speed int: speed of the tram
     * @REQUIRE properlyInitialized(), "TramStop was not properly initialised."
     */
    void setSpeed(int speed);

    /**
     * Sets the station where the train starts at the start of the system
     *
     * @param startStation TramStop *: station where the tram starts form
     * @REQUIRE properlyInitialized(), "TramStop was not properly initialised."
     */
    void setStartStation(TramStop *startStation);

    /**
     * Moves the tram to the next station
     *
     * @param os std::ostream: where the output of moving the train is written to
     * @REQUIRE properlyInitialized(), "TramStop was not properly initialised."
     */
    void drive(TramStop* destination, int length, std::ostream &os);

protected:
    // Constructor
    Tram();

    friend std::ostream &operator<<(std::ostream &os, const Tram &tram);
    int tramNumber;
    int speed;
    int repairCost;
    TramStop *startStation;
    TramStop *currentStation;
    Tram* _initCheck;
};

class PCC : public Tram {
public:
    // Constructor
    PCC(int tramNumber, TramStop *startStation);
};

class Albatros : public Tram {
public:
    // Constructor
    Albatros(int tramNumber, Metrostation *startStation);
};

class Stadslijner : public Tram {
public:
    // Constructor
    Stadslijner(int tramNumber, Metrostation *startStation);
};


#endif //PSE_METRO_SIMULATIE_TRAM_H
