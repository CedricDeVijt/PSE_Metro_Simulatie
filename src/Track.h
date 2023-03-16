#ifndef PSE_METRO_SIMULATIE_TRACK_H
#define PSE_METRO_SIMULATIE_TRACK_H

class Station;

class Track {
public:
    // Constructor
    Track(Station *begin, Station *anEnd);
    // Destructor
    virtual ~Track();

    //Getters
    Station *getBegin() const;
    Station *getAnEnd() const;
private:
    // Other
    bool properlyInitialized() const;

    Station *begin;
    Station *end;

    Track* _initCheck;
};


#endif //PSE_METRO_SIMULATIE_TRACK_H
