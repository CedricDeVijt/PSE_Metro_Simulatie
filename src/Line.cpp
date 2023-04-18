#include "Line.h"
#include "Track.h"
#include "Tram.h"
#include "DesignByContract.h"

Line::Line(int lineNumber) : lineNumber(lineNumber), verified(true) {
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
        TramStop *currentStation = tram->getCurrentStation();
        TramStop *next = getNext(currentStation);
        int length = getTrackLength(currentStation, next);
        trams[i]->drive(next, length, os);
    }
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

bool Line::verify(std::ostream &errorstream) {
    REQUIRE(properlyInitialised(), "The line was not properly initialised.");
    if (trams.empty()) {
        Logger::writeError(errorstream, "VerificationError: er zijn sporen waarvoor geen tram bestaat");
        verified=false;
    }
    return verified;
}

TramStop *Line::getNext(TramStop *station) {
    REQUIRE(properlyInitialised(), "The line was not properly initialised.");
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

TramStop *Line::getPrev(TramStop *station) {
    REQUIRE(properlyInitialised(), "The line was not properly initialised.");
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

int Line::getTrackLength(TramStop *curr, TramStop *next) {
    REQUIRE(properlyInitialised(), "The line was not properly initialised.");
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
    REQUIRE(properlyInitialised(), "The line was not properly initialised.");
    std::string output;

    std::stringstream ss;
    ss << lineNumber;
    std::string lineNrStr = ss.str();
    output += "Lijn " + lineNrStr + "\n\n";

    std::vector<TramStop*>::iterator it = stations.begin();
    while (it!=stations.end()) {
        TramStop *station = *it;
        output += "TramStop " + station->getName() + "\n";
        output += "<- TramStop " + getPrev(station)->getName() + "\n";
        output += "-> TramStop " + getNext(station)->getName() + "\n\n";
        it++;
    }

    std::vector<Tram*>::iterator it1 = trams.begin();
    while (it1!=trams.end()) {
        Tram *tram = *it1;

        std::stringstream ss1;
        ss1 << tram->getTramNumber();
        std::string tramNumStr = ss1.str();

        output += "Tram " + tramNumStr + " in TramStop " + tram->getCurrentStation()->getName() + "\n\n";
        it1++;
    }
    return output;
}

void Line::addStation(TramStop* station) {
    REQUIRE(properlyInitialised(), "The line was not properly initialised.");
    std::vector<TramStop*>::iterator it = stations.begin();
    while (it != stations.end()) {
        TramStop* station1 = *it;
        if (station1==station) {
            return;
        }
        it++;
    }
    stations.push_back(station);
}

void Line::deployTram(Tram *newTram, const std::string &stationName, std::ostream &errorStream) {
    REQUIRE(properlyInitialised(), "The line was not properly initialised.");
    std::vector<TramStop*>::iterator it = stations.begin();
    while (it!=stations.end()) {
        TramStop *station = *it;
        if (station->getName()==stationName) {
            trams.push_back(newTram);
            newTram->setStartStation(station);
            return;
        }
        it++;
    }
    Logger::writeError(errorStream, "StartStation Of Tram Not Found");
    Logger::writeError(errorStream, "Deploy Error: Niet elke tram heeft een lijn die overeenkomt met een spoor in zijn beginstation");
    verified = false;
    delete newTram;
}

TramStop *Line::getStation(const std::string &name) {
    REQUIRE(properlyInitialised(), "The line was not properly initialised.");
    std::vector<TramStop*>::iterator it = stations.begin();
    while (it!=stations.end()) {
        TramStop *station = *it;
        if (station->getName()==name) {
            return station;
        }
        it++;
    }
    return NULL;
}

void Line::connect(const std::string &start, const std::string &end, std::ostream &errorStream) {
    REQUIRE(properlyInitialised(), "The line was not properly initialised.");
    TramStop *startStation = getStation(start);
    TramStop *endStation = getStation(end);
    if (startStation==NULL) {
        Logger::writeError(errorStream, "Failed to connect: StartStation not found in Line");
        Logger::writeError(errorStream, "Failed to connect: niet elk station is verbonden met een voorgaand en een volgend station voor elk spoor");
        verified = false;
    } else if (endStation==NULL) {
        Logger::writeError(errorStream, "Failed to connect: EndStation not found in Line");
        Logger::writeError(errorStream, "Failed to connect: niet elk station is verbonden met een voorgaand en een volgend station voor elk spoor");
        verified = false;
    } else {
        Track *newTrack = new Track(startStation, endStation, 0);
        std::vector<Track*>::iterator it = tracks.begin();
        while (it != tracks.end()) {
            Track *track = *it;
            if (track->getBegin()==newTrack->getBegin() && track->getAnEnd()==newTrack->getAnEnd()){
                return;
            }
            it++;
        }
        tracks.push_back(newTrack);
    }
}

const std::vector<TramStop *> &Line::getStations() const {
    return stations;
}
