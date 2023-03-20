#include "Tram.h"
#include <sstream>
#include "DesignByContract.h"

Tram::Tram(int lineNumber, int tramNumber, int speed, Station *startStation) : lineNumber(lineNumber),
                                                                               tramNumber(tramNumber), speed(speed),
                                                                               startStation(startStation), currentStation(startStation) {
    _initCheck = this;
    ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
}

Tram::~Tram() {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
}

int Tram::getLineNumber() const {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
    return lineNumber;
}

int Tram::getSpeed() const {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
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

void Tram::drive(std::ostream &os) {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");

    Station* prev = currentStation;
    currentStation = currentStation->getNextTrack()->getAnEnd();
    os << *this << " reed van " << *prev << " naar " << *currentStation << "." << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Tram &tram) {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
    return os << "Tram " << tram.tramNumber;
}

Tram::operator std::string() {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
    std::ostringstream output;
    output << "Tram " << this->tramNumber << " in Station " << this->getCurrentStation()->getName();
    std::string outputString  = output.str();
    return outputString;
}

bool Tram::properlyInitialized() const {
    return _initCheck == this;
}
