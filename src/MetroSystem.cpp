#include <sstream>
#include <iomanip>
#include "MetroSystem.h"

MetroSystem::MetroSystem() : consistent(true) {
    _initCheck = this;
    ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
}

MetroSystem::~MetroSystem() {
    REQUIRE(properlyInitialized(), "MetroSystem is not properly initialised.");
    for (int i = 0; i < static_cast<int>(lines.size()); ++i) {
        delete lines[i];
    }
}

bool MetroSystem::properlyInitialized() const {
    return _initCheck==this;
}

void MetroSystem::updateSystem(std::ostream &os) {
    REQUIRE(properlyInitialized(), "MetroSystem is not properly initialised.");
    for (int j = 0; j < static_cast<int>(lines.size()); ++j) {
        lines[j]->update(os);
    }
}

void MetroSystem::addLine(const int &lineNumber) {
    REQUIRE(properlyInitialized(), "MetroSystem is not properly initialised.");
    std::vector<Line*>::iterator it = lines.begin();
    while (it != lines.end()) {
        Line* line = *it;
        if (line->getLineNumber()==lineNumber) {
            return;
        }
        it++;
    }
    lines.push_back(new Line(lineNumber));
}

void MetroSystem::addStation(TramStop *newStation, const int &lineNumber, std::ostream &errorStream) {
    REQUIRE(properlyInitialized(), "MetroSystem is not properly initialised.");
    //Dont make a new Pointer if a Statoin with this name exists
    std::vector<TramStop*>::iterator it1 = stations.begin();
    bool isNewStation = true;
    while (it1 != stations.end()) {
        TramStop *station = *it1;
        if (station->getName()==newStation->getName()) {
            newStation = station;
            isNewStation = false;
            break;
        }
        it1++;
    }
    if (isNewStation) stations.push_back(newStation);

    std::vector<Line*>::iterator it = lines.begin();
    while (it != lines.end()) {
        Line* line = *it;
        if (line->getLineNumber()==lineNumber) {
            line->addStation(newStation);
            return;
        }
        it++;
    }
    Logger::writeError(errorStream, "addStation: Line not found, station not added");
}

void MetroSystem::deployTram(Tram *newTram, const std::string &startStation, const int &lineNumber,std::ostream &errorStream) {
    REQUIRE(properlyInitialized(), "MetroSystem is not properly initialised.");
    //Check for double tramnumbers
    int newNumber = newTram->getTramNumber();
    std::vector<int>::iterator it1 = takenTramNumbers.begin();
    while (it1!=takenTramNumbers.end()) {
        if (*it1==newNumber) {
            Logger::writeError(errorStream, "Deploy Error: er zijn twee trams met hetzelfde voertuignummer");
            consistent = false;
            return;
        }
        it1++;
    }
    takenTramNumbers.push_back(newNumber);

    //Try to deploy tram at right TramStop*
    std::vector<Line*>::iterator it = lines.begin();
    while (it != lines.end()) {
        Line* line = *it;
        if (line->getLineNumber()==lineNumber) {
            line->deployTram(newTram, startStation, errorStream);
            return;
        }
        it++;
    }
    Logger::writeError(errorStream, "deployTram: Line Not found");
    Logger::writeError(errorStream, "deployTram: Niet elke tram heeft een lijn die overeenkomt met een spoor in zijn beginstation");
}

void MetroSystem::addConnection(const std::string &start, const std::string &end, const int &lineNumber,std::ostream &errorStream) {
    REQUIRE(properlyInitialized(), "MetroSystem is not properly initialised.");
    std::vector<Line*>::iterator it = lines.begin();
    while (it != lines.end()) {
        Line* line = *it;
        if (line->getLineNumber()==lineNumber) {
            line->connect(start, end, errorStream);
            return;
        }
        it++;
    }
}

void MetroSystem::verify(std::ostream &errorStream) {
    REQUIRE(properlyInitialized(), "MetroSystem is not properly initialised.");
    std::vector<Line*>::iterator it = lines.begin();
    while (it != lines.end()) {
        Line* line = *it;
        consistent = consistent && line->verify(errorStream);
        it++;
    }
    if (!consistent) {
        Logger::writeError(errorStream, "Inconsistent Metronet");
    }
}

const std::vector<Line *> &MetroSystem::getLines() const {
    return lines;
}

const std::vector<TramStop *> &MetroSystem::getStations() const {
    return stations;
}
