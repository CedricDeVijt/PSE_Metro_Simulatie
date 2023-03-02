#ifndef PSE_METRO_SIMULATIE_TRAM_H
#define PSE_METRO_SIMULATIE_TRAM_H
#include "Station.h"

class Tram {
public:
    // Constructor
    Tram(int trackNumber, int speed, Station *startStation);
    Tram();

    // Destructor
    virtual ~Tram();

    // Getters
    int getTrackNumber() const;
    int getSpeed() const;
    Station *getStartStation() const;

    // Setters
    void setTrackNumber(int lineNumber);
    void setSpeed(int speed);
    void setStartStation(Station *startStation);

private:
    int trackNumber;
    int speed;
    Station *startStation;

    bool properlyInitialized;
};


#endif //PSE_METRO_SIMULATIE_TRAM_H
