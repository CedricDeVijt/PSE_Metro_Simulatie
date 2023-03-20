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
     * @param nextTrack is a pointer to the next Track of the station
     * @param prevTrack is a pointer to the previous Track of the station
     * @param lineNumber is the Number of The line of the Station
     * @ENSURE properlyInitialized(), "constructor must end in properlyInitialized state"
     */
    Station(const std::string &name, Track *nextTrack, Track *prevTrack, int lineNumber);

    /**
     * Destructs a Station object
     *
     * @REQUIRE properlyInitialized(), "Station was not properly initialised."
     */
    ~Station();

    bool properlyInitialized() const;

    /**
     * Converts Track into a string
     *
     * @REQUIRE properlyInitialized(), "Station was not properly initialised."
     */
    operator std::string();

    /**
     * Gives the name of the station
     *
     * @return @b string: name of the station
     * @REQUIRE properlyInitialized(), "Station was not properly initialised."
     */
    const std::string &getName() const;

    /**
     * Gives a pointer to the next track of the station
     *
     * @return @b Track*: pointer to the next track
     * @REQUIRE properlyInitialized(), "Station was not properly initialised."
     */
    Track *getNextTrack() const;

    /**
     * Gives a pointer to the previous track of the station
     *
     * @return @b Track*: pointer to the previous track
     * @REQUIRE properlyInitialized(), "Station was not properly initialised."
     */
    Track *getPrevTrack() const;

   /**
    * Gives the line number of the station
    *
     * @return @b int: the line number
     * @REQUIRE properlyInitialized(), "Station was not properly initialised."
    */
    int getLineNumber() const;

    /**
     * Sets the next Track given by a nextStation \n
     * The end of the Track is the nextStation, Begin is the Station itself
     *
     * @param nextStation is the next station given to the station
     * @REQUIRE properlyInitialized(), "Station was not properly initialised."
     */
    void setNextTrack(Station *nextStation);

    /**
     * Sets the previous Track given by a prevStation \n
     * The end of the Track is the Station itself, Begin is the Prevstation
     *
     * @param prevStation is the previous station given to the station
     * @REQUIRE properlyInitialized(), "Station was not properly initialised."
     */
    void setPrevTrack(Station *prevStation);
private:
    friend std::ostream &operator<<(std::ostream &os, const Station &station);
    std::string name;
    Track *nextTrack;
    Track *prevTrack;
    int lineNumber;
    Station* _initCheck;
};


#endif //PSE_METRO_SIMULATIE_STATION_H
