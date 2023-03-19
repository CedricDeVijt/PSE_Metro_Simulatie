#include "Line.h"
#include "Track.h"
#include "Tram.h"
#include "DesignByContract.h"

Line::Line(int lineNumber) : lineNumber(lineNumber) { _initCheck = this; }

Line::~Line() {
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
        Tram *currentTram = trams[i];
        bool drove = false;
        for (int j = 0; j < static_cast<int>(tracks.size()); j++) {
            if (drove) { continue; }
            Track *currentTrack = tracks[j];
            drove = currentTram->drive(currentTrack, os);
        }
        ENSURE(drove, "The tram did not find the right track to drive on.");
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
    return lineNumber;
}
const std::vector<Track *> &Line::getTracks() const {
    return tracks;
}
const std::vector<Tram *> &Line::getTrams() const {
    return trams;
}

bool Line::properlyInitialised() const{
    return _initCheck == this;
}
