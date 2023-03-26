#include <cstdlib>
#include <sstream>
#include "Station.h"
#include "Track.h"
#include "DesignByContract.h"

Station::Station(const std::string &name) : name(name) {
    _initCheck = this;
    ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
}

Station::~Station() {
    REQUIRE(properlyInitialized(), "Station was not properly initialised.");
}

std::ostream &operator<<(std::ostream &os, const Station &station) {
    return os << "Station: " << station.getName();
}

const std::string &Station::getName() const {
    REQUIRE(properlyInitialized(), "Station was not properly initialised.");
    return name;
}
bool Station::properlyInitialized() const{ return _initCheck == this; }

bool Station::operator<(const Station &rhs) const {
    return name < rhs.name;
}