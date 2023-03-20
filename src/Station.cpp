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
}

Station::~Station() {}

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

//getters
const std::string &Station::getName() const {
    REQUIRE(properlyInitialized(), "Station was not properly initialised.");
    return name;
}
int Station::getLineNumber() const {
    return lineNumber;
}
Track *Station::getNextTrack() const {
    return nextTrack;
}
Track *Station::getPrevTrack() const {
    return prevTrack;
}

//setters
void Station::setNextTrack(Station *nextStation) {
    REQUIRE(properlyInitialized(), "Station was not properly initialised.");
    Station::nextTrack = new Track(this, nextStation);
}
void Station::setPrevTrack(Station *prevStation) {
    REQUIRE(properlyInitialized(), "Station was not properly initialised.");
    Station::prevTrack = new Track(prevStation, this);
}
void Station::setLineNumber(int lineNumber_) {
    REQUIRE(properlyInitialized(), "Station was not properly initialised.");
    Station::lineNumber = lineNumber_;
}
void Station::setName(const std::string &name_) {
    REQUIRE(properlyInitialized(), "Station was not properly initialised.");
    Station::name = name_;
}

bool Station::properlyInitialized() const{ return _initCheck == this; }
