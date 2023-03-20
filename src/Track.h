#ifndef PSE_METRO_SIMULATIE_TRACK_H
#define PSE_METRO_SIMULATIE_TRACK_H

class Station;

/**
 * Object that represents a track for a metro
 */
class Track {
public:
    // Constructor
    Track(Station *begin, Station *anEnd);
    // Destructor
    virtual ~Track();

    //Getters
    /**
     * Gets the station at the beginning of the track
     * @return Station* to the station at the beginning of the track
     */
    Station *getBegin() const;

    /**
     * Gets the station at the end of the track
     * @return Station* to the station at the end of the track
     */
    Station *getAnEnd() const;

private:
    // Other
    bool properlyInitialized() const;

    Station *begin;
    Station *end;

    Track* _initCheck;
};


#endif //PSE_METRO_SIMULATIE_TRACK_H
