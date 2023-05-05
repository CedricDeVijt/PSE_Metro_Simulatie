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
    std::vector<std::pair<Tram*,TramStop*> > drivers;
    for (int i = 0; i < static_cast<int>(trams.size()); i++) {
        Tram* tram = trams[i];
        if (tram->isDefect()) {
            tram->handleDefect(os);
            continue;
        }
        TramStop *currentStation = tram->getCurrentStation();
        TramStop *next = getNext(currentStation);
        while (!next->acceptsTramType(tram) && !next->acceptsTramType(tram)) {
            next = getNext(next);
        }
        if (!next->isOccupied()) {
            drivers.push_back(std::pair<Tram*,TramStop*>(tram,next));
        }
    }
    for (int i = 0; i < static_cast<int>(drivers.size()); i++) {
        std::pair<Tram*,TramStop*> drive = drivers[i];
        drive.first->drive(drive.second,os);
        drive.first->handleDefect(os);
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
            if (station->isOccupied()) {
                Logger::writeError(errorStream, "Deploy error, this station was already occupied.");
                verified = false;
                return;
            }
            trams.push_back(newTram);
            newTram->setStartStation(station);
            station->setOccupied(true);
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
        Track *newTrack = new Track(startStation, endStation);
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
