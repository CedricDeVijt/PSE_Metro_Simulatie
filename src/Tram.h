#ifndef PSE_METRO_SIMULATIE_TRAM_H
#define PSE_METRO_SIMULATIE_TRAM_H
#include <ostream>
#include "Station.h"
#include "Track.h"

class Tram {
public:
    // Constructor
    Tram(int lineNumber, int tramNumber, int speed, Station *startStation);

    Tram();

    // Destructor
    virtual ~Tram();

    // Operators
    operator std::string();

    // Getters
    int getLineNumber() const;
    int getSpeed() const;
    Station *getStartStation() const;
    int getTramNumber() const;

    Station *getCurrentStation() const;

    // Setters
    void setLineNumber(int lineNumber);
    void setSpeed(int speed);
    void setStartStation(Station *startStation);

    void setTramNumber(int tramNumber);

    bool drive(Track *track, std::ostream &os);
private:
    int lineNumber;
    int tramNumber;
    int speed;
    Station *startStation;

private:
    Station *currentStation;

    // OS
    friend std::ostream &operator<<(std::ostream &os, const Tram &tram);

    Tram* _initCheck;

    bool properlyInitialized() const;
};


#endif //PSE_METRO_SIMULATIE_TRAM_H
