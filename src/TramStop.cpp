#include <cstdlib>
#include <sstream>
#include "TramStop.h"
#include "Track.h"
#include "DesignByContract.h"

TramStop::TramStop(const std::string &name) : name(name) {
    _initCheck = this;
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