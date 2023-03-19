#include "Tram.h"
#include <sstream>
#include "DesignByContract.h"

Tram::Tram() {
    startStation = NULL;
    _initCheck = this;
}
Tram::Tram(int lineNumber, int tramNumber, int speed, Station *startStation) : lineNumber(lineNumber),
                                                                               tramNumber(tramNumber), speed(speed),
                                                                               startStation(startStation) {
    _initCheck = this;
}

Tram::~Tram() {}

int Tram::getLineNumber() const {
    return lineNumber;
}

void Tram::setLineNumber(int lineNumber_) {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
    Tram::lineNumber = lineNumber_;
}

int Tram::getSpeed() const {
    return speed;
}

void Tram::setSpeed(int speed_) {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
    Tram::speed = speed_;
}

Station *Tram::getStartStation() const {
    return startStation;
}

int Tram::getTramNumber() const {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
    return tramNumber;
}

Station *Tram::getCurrentStation() const {
    return currentStation;
}

void Tram::setStartStation(Station *startStation_) {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
    Tram::startStation = startStation_;
    currentStation = startStation_;
}

void Tram::setTramNumber(int tramNumber_) {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
    Tram::tramNumber = tramNumber_;
}

bool Tram::drive(Track *track, std::ostream &os) {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
    if (currentStation != track->getBegin()) { return false; }

    currentStation = track->getAnEnd();
    os << *this << " reed van " << *track->getBegin() << " naar " << *track->getAnEnd() << "." << std::endl;
    return true;
}

std::ostream &operator<<(std::ostream &os, const Tram &tram) {
    return os << "Tram " << tram.tramNumber;
}

Tram::operator std::string() {
    std::ostringstream output;
    output << "Tram " << this->tramNumber << " in Station " << this->getCurrentStation()->getName();
    std::string outputString  = output.str();
    return outputString;
}

bool Tram::properlyInitialized() const {
    return _initCheck == this;
}
