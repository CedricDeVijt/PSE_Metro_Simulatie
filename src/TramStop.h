#ifndef PSE_METRO_SIMULATIE_TRAMSTOP_H
#define PSE_METRO_SIMULATIE_TRAMSTOP_H

#include <string>
#include <ostream>

class Track;

/**
 * Object that represents a metro station that has a name, tracknumber and tracks
 */
class TramStop {
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
    ~TramStop();

    bool properlyInitialized() const;

    /**
     * Gives the name of the station
     *
     * @return @b string: name of the station
     * @REQUIRE properlyInitialized(), "TramStop was not properly initialised."
     */
    const std::string &getName() const;

    bool operator<(const TramStop &rhs) const;

private:
    friend std::ostream &operator<<(std::ostream &os, const TramStop &station);
    std::string name;
    TramStop* _initCheck;
};

class Metrostation : public TramStop{
public:
    explicit Metrostation(const std::string &name);
};

class Halte : public TramStop{
public:
    explicit Halte(const std::string &name);
};

#endif //PSE_METRO_SIMULATIE_TRAMSTOP_H
