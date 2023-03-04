#include "iostream"
#include "MetroXMLParser.h"
#include "tinyxml/tinyxml.h"
#include "Tram.h"
#include "Station.h"
#include "DesignByContract.h"
#include "Track.h"
#include "Line.h"

MetroXMLParser::MetroXMLParser(const std::string &filename) : filename(filename) {
    properlyParsed = parse();
    verify();
    properlyInitialized = isVerified && properlyParsed;
}

MetroXMLParser::~MetroXMLParser() {}

bool MetroXMLParser::parse() {
    TiXmlDocument doc(filename.c_str());
    if (!doc.LoadFile()) {
        std::cerr << doc.ErrorDesc() << std::endl;
        return false;
    }

    TiXmlElement* root = doc.FirstChildElement("SIMDATA");
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
        return false;
    }

    TiXmlElement* elem = root->FirstChildElement();
    while (elem) {
        std::string elemName = elem->Value();
        if (elemName == "STATION") {
            std::string naam = elem->FirstChildElement("naam")->GetText();
            std::string volgende = elem->FirstChildElement("volgende")->GetText();
            std::string vorige = elem->FirstChildElement("vorige")->GetText();
            int lineNr = atoi(elem->FirstChildElement("spoorNr")->GetText());

            Station *newStation = new Station;
            newStation->setName(naam);
            newStation->setLineNumber(lineNr);
            stations.push_back(newStation);

            stationMap[newStation] = std::pair<std::string, std::string> (volgende, vorige);

        } else if (elemName == "TRAM") {
            int lijnNr = atoi(elem->FirstChildElement("lijnNr")->GetText());
            int snelheid = atoi(elem->FirstChildElement("snelheid")->GetText());
            std::string begin = elem->FirstChildElement("beginStation")->GetText();

            Tram *newTram = new Tram;
            newTram->setLineNumber(lijnNr);
            newTram->setSpeed(snelheid);
            trams.push_back(newTram);

            tramMap[newTram] = begin;
        }
        elem = elem->NextSiblingElement();
    }
    doc.Clear();
    handleStations();
    handleTrams();
    return true;
}

void MetroXMLParser::handleTrams() {
    REQUIRE(!tramMap.empty(),"tramMap is empty");
    REQUIRE(!trams.empty(), "trams is empty");

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
    REQUIRE(!stationMap.empty(),"StationMap is empty");
    REQUIRE(!stations.empty(), "stations is empty");

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

void MetroXMLParser::verify() {
    isVerified = true;
    bool connectedProperly;
    for (int i = 0; i < static_cast<int>(stations.size()); i++) {
        connectedProperly = stations[i]->getPrevTrack()->getBegin() != NULL && stations[i]->getNextTrack()->getAnEnd() != NULL;
        ENSURE(connectedProperly, "Stations not connected properly");
        stations[i]->setProperlyInitialized(connectedProperly);
        if (!connectedProperly) {
            isVerified = false;
        }
    }

    bool hasCorrespondingLine;
    bool validStartstation;
    for (int i = 0; i < static_cast<int>(trams.size()); i++) {
        validStartstation = trams[i]->getStartStation() != NULL;
        ENSURE(validStartstation, "Invalid startstation of tram");

        if (validStartstation) {
            hasCorrespondingLine = trams[i]->getLineNumber() == trams[i]->getStartStation()->getLineNumber();
            ENSURE(hasCorrespondingLine, "Track of tram does not correspond with track startStation");

            if (!hasCorrespondingLine) {
                isVerified = false;
            }
        } else {
            isVerified = false;
        }
    }

    bool lineHasTram;
    for (int i = 0; i < static_cast<int>(lines.size()); ++i) {
        lineHasTram = lines[i]->getTrams().size() > 0;
        ENSURE(lineHasTram, "Not every line has a tram");
        if (!lineHasTram) {
            isVerified = false;
        }
    }
}

const std::vector<Tram *> &MetroXMLParser::getTrams() const {return trams;}
const std::vector<Station *> &MetroXMLParser::getStations() const {return stations;}
bool MetroXMLParser::isProperlyInitialized() const {return properlyInitialized;}
bool MetroXMLParser::isProperlyParsed() const {return properlyParsed;}
const std::vector<Line *> &MetroXMLParser::getLines() const { return lines; }
