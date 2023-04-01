#include "MetroXMLParser.h"

void MetroXMLParser::loadMetroSystem(MetroSystem &system, const std::string &filename, std::ostream &errorStream) {
    TiXmlDocument doc(filename.c_str());
    if (!doc.LoadFile()) {
        Logger::writeError(errorStream,"Failed to load file: File not found");
        return;
    }
    TiXmlElement* root = doc.FirstChildElement("METRONET");
    if (root==NULL) {
        Logger::writeError(errorStream, "Failed to load file: No METRONET element");
        return;
    }

    TiXmlElement* elem = root->FirstChildElement();
    //Create All the Stations and lines and look for Unexpected elements
    while (elem) {
        std::string elemName = elem->Value();
        if (elemName == "STATION") {
            parseStation(system, elem, errorStream);
        } else if (elemName != "TRAM") {
            Logger::writeError(errorStream, "Unknown Element");
        }
        elem = elem->NextSiblingElement();
    }

    elem = root->FirstChildElement();
    //Connect stations and Deploy all trams
    while (elem) {
        std::string elemName = elem->Value();
        if (elemName == "STATION") {
            parseConnection(system, elem, errorStream);
        } else if (elemName == "TRAM") {
            parseTram(system, elem, errorStream);
        }
        elem = elem->NextSiblingElement();
    }
    doc.Clear();
    //verify every line
    system.verify(errorStream);
}

std::pair<std::string,bool> MetroXMLParser::readKey(TiXmlElement *elem, const std::string &key, std::ostream &errorStream) {
    elem = elem->FirstChildElement(key.c_str());
    if (elem == NULL) {
        Logger::writeError(errorStream, "Invalid Information: \"" + key + "\" element not found");
        return std::pair<std::string,bool> ("", false);
    }
    return std::pair<std::string,bool> (elem->GetText(), true);
}

void MetroXMLParser::parseStation(MetroSystem &system, TiXmlElement* stationElem, std::ostream &errorStream) {
    std::pair<std::string,bool> p;
    p = readKey(stationElem, "naam", errorStream);
    if (!p.second) return;
    std::string name = p.first;

    p = readKey(stationElem, "spoorNr", errorStream);
    if (!p.second) return;
    int lineNr = atoi(p.first.c_str());

    system.addLine(lineNr);
    system.addStation(new TramStop(name), lineNr);
}

void MetroXMLParser::parseTram(MetroSystem &system, TiXmlElement* tramElem, std::ostream &errorStream) {
    std::pair<std::string,bool> p;

    p = readKey(tramElem, "voertuigNr", errorStream);
    if (!p.second) return;
    int tramNr = atoi(p.first.c_str());

    p = readKey(tramElem, "lijnNr", errorStream);
    if (!p.second) return;
    int lijnNr = atoi(p.first.c_str());

    p = readKey(tramElem, "snelheid",errorStream);
    if (!p.second) return;
    int snelheid = atoi(tramElem->FirstChildElement("snelheid")->GetText());

    p = readKey(tramElem, "beginStation",errorStream);
    if (!p.second) return;
    std::string begin = p.first;

    system.deployTram(new Tram(tramNr, snelheid, NULL), begin, lijnNr,errorStream);
}

void MetroXMLParser::parseConnection(MetroSystem &system, TiXmlElement *stationElem, std::ostream &errorStream) {
    std::pair<std::string,bool> p;
    p = readKey(stationElem, "naam", errorStream);
    if (!p.second) return;
    std::string name = p.first;

    p = readKey(stationElem, "volgende", errorStream);
    if (!p.second) return;
    std::string next = p.first;

    p = readKey(stationElem, "vorige", errorStream);
    if (!p.second) return;
    std::string prev = p.first;

    p = readKey(stationElem, "spoorNr", errorStream);
    if (!p.second) return;
    int lineNr = atoi(p.first.c_str());

    system.addConnection(name, next, lineNr, errorStream);
    system.addConnection(prev, name, lineNr, errorStream);
}
