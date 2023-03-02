#ifndef PSE_METRO_SIMULATIE_TRAM_H
#define PSE_METRO_SIMULATIE_TRAM_H

#include "Station.h"

class Tram {
public:
    // Constructor
    Tram(int lineNumber, int speed, Station *startStation);
    // Destructor
    virtual ~Tram();

    // Getters
    int getLineNumber() const;
    int getSpeed() const;
    Station *getStartStation() const;

    // Setters
    void setLineNumber(int lineNumber);
    void setSpeed(int speed);
    void setStartStation(Station *startStation);

private:
    int lineNumber;
    int speed;
    Station *startStation;
};


#endif //PSE_METRO_SIMULATIE_TRAM_H
