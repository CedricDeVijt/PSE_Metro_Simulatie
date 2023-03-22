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
        Tram* tram = trams[i];
        Station *currentStation = tram->getCurrentStation();
        Station *next = getNext(currentStation);
        int length = getTrackLength(currentStation, next);
        trams[i]->drive(next, length, os);
    }
}

void Line::addTrack(Track *newTrack) {
    REQUIRE(properlyInitialised(), "The line was not properly initialised.");
    std::vector<Track*>::iterator it = tracks.begin();
    while (it!=tracks.end()) {
        Track *track = *it;
        if (track->getBegin()==newTrack->getBegin() && track->getAnEnd() == newTrack->getAnEnd()) {
            return;
        }
        it++;
    }

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

void Line::addStation(Station* station) {
    REQUIRE(properlyInitialised(), "The line was not properly initialised.");
    stations.push_back(station);
}


bool Line::verify(std::ostream &errorstream) {
    bool verified = true;

    std::vector<Station*>::iterator it = stations.begin();
    while (it!=stations.end()) {
        Station* station = *it;
        if (getNext(station)==NULL || getPrev(station)==NULL) {
            Logger::writeError(errorstream, "VerificationError: niet elk station is verbonden met een voorgaand en een volgend station voor elk spoor.");
            verified=false;
        }
        it++;
    }

    if (trams.empty()) {
        Logger::writeError(errorstream, "VerificationError: er zijn sporen waarvoor geen tram bestaat.");
        verified=false;
    } else {
        std::vector<Tram*>::iterator it1 = trams.begin();
        while (it1!=trams.end()) {
            Tram* tram = *it1;
            Station* startStation = tram->getStartStation();

            if (startStation==NULL) {
                Logger::writeError(errorstream, "VerificationError: het startstation van een tram is geen geldig station in het metronet.");
                verified=false;
            }
            else if (std::find(stations.begin(), stations.end(), startStation)==stations.end()) {
                Logger::writeError(errorstream, "VerificationError: niet elke tram heeft een lijn die overeenkomt met een spoor in zijn beginstation.");
                Logger::writeError(errorstream, "StartStation");
                Logger::writeError(errorstream, startStation->getName());
                Logger::writeError(errorstream, "Stations:");
                for (int i = 0; i < static_cast<int>(stations.size()); i++) {
                    Logger::writeError(errorstream, stations[i]->getName());
                }
                verified=false;
            }
            it1++;
        }
    }
    return verified;
}

Station *Line::getNext(Station *station) {
    std::vector<Track*>::iterator it = tracks.begin();
    while (it!=tracks.end()) {
        Track* track = *it;
        if (track->getBegin()==station) {
            return track->getAnEnd();
        }
        it++;
    }
    return NULL;
}

Station *Line::getPrev(Station *station) {
    std::vector<Track*>::iterator it = tracks.begin();
    while (it!=tracks.end()) {
        Track* track = *it;
        if (track->getAnEnd()==station) {
            return track->getBegin();
        }
        it++;
    }
    return NULL;
}

int Line::getTrackLength(Station *curr, Station *next) {
    std::vector<Track*>::iterator it = tracks.begin();
    while (it!=tracks.end()) {
        Track* track = *it;
        if ( (track->getAnEnd()==curr && track->getBegin()==next) ||
                (track->getAnEnd()==next && track->getBegin()==curr)) {
            return track->getLength();
        }
        it++;
    }
    return 0;
}

Line::operator std::string() {
    std::string output;

    std::stringstream ss;
    ss << lineNumber;
    std::string lineNrStr = ss.str();
    output += "Lijn " + lineNrStr + "\n\n";

    std::vector<Station*>::iterator it = stations.begin();
    while (it!=stations.end()) {
        Station *station = *it;
        output += "Station " + station->getName() + "\n";
        output += "<- Station " + getPrev(station)->getName() + "\n";
        output += "-> Station " + getNext(station)->getName() + "\n\n";
        it++;
    }

    std::vector<Tram*>::iterator it1 = trams.begin();
    while (it1!=trams.end()) {
        Tram *tram = *it1;

        std::stringstream ss1;
        ss1 << tram->getTramNumber();
        std::string tramNumStr = ss1.str();

        output += "Tram " + tramNumStr + " in Station " + tram->getCurrentStation()->getName() + "\n\n";
        it1++;
    }
    return output;
}
