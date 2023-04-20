#ifndef PSE_METRO_SIMULATIE_TRACK_H
#define PSE_METRO_SIMULATIE_TRACK_H

class TramStop;

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
    Track(TramStop *begin, TramStop *anEnd);

    /**
     * Destructs a Track object
     *
     * @REQUIRE properlyInitialized(), "Track was not properly initialised."
     */
    virtual ~Track();

    bool properlyInitialized() const;

    /**
     * Gets the station at the beginning of the track
     * @return TramStop* to the station at the beginning of the track
     * @REQUIRE properlyInitialized(), "Track was not properly initialised."
     */
    TramStop *getBegin() const;

    /**
     * Gets the station at the end of the track
     * @return TramStop* to the station at the end of the track
     * @REQUIRE properlyInitialized(), "Track was not properly initialised."
     */
    TramStop *getAnEnd() const;
private:
    TramStop *begin;
    TramStop *end;
    Track* _initCheck;
};

#endif //PSE_METRO_SIMULATIE_TRACK_H
