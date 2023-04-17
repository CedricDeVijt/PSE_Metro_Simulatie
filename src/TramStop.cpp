#include <cstdlib>
#include <sstream>
#include <iostream>
#include "TramStop.h"
#include "Track.h"
#include "DesignByContract.h"
#include "Tram.h"

TramStop::TramStop(const std::string &name) : name(name), _initCheck(this), occupied(false) {
    ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
}

TramStop::~TramStop() {
    REQUIRE(properlyInitialized(), "TramStop was not properly initialised.");
}

std::ostream &operator<<(std::ostream &os, const TramStop &station) {
    return os << "TramStop: " << station.getName();
}

const std::string &TramStop::getName() const {
    REQUIRE(properlyInitialized(), "TramStop was not properly initialised.");
    return name;
}
bool TramStop::properlyInitialized() const{ return _initCheck == this; }

bool TramStop::operator<(const TramStop &rhs) const {
    return name < rhs.name;
}

bool TramStop::isOccupied() const {
    REQUIRE(properlyInitialized(), "TramStop was not properly initialised.");
    return occupied;
}

void TramStop::setOccupied(bool occupied_) {
    TramStop::occupied = occupied_;
}

Metrostation::Metrostation(const std::string &name) : TramStop(name) {}

bool Metrostation::acceptsTramType(Tram *tram) {
    return true;
}

Metrostation::~Metrostation() {}

Halte::Halte(const std::string &name) : TramStop(name) {}

bool Halte::acceptsTramType(Tram *tram) {
    return dynamic_cast<PCC*>(tram);
}

Halte::~Halte() {}
