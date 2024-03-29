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

void MetroSystem::updateSystem() {
    REQUIRE(properlyInitialized(), "MetroSystem is not properly initialised.");
    for (int j = 0; j < static_cast<int>(lines.size()); ++j) {
        lines[j]->update();
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

void MetroSystem::addStation(TramStop *newStation, const int &lineNumber) {
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
    Logger::error("addStation: Line not found, station not added");
}

void MetroSystem::deployTram(Tram *newTram, const std::string &startStation, const int &lineNumber) {
    REQUIRE(properlyInitialized(), "MetroSystem is not properly initialised.");
    //Check for double tramnumbers
    int newNumber = newTram->getTramNumber();
    std::vector<int>::iterator it1 = takenTramNumbers.begin();
    while (it1!=takenTramNumbers.end()) {
        if (*it1==newNumber) {
            Logger::error("Deploy Error: er zijn twee trams met hetzelfde voertuignummer");
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
            line->deployTram(newTram, startStation);
            return;
        }
        it++;
    }
    Logger::error("deployTram: Line Not found");
    Logger::error("deployTram: Niet elke tram heeft een lijn die overeenkomt met een spoor in zijn beginstation");
}

void MetroSystem::addConnection(const std::string &start, const std::string &end, const int &lineNumber) {
    REQUIRE(properlyInitialized(), "MetroSystem is not properly initialised.");
    std::vector<Line*>::iterator it = lines.begin();
    while (it != lines.end()) {
        Line* line = *it;
        if (line->getLineNumber()==lineNumber) {
            line->connect(start, end);
            return;
        }
        it++;
    }
}

void MetroSystem::verify() {
    REQUIRE(properlyInitialized(), "MetroSystem is not properly initialised.");
    std::vector<Line*>::iterator it = lines.begin();
    while (it != lines.end()) {
        Line* line = *it;
        consistent = consistent && line->verify();
        it++;
    }
    if (!consistent) {
        Logger::error("Inconsistent Metronet");
    }
}

const std::vector<Line *> &MetroSystem::getLines() const {
    REQUIRE(properlyInitialized(), "MetroSystem is not properly initialised.");
    return lines;
}

const std::vector<TramStop *> &MetroSystem::getStations() const {
    REQUIRE(properlyInitialized(), "MetroSystem is not properly initialised.");
    return stations;
}

std::pair<std::vector<TramStop *>, std::vector<Line *> > MetroSystem::getRoute(const std::string &beginStopName, const std::string &endStopName) {
    REQUIRE(properlyInitialized(), "MetroSystem is not properly initialised.");

    // Find Station* for the two strings and find lines where Stops are on
    TramStop *beginStop;
    TramStop *endStop;
    std::vector<Line *> beginStopLines;
    std::vector<Line *> endStopLines;
    for (int i = 0; i < (int)lines.size(); ++i) {
        Line *line = lines[i];

        if (line->getStation(beginStopName) != NULL){
            beginStop = line->getStation(beginStopName);
            beginStopLines.push_back(line);
        }
        if (line->getStation(endStopName) != NULL){
            endStop = line->getStation(endStopName);
            endStopLines.push_back(line);
        }
    }

    // Check if endStation on same line as begin station
    for (int i = 0; i < (int)beginStopLines.size(); ++i) {
        for (int j = 0; j < (int)endStopLines.size(); ++j) {
            if (beginStopLines[i] == endStopLines[j]){
                std::vector<TramStop *> resultingStops;
                resultingStops.push_back(beginStop);
                resultingStops.push_back(endStop);

                std::vector<Line *> resultingLines;
                resultingLines.push_back(beginStopLines[i]);

                std::pair<std::vector<TramStop *>, std::vector<Line *> > result;
                result.first = resultingStops;
                result.second = resultingLines;
                return result;
            }
        }
    }

    // Stations are on different lines -> find connection
    for (int i = 0; i < (int)beginStopLines.size(); ++i) {
        std::vector<TramStop *>beginStops = beginStopLines[i]->getStations();
        for (int j = 0; j < (int)endStopLines.size(); ++j) {
            std::vector<TramStop *>endStops = endStopLines[j]->getStations();
            for (int k = 0; k < (int)beginStops.size(); ++k) {
                for (int l = 0; l < (int)endStops.size(); ++l) {
                    if (beginStops[k] == endStops[l]){
                        std::vector<TramStop *> resultingStops;
                        resultingStops.push_back(beginStop);
                        resultingStops.push_back(beginStops[k]);
                        resultingStops.push_back(endStop);

                        std::vector<Line *> resultingLines;
                        resultingLines.push_back(beginStopLines[i]);
                        resultingLines.push_back(endStopLines[i]);

                        std::pair<std::vector<TramStop *>, std::vector<Line *> > result;
                        result.first = resultingStops;
                        result.second = resultingLines;
                        return result;
                    }
                }
            }
        }
    }

    // No route
    std::vector<TramStop *> resultingStops;
    resultingStops.push_back(beginStop);
    resultingStops.push_back(endStop);

    std::vector<Line *> resultingLines;

    std::pair<std::vector<TramStop *>, std::vector<Line *> > result;
    result.first = resultingStops;
    result.second = resultingLines;
    return result;
}
