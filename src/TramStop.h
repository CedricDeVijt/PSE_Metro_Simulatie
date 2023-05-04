#ifndef PSE_METRO_SIMULATIE_TRAMSTOP_H
#define PSE_METRO_SIMULATIE_TRAMSTOP_H

#include <string>
#include <ostream>

class Track;
class Tram;

/**
 * Object that represents a metro station that has a name, track-number and tracks.
 */
class TramStop {
//Init
public:
    /**
     * Initializes TramStop object
     *
     * @param name is the name of the station
     * @ENSURE properlyInitialized(), "constructor must end in properlyInitialized state"
     */
    TramStop(const std::string &name);

    /**
     * Destructs a TramStop object
     *
     * @REQUIRE properlyInitialized(), "TramStop was not properly initialised."
     */
    virtual ~TramStop();
    bool properlyInitialized() const;

//Functions
public:
    bool operator<(const TramStop &rhs) const;

    virtual bool acceptsTramType(Tram *tram)=0;

//Getters
public:
    /**
     * Gives the name of the station
     *
     * @return @b string: name of the station
     * @REQUIRE properlyInitialized(), "TramStop was not properly initialised."
     */
    const std::string &getName() const;

    /**
     * Returns bool that contains info about occupation
     *
     * @return @b bool: occupation of station
     * @REQUIRE properlyInitialized(), "TramStop was not properly initialised."
     */
    bool isOccupied() const;
//Setters
public:
    void setOccupied(bool occupied);
private:
    friend std::ostream &operator<<(std::ostream &os, const TramStop &station);
    std::string name;
    TramStop* _initCheck;
    bool occupied;
};

class Metrostation : public TramStop{
public:
    explicit Metrostation(const std::string &name);
    virtual ~Metrostation();

    bool acceptsTramType(Tram *tram);
};

class Halte : public TramStop{
public:
    explicit Halte(const std::string &name);

    virtual ~Halte();

    bool acceptsTramType(Tram *tram);
};

#endif //PSE_METRO_SIMULATIE_TRAMSTOP_H
