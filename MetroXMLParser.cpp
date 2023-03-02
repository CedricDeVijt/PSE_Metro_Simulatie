#include "iostream"
#include "MetroXMLParser.h"
#include "tinyxml/tinyxml.h"

MetroXMLParser::MetroXMLParser(const std::string &filename) : filename(filename) {
    properlyInitialized = true;
    properlyParsed = parse();
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
        std::cout << elemName << std::endl;
        if (elemName == "STATION") {
            std::string naam = elem->FirstChildElement("naam")->GetText();
            std::string volgende = elem->FirstChildElement("volgende")->GetText();
            std::string vorige = elem->FirstChildElement("vorige")->GetText();
            std::string spoorNr = elem->FirstChildElement("spoorNr")->GetText();
        } else if (elemName == "TRAM") {
            std::string lijnNr = elem->FirstChildElement("lijnNr")->GetText();
            std::string snelheid = elem->FirstChildElement("snelheid")->GetText();
            std::string begin = elem->FirstChildElement("beginStation")->GetText();
        }
        elem = elem->NextSiblingElement();
    }
    return true;
}

const std::vector<Tram *> &MetroXMLParser::getTrams() const {return trams;}
const std::vector<Station *> &MetroXMLParser::getStations() const {return stations;}
bool MetroXMLParser::isProperlyInitialized() const {return properlyInitialized;}
bool MetroXMLParser::isProperlyParsed() const {return properlyParsed;}

bool MetroXMLParser::verify() const {
    return false;
}

