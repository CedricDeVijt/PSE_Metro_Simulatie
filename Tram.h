#ifndef PSE_METRO_SIMULATIE_TRAM_H
#define PSE_METRO_SIMULATIE_TRAM_H
#include "Station.h"
zdz
class Tram {
public:
    // Constructor
    Tram(int lineNumber, int speed, Station *startStation);
    Tram();

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

    bool properlyInitialized;
};


#endif //PSE_METRO_SIMULATIE_TRAM_H
