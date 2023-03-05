#ifndef PSE_METRO_SIMULATIE_TRACK_H
#define PSE_METRO_SIMULATIE_TRACK_H

class Station;

class Track {
public:
    Track(Station *begin, Station *anEnd);

    Station *getBegin() const;

    Station *getAnEnd() const;

private:
    Station *begin;
    Station *end;
};


#endif //PSE_METRO_SIMULATIE_TRACK_H
