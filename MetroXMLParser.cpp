#include "iostream"
#include "MetroXMLParser.h"
#include "tinyxml/tinyxml.h"
#include "Tram.h"
#include "Station.h"
#include "DesignByContract.h"

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
            int spoorNr = atoi(elem->FirstChildElement("spoorNr")->GetText());

            Station *newStation = new Station;
            newStation->setName(naam);
            newStation->setTrackNumber(spoorNr);
            stations.push_back(newStation);

            stationMap[newStation] = std::pair<std::string, std::string> (volgende, vorige);
        } else if (elemName == "TRAM") {
            int lijnNr = atoi(elem->FirstChildElement("lijnNr")->GetText());
            int snelheid = atoi(elem->FirstChildElement("snelheid")->GetText());
            std::string begin = elem->FirstChildElement("beginStation")->GetText();

            Tram *newTram = new Tram;
            newTram->setTrackNumber(lijnNr);
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

const std::vector<Tram *> &MetroXMLParser::getTrams() const {return trams;}
const std::vector<Station *> &MetroXMLParser::getStations() const {return stations;}
bool MetroXMLParser::isProperlyInitialized() const {return properlyInitialized;}
bool MetroXMLParser::isProperlyParsed() const {return properlyParsed;}

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
                current->setNextStation(target);
            } else if (target->getName()==vorige) {
                vorigeFound = true;
                current->setPreviousStation(target);
            }
        }
    }
}

void MetroXMLParser::verify() {
    isVerified = true;
    bool connectedProperly;
    for (int i = 0; i < static_cast<int>(stations.size()); i++) {
        connectedProperly = stations[i]->getPreviousStation() != NULL && stations[i]->getNextStation() != NULL;
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
            hasCorrespondingLine = trams[i]->getTrackNumber() == trams[i]->getStartStation()->getTrackNumber();
            ENSURE(hasCorrespondingLine, "Track of tram does not correspond with track startStation");

            if (!hasCorrespondingLine) {
                isVerified = false;
            }
        } else {
            isVerified = false;
        }
    }
}