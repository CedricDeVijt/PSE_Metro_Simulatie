#include "Tram.h"
#include <sstream>
#include "DesignByContract.h"

Tram::Tram() : tramNumber(), speed(), startStation(), currentStation(), _initCheck() {}

Tram::Tram(int tramNumber, int speed, TramStop *startStation) : tramNumber(tramNumber), speed(speed),
                                                                startStation(startStation), currentStation(startStation) {
    _initCheck = this;
    ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
}

Tram::~Tram() {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
}

int Tram::getSpeed() const {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
    return speed;
}

void Tram::setSpeed(int speed_) {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
    Tram::speed = speed_;
}

TramStop *Tram::getStartStation() const {
    return startStation;
}

int Tram::getTramNumber() const {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
    return tramNumber;
}

TramStop *Tram::getCurrentStation() const {
    return currentStation;
}

void Tram::setStartStation(TramStop *startStation_) {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
    Tram::startStation = startStation_;
    currentStation = startStation_;
}

std::ostream &operator<<(std::ostream &os, const Tram &tram) {
    return os << "Tram " << tram.tramNumber;
}

Tram::operator std::string() {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
    std::ostringstream output;
    output << "Tram " << this->tramNumber << " in TramStop " << this->getCurrentStation()->getName();
    std::string outputString  = output.str();
    return outputString;
}

bool Tram::properlyInitialized() const {
    return _initCheck == this;
}

void Tram::drive(TramStop *destination, int length, std::ostream &os) {
    os << *this << " reed van " << *currentStation << " naar ";

    currentStation = destination;

    os << *currentStation << "." << std::endl;
}

PCC::PCC(int tramNumber, TramStop *startStation) : Tram(tramNumber, 40, startStation) {
    _initCheck = this;
    ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
}

Albatros::Albatros(int tramNumber, Metrostation *startStation) : Tram(tramNumber, 70, startStation)  {}

Stadslijner::Stadslijner(int tramNumber, Metrostation *startStation) : Tram(tramNumber, 70, startStation)  {}
