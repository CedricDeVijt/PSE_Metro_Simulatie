#ifndef PSE_METRO_SIMULATIE_TRACK_H
#define PSE_METRO_SIMULATIE_TRACK_H

class Station;

class Track {
public:
    // Constructor
    Track(Station *begin, Station *anEnd);

    // Destructor
    //...

    Station *getBegin() const;

    Station *getAnEnd() const;

private:
    Station *begin;
    Station *end;
};


#endif //PSE_METRO_SIMULATIE_TRACK_H
