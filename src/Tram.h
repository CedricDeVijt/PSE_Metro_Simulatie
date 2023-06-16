#ifndef PSE_METRO_SIMULATIE_TRAM_H
#define PSE_METRO_SIMULATIE_TRAM_H
#include <ostream>
#include "TramStop.h"
#include "Track.h"

/**
 * Object that represents a tram
 */
class Tram {
//Init
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

//Functions
public:
    /**
     * Converts Tram into a string
     *
     * @REQUIRE properlyInitialized(), "TramStop was not properly initialised."
     */
    operator std::string();

    /**
     * Moves the tram to the next station
     *
     * @param os std::ostream: where the output of moving the train is written to
     * @REQUIRE properlyInitialized(), "TramStop was not properly initialised."
     */
    virtual void drive(TramStop* destination, bool blocked, std::ostream &os);

//Getters
public:
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
     * Gives the type of the tram.
     *
     * @return The name of the type of tram.
     * @REQUIRE properlyInitialized(), "TramStop was not properly initialised."
     */
    const std::string &getVehicleType() const;

//Setters
public:
    /**
     * Sets the speed of the tram
     *
     * @REQUIRE properlyInitialized(), "TramStop was not properly initialised."
     * @ENSURE getSpeed()==speed_, "Failed to set speed."
     * @param speed int: speed of the tram
     */
    void setSpeed(int speed);

    /**
     * Sets the station where the train starts at the start of the system
     *
     * @REQUIRE properlyInitialized(), "TramStop was not properly initialised."
     * @ENSURE getStartStation()==startStation_, "SetStartstation failed."
     * @param startStation TramStop *: station where the tram starts form
     */
    void setStartStation(TramStop *startStation);

private:
    friend std::ostream &operator<<(std::ostream &os, const Tram &tram);
    int tramNumber;
    int speed;
    Tram* _initCheck;
    TramStop *startStation;
    TramStop *currentStation;
protected:
    std::string vehicleType;
};

class PCC : public Tram {
public:
    /**
     * Creates a PCC Tram object
     *
     * @param tramNumber is the Number of the Tram
     * @param speed is the Speed of the tram
     * @param startStation is the startstation of the tram
     *
     * @ENSURE properlyInitialized(), "constructor must end in properlyInitialized state"
     */
    PCC(int tramNumber, TramStop *startStation, int repairTime, int defectAmount, int repairCost);

    void drive(TramStop *destination, bool blocked, std::ostream &os);

    /**
     * Gives the cost of the repairs of the tram.
     *
     * @return The cost in euro's of the repairs.
     * @REQUIRE properlyInitialized(), "TramStop was not properly initialised."
     */
    int getTotalCost() const;

    /**
    * Returns true if the Tram is defect
    *
    * @REQUIRE properlyInitialized(), "Tram was not properly initialised."
    */
    bool isDefect() const;
private:
    /**
     * Handles the effect property of the tram
     *
     * @param os is the outputstream, in case of Defect/Reparation
     */
    void handleDefect(std::ostream &os);
private:
    int repairCost;
    int repairTime;
    int defectAmount;
    int totalCost;

    bool defect;
    int repairSteps;
    int steps;
};

class Albatros : public Tram {
public:
    /**
     * Creates a Albatros Tram object
     *
     * @param tramNumber is the Number of the Tram
     * @param speed is the Speed of the tram
     * @param startStation is the startstation of the tram
     *
     * @ENSURE properlyInitialized(), "constructor must end in properlyInitialized state"
     */
    Albatros(int tramNumber, Metrostation *startStation);
};

class Stadslijner : public Tram {
public:
    /**
     * Creates a Stadslijner Tram object
     *
     * @param tramNumber is the Number of the Tram
     * @param speed is the Speed of the tram
     * @param startStation is the startstation of the tram
     *
     * @ENSURE properlyInitialized(), "constructor must end in properlyInitialized state"
     */
    Stadslijner(int tramNumber, Metrostation *startStation);
};


#endif //PSE_METRO_SIMULATIE_TRAM_H
