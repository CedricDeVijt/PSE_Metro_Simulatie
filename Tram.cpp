#include "Tram.h"

Tram::Tram(int lineNumber, int speed, Station *startStation) : lineNumber(lineNumber), speed(speed),
                                                               startStation(startStation) {
    properlyInitialized = true;
}

Tram::~Tram() {

}

int Tram::getLineNumber() const {
    return lineNumber;
}

void Tram::setLineNumber(int lineNumber_) {
    Tram::lineNumber = lineNumber_;
}

int Tram::getSpeed() const {
    return speed;
}

void Tram::setSpeed(int speed_) {
    Tram::speed = speed_;
}

Station *Tram::getStartStation() const {
    return startStation;
}

void Tram::setStartStation(Station *startStation_) {
    Tram::startStation = startStation_;
}
