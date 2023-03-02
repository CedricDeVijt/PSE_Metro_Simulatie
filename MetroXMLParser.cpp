#include "iostream"
#include "MetroXMLParser.h"
#include "tinyxml/tinyxml.h"
#include "Tram.h"
#include "Station.h"
#include "algorithm"

MetroXMLParser::MetroXMLParser(const std::string &filename) : filename(filename) {
    properlyParsed = parse();
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
            newTram->setLineNumber(lijnNr);
            newTram->setSpeed(snelheid);
            trams.push_back(newTram);

            tramMap[newTram] = begin;
        }
        elem = elem->NextSiblingElement();
    }
    return true;
}


void MetroXMLParser::handleMaps() {
    for (int i = 0; i < stations.size(); i++) {
        Station* s = stations[i];
        std::pair<std::string, std::string> p = stationMap[s];
        std::string volgende = p.first;
        std::string vorige = p.second;

        for (int j = 0; j < stations.size(); ++j) {
            return;
        }
    }

}

const std::vector<Tram *> &MetroXMLParser::getTrams() const {return trams;}
const std::vector<Station *> &MetroXMLParser::getStations() const {return stations;}
bool MetroXMLParser::isProperlyInitialized() const {return properlyInitialized;}
bool MetroXMLParser::isProperlyParsed() const {return properlyParsed;}