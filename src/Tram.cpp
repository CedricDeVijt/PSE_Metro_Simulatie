#include "Tram.h"
#include "Track.h"

Tram::Tram() {
    startStation = NULL;
}
Tram::Tram(int lineNumber, int tramNumber, int speed, Station *startStation) : lineNumber(lineNumber),
                                                                               tramNumber(tramNumber), speed(speed),
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
    currentStation = startStation_;
}

void Tram::setTramNumber(int tramNumber_) {
    Tram::tramNumber = tramNumber_;
}

bool Tram::drive(Track *track, std::ostream &os) {
    if (currentStation != track->getBegin()) { return false; }

    currentStation = track->getAnEnd();
    os << *this << " reed van " << *track->getBegin() << " naar " << *track->getAnEnd() << "." << std::endl;
    return true;
}

std::ostream &operator<<(std::ostream &os, const Tram &tram) {
    return os << "Tram " << tram.tramNumber;
}




