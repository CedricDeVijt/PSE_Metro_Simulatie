#include <cstdlib>
#include <sstream>
#include "Station.h"
#include "Track.h"
#include "DesignByContract.h"

Station::Station(const std::string &name, Track *nextTrack, Track *prevTrack, int lineNumber) : name(name),
                                                                                                nextTrack(nextTrack),
                                                                                                prevTrack(prevTrack),
                                                                                                lineNumber(
                                                                                                        lineNumber) {
    _initCheck = this;
    ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
}

Station::~Station() {
    REQUIRE(properlyInitialized(), "Station was not properly initialised.");
}

std::ostream &operator<<(std::ostream &os, const Station &station) {
    return os << "Station " << station.getName();
}

Station::operator std::string() {
    REQUIRE(properlyInitialized(), "Station was not properly initialised.");
    std::ostringstream output;
    output <<  "Station " << this->getName() << "\n";
    output << "<- Station " << this->prevTrack->getBegin()->getName() << "\n";
    output << "-> Station " << this->nextTrack->getAnEnd()->getName() << "\n";

    std::string outputString  = output.str();

    return outputString;
}

const std::string &Station::getName() const {
    REQUIRE(properlyInitialized(), "Station was not properly initialised.");
    return name;
}
int Station::getLineNumber() const {
    REQUIRE(properlyInitialized(), "Station was not properly initialised.");
    return lineNumber;
}
Track *Station::getNextTrack() const {
    REQUIRE(properlyInitialized(), "Station was not properly initialised.");
    return nextTrack;
}
Track *Station::getPrevTrack() const {
    REQUIRE(properlyInitialized(), "Station was not properly initialised.");
    return prevTrack;
}

void Station::setNextTrack(Station *nextStation) {
    REQUIRE(properlyInitialized(), "Station was not properly initialised.");
    Station::nextTrack = new Track(this, nextStation);
}
void Station::setPrevTrack(Station *prevStation) {
    REQUIRE(properlyInitialized(), "Station was not properly initialised.");
    Station::prevTrack = new Track(prevStation, this);
}

bool Station::properlyInitialized() const{ return _initCheck == this; }
