#ifndef PSE_METRO_SIMULATIE_STATION_H
#define PSE_METRO_SIMULATIE_STATION_H

#include <string>
#include <ostream>

class Track;

/**
 * Object that represents a metro station that has a name, tracknumber and tracks
 */
class Station {
public:
    /**
     * Initializes Station object
     *
     * @param name is the name of the station
     * @ENSURE properlyInitialized(), "constructor must end in properlyInitialized state"
     */
    Station(const std::string &name);

    /**
     * Destructs a Station object
     *
     * @REQUIRE properlyInitialized(), "Station was not properly initialised."
     */
    ~Station();

    bool properlyInitialized() const;

    /**
     * Gives the name of the station
     *
     * @return @b string: name of the station
     * @REQUIRE properlyInitialized(), "Station was not properly initialised."
     */
    const std::string &getName() const;

    bool operator<(const Station &rhs) const;

private:
    friend std::ostream &operator<<(std::ostream &os, const Station &station);
    std::string name;
    Station* _initCheck;
};


#endif //PSE_METRO_SIMULATIE_STATION_H
