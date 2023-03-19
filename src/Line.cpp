#include "Line.h"
#include "Track.h"
#include "Tram.h"
#include "DesignByContract.h"

Line::Line(int lineNumber) : lineNumber(lineNumber) {
    _initCheck = this;
    ENSURE(properlyInitialised(), "constructor must end in properlyInitialized state");
}

Line::~Line() {
    REQUIRE(properlyInitialised(), "The line was not properly initialised.");
    for (int i = 0; i < static_cast<int>(trams.size()); ++i) {
        delete trams[i];
    }
    for (int i = 0; i < static_cast<int>(tracks.size()); ++i) {
        delete tracks[i];
    }
}

void Line::update(std::ostream &os) {
    REQUIRE(properlyInitialised(), "The line was not properly initialised.");
    for (int i = 0; i < static_cast<int>(trams.size()); i++) {
        trams[i]->drive(os);
    }
}

void Line::addTrack(Track *newTrack) {
    REQUIRE(properlyInitialised(), "The line was not properly initialised.");
    tracks.push_back(newTrack);
}
void Line::addTram(Tram *newTram) {
    REQUIRE(properlyInitialised(), "The line was not properly initialised.");
    trams.push_back(newTram);
}
int Line::getLineNumber() const {
    REQUIRE(properlyInitialised(), "The line was not properly initialised.");
    return lineNumber;
}
const std::vector<Track *> &Line::getTracks() const {
    REQUIRE(properlyInitialised(), "The line was not properly initialised.");
    return tracks;
}
const std::vector<Tram *> &Line::getTrams() const {
    REQUIRE(properlyInitialised(), "The line was not properly initialised.");
    return trams;
}

bool Line::properlyInitialised() const{
    return _initCheck == this;
}
