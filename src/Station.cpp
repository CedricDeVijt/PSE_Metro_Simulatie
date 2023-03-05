#include "Station.h"
#include "Track.h"

Station::Station() {
    nextTrack = NULL;
    prevTrack = NULL;
}

Station::Station(const std::string &name, Track *nextTrack, Track *prevTrack, int lineNumber) : name(name),
                                                                                                nextTrack(nextTrack),
                                                                                                prevTrack(prevTrack),
                                                                                                lineNumber(
                                                                                                        lineNumber) {
    properlyInitialized = true;
}

Station::~Station() {}

//getters
const std::string &Station::getName() const { return name; }
int Station::getLineNumber() const { return lineNumber; }
bool Station::isProperlyInitialized() const { return properlyInitialized; }
Track *Station::getNextTrack() const { return nextTrack; }
Track *Station::getPrevTrack() const { return prevTrack; }

//setters
void Station::setNextTrack(Station *nextStation) { Station::nextTrack = new Track(this, nextStation); }
void Station::setPrevTrack(Station *prevStation) { Station::prevTrack = new Track(prevStation, this); }
void Station::setLineNumber(int lineNumber_) { Station::lineNumber = lineNumber_; }
void Station::setName(const std::string &name_) { Station::name = name_; }
void Station::setProperlyInitialized(bool properlyInitialized_) { Station::properlyInitialized = properlyInitialized_; }