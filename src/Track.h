#ifndef PSE_METRO_SIMULATIE_TRACK_H
#define PSE_METRO_SIMULATIE_TRACK_H

class Station;

/**
 * Object that represents a track for a metro
 */
class Track {
public:
    /**
     * Initializes Track Object
     *
     * @param begin is the beginstation of the Track
     * @param anEnd is the endStation of the Track
     */
    Track(Station *begin, Station *anEnd);

    /**
     * Destructs a Track object
     *
     * @REQUIRE properlyInitialized(), "Track was not properly initialised."
     */
    virtual ~Track();

    bool properlyInitialized() const;

    /**
     * Gets the station at the beginning of the track
     * @return Station* to the station at the beginning of the track
     * @REQUIRE properlyInitialized(), "Track was not properly initialised."
     */
    Station *getBegin() const;

    /**
     * Gets the station at the end of the track
     * @return Station* to the station at the end of the track
     * @REQUIRE properlyInitialized(), "Track was not properly initialised."
     */
    Station *getAnEnd() const;
private:
    Station *begin;
    Station *end;
    Track* _initCheck;
};

#endif //PSE_METRO_SIMULATIE_TRACK_H
