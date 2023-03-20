#include "Tram.h"
#include <sstream>
#include "DesignByContract.h"

Tram::Tram(int lineNumber, int tramNumber, int speed, Station *startStation) : lineNumber(lineNumber),
                                                                               tramNumber(tramNumber), speed(speed),
                                                                               startStation(startStation), currentStation(startStation) {
    _initCheck = this;
}

Tram::~Tram() {}

int Tram::getLineNumber() const {
    return lineNumber;
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

void Tram::drive(std::ostream &os) {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");

    Station* prev = currentStation;
    currentStation = currentStation->getNextTrack()->getAnEnd();
    os << *this << " reed van " << *prev << " naar " << *currentStation << "." << std::endl;
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
