#include "Tram.h"

Tram::Tram() {}
Tram::Tram(int trackNumber, int speed, Station *startStation) : trackNumber(trackNumber), speed(speed),
                                                               startStation(startStation) {
    properlyInitialized = true;
}

Tram::~Tram() {

}

int Tram::getTrackNumber() const {
    return trackNumber;
}

void Tram::setTrackNumber(int trackNumber_) {
    Tram::trackNumber = trackNumber_;
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


