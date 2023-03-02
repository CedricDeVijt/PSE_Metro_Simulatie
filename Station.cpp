#include "Station.h"

Station::Station() {
    previousStation = NULL;
    nextStation = NULL;
}
Station::Station(const std::string &name, Station *nextStation, Station *previousStation, int trackNumber) : name(name),
                                                                                                            nextStation(
                                                                                                                    nextStation),
                                                                                                            previousStation(
                                                                                                                    previousStation),
                                                                                                            trackNumber(
                                                                                                                    trackNumber) {
    properlyInitialized = true;
}

const std::string &Station::getName() const {
    return name;
}

void Station::setName(const std::string &name_) {
    Station::name = name_;
}

Station *Station::getNextStation() const {
    return nextStation;
}

void Station::setNextStation(Station *nextStation_) {
    Station::nextStation = nextStation_;
}

Station *Station::getPreviousStation() const {
    return previousStation;
}

void Station::setPreviousStation(Station *previousStation_) {
    Station::previousStation = previousStation_;
}

int Station::getTrackNumber() const {
    return trackNumber;
}

void Station::setTrackNumber(int trackNumber_) {
    Station::trackNumber = trackNumber_;
}

Station::~Station() {
}

bool Station::isProperlyInitialized() const {
    return properlyInitialized;
}

void Station::setProperlyInitialized(bool properlyInitialized_) {
    Station::properlyInitialized = properlyInitialized_;
}



