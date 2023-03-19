#include "iostream"
#include "MetroXMLParser.h"
#include "../tinyxml/tinyxml.h"
#include "Tram.h"
#include "Station.h"
#include "DesignByContract.h"
#include "Track.h"
#include "Line.h"
#include "Logger.h"

MetroXMLParser::MetroXMLParser(const std::string &filename, std::ostream &errorStream) : errorstream(errorStream) {
    _initCheck = this;
    properlyParsed = parse(filename);
    ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
}

MetroXMLParser::~MetroXMLParser() {}

bool MetroXMLParser::parse(const std::string &filename) {
    REQUIRE(properlyInitialized(), "MetroXMLParser was not initialized when calling parse");

    TiXmlDocument doc(filename.c_str());
    if (!doc.LoadFile()) {
        Logger::writeError(errorstream,"Failed to load file: File not found");
        return false;
    }
    TiXmlElement* root = doc.FirstChildElement("METRODATA");
    if (root==NULL) {
        Logger::writeError(errorstream, "Failed to load file: No METRODATA element");
        return false;
    }

    TiXmlElement* elem = root->FirstChildElement();
    while (elem) {
        std::string elemName = elem->Value();
        if (elemName == "STATION") {
            parseStation(elem);
        } else if (elemName == "TRAM") {
            parseTram(elem);
        } else {
            Logger::writeError(errorstream, "Unknown Element");
        }
        elem = elem->NextSiblingElement();
    }
    doc.Clear();
    handleStations();
    handleTrams();
    return verify();
}

std::pair<std::string,bool> MetroXMLParser::readKey(TiXmlElement *elem, const std::string &key) {
    REQUIRE(properlyInitialized(), "MetroXMLParser was not initialized when calling readKey");
    elem = elem->FirstChildElement(key.c_str());
    if (elem == NULL) {
        Logger::writeError(errorstream, "Invalid Information: \"" + key + "\" element not found");
        return std::pair<std::string,bool> ("", false);
    }
    return std::pair<std::string,bool> (elem->GetText(), true);
}


void MetroXMLParser::parseStation(TiXmlElement *stationElem) {
    REQUIRE(properlyInitialized(), "MetroXMLParser was not initialized when calling parseStation");
    std::pair<std::string,bool> p;

    p = readKey(stationElem, "naam");
    if (!p.second) return;
    std::string name = p.first;

    p = readKey(stationElem, "volgende");
    if (!p.second) return;
    std::string next = p.first;

    p = readKey(stationElem, "vorige");
    if (!p.second) return;
    std::string prev = p.first;

    p = readKey(stationElem, "spoorNr");
    if (!p.second) return;
    int lineNr = atoi(p.first.c_str());

    Station *newStation = new Station(name, NULL, NULL, lineNr);
    stations.push_back(newStation);
    stationMap[newStation] = std::pair<std::string, std::string> (next, prev);
}

void MetroXMLParser::parseTram(TiXmlElement *tramElem) {
    REQUIRE(properlyInitialized(), "MetroXMLParser was not initialized when calling parseTram");
    std::pair<std::string,bool> p;

    p = readKey(tramElem, "lijnNr");
    if (!p.second) return;
    int lijnNr = atoi(p.first.c_str());

    p = readKey(tramElem, "snelheid");
    if (!p.second) return;
    int snelheid = atoi(tramElem->FirstChildElement("snelheid")->GetText());

    p = readKey(tramElem, "beginStation");
    if (!p.second) return;
    std::string begin = p.first;

    Tram *newTram = new Tram(lijnNr, static_cast<int>(trams.size()),snelheid,NULL);
    trams.push_back(newTram);
    tramMap[newTram] = begin;
}

void MetroXMLParser::handleTrams() {
    REQUIRE(properlyInitialized(), "MetroXMLParser was not initialized when calling handleTrams");

    Station *target;
    for (int i = 0; i < static_cast<int>(trams.size()); i++) {
        Tram *current = trams[i];
        std::string beginString = tramMap[current];

        bool found = false;
        for (int j = 0; j < static_cast<int>(stations.size()); j++) {
            if (found) { continue; }
            target = stations[j];
            if (target->getName()==beginString) {
                found = true;
                current->setStartStation(target);
            }
        }
        bool foundLine = false;
        for (int j = 0; j < static_cast<int>(lines.size()); j++) {
            if (foundLine) { continue; }
            if (lines[j]->getLineNumber() == trams[i]->getLineNumber()) {
                foundLine = true;
                lines[j]->addTram(trams[i]);
            }
        }
        if (!foundLine) {
            Line *newLine = new Line(trams[i]->getLineNumber());
            newLine->addTram(trams[i]);
            lines.push_back(newLine);
        }
    }
}

void MetroXMLParser::handleStations() {
    REQUIRE(properlyInitialized(), "MetroXMLParser was not initialized when calling handleStations");

    Station *target;
    for (int i = 0; i < static_cast<int>(stations.size()); i++) {
        Station* current = stations[i];
        std::pair<std::string, std::string> p = stationMap[current];
        std::string volgende = p.first;
        std::string vorige = p.second;

        bool vorigeFound = false;
        bool volgendeFound = false;
        for (int j = 0; j < static_cast<int>(stations.size()); j++) {
            if (vorigeFound && volgendeFound) { continue; }
            target = stations[j];
            if (target->getName()==volgende) {
                volgendeFound = true;
                current->setNextTrack(target);
            } else if (target->getName()==vorige) {
                vorigeFound = true;
                current->setPrevTrack(target);
            }
        }

        bool foundLine = false;
        for (int j = 0; j < static_cast<int>(lines.size()); j++) {
            if (foundLine) { continue; }
            if (lines[j]->getLineNumber() == stations[i]->getLineNumber()) {
                foundLine = true;
                lines[j]->addTrack(stations[i]->getNextTrack());
            }
        }
        if (!foundLine) {
            Line *newLine = new Line(stations[i]->getLineNumber());
            newLine->addTrack(stations[i]->getNextTrack());
            lines.push_back(newLine);
        }
    }
}

bool MetroXMLParser::verify() {
    bool isVerified = true;

    bool connectedProperly;
    for (int i = 0; i < static_cast<int>(stations.size()); i++) {
        connectedProperly = stations[i]->getPrevTrack() != NULL && stations[i]->getNextTrack() != NULL;
        if (!connectedProperly) {
            Logger::writeError(errorstream, "VerificationError: Stations are not connected properly");
            isVerified = false;
        }
    }

    bool hasCorrespondingLine;
    bool validStartstation;
    for (int i = 0; i < static_cast<int>(trams.size()); i++) {
        validStartstation = trams[i]->getStartStation() != NULL;
        if (validStartstation) {
            hasCorrespondingLine = trams[i]->getLineNumber() == trams[i]->getStartStation()->getLineNumber();
            if (!hasCorrespondingLine) {
                Logger::writeError(errorstream, "VerificationError: LineNumber of tram does not correspond with LineNumber of startStation");
                isVerified = false;
            }
        } else {
            Logger::writeError(errorstream, "VerificationError: Invalid startstation of tram");
            isVerified = false;
        }
    }

    bool lineHasTram;
    for (int i = 0; i < static_cast<int>(lines.size()); ++i) {
        lineHasTram = lines[i]->getTrams().size() > 0;
        if (!lineHasTram) {
            Logger::writeError(errorstream, "VerificationError: Invalid startstation of tram");
            isVerified = false;
        }
    }
    return isVerified;
}

const std::vector<Tram *> &MetroXMLParser::getTrams() const {
    REQUIRE(properlyInitialized(), "MetroXMLParser was not initialized when calling handleStations");
    return trams;
}

const std::vector<Station *> &MetroXMLParser::getStations() const {
    REQUIRE(properlyInitialized(), "MetroXMLParser was not initialized when calling handleStations");
    return stations;
}

bool MetroXMLParser::properlyInitialized() const {
    return _initCheck==this;
}

bool MetroXMLParser::isProperlyParsed() const {
    REQUIRE(properlyInitialized(), "MetroXMLParser was not initialized when calling handleStations");
    return properlyParsed;
}

const std::vector<Line *> &MetroXMLParser::getLines() const {
    REQUIRE(properlyInitialized(), "MetroXMLParser was not initialized when calling handleStations");
    return lines;
}

