#include "MetroXMLParser.h"

void MetroXMLParser::loadMetroSystem(MetroSystem &system, const std::string &filename) {
    TiXmlDocument doc(filename.c_str());
    if (!doc.LoadFile()) {
        Logger::error("Failed to load file: File not found");
        return;
    }
    TiXmlElement* root = doc.FirstChildElement("METRONET");
    if (root==NULL) {
        Logger::error("Failed to load file: No METRONET element");
        return;
    }

    TiXmlElement* elem = root->FirstChildElement();
    //Create All the Stations and lines and look for Unexpected elements
    while (elem) {
        std::string elemName = elem->Value();
        if (elemName == "STATION") {
            parseStation(system, elem);
        } else if (elemName != "TRAM") {
            Logger::error("Unknown Element");
        }
        elem = elem->NextSiblingElement();
    }

    elem = root->FirstChildElement();
    //Connect stations and Deploy all trams
    while (elem) {
        std::string elemName = elem->Value();
        if (elemName == "STATION") {
            parseConnection(system, elem);
        } else if (elemName == "TRAM") {
            parseTram(system, elem);
        }
        elem = elem->NextSiblingElement();
    }
    doc.Clear();
    //verify every line
    system.verify();
}

std::pair<std::string,bool> MetroXMLParser::readKey(const TiXmlElement *elem, const std::string &key) {
    elem = elem->FirstChildElement(key.c_str());
    if (elem == NULL) {
        Logger::error("Invalid Information: \"" + key + "\" element not found");
        return std::pair<std::string,bool> ("", false);
    }
    return std::pair<std::string,bool> (elem->GetText(), true);
}

void MetroXMLParser::parseStation(MetroSystem &system, TiXmlElement* stationElem) {
    std::pair<std::string,bool> p;
    p = readKey(stationElem, "naam");
    if (!p.second) return;
    std::string name = p.first;

    p = readKey(stationElem, "type");
    if (!p.second) return;
    std::string type = p.first;
    TramStop* newStop;
    if (type=="Metrostation") {
        newStop = new Metrostation(name);
    } else if (type=="Halte") {
        newStop = new Halte(name);
    } else {
        Logger::error("Invalid Station type");
        return;
    }

    TiXmlElement *elem = stationElem->FirstChildElement();
    while (elem) {
        std::string elemName = elem->Value();
        if (elemName == "SPOOR") {
            p = readKey(elem, "spoorNr");
            if (!p.second) return;
            int lineNr = atoi(p.first.c_str());

            system.addLine(lineNr);
            system.addStation(newStop, lineNr);
        }
        elem = elem->NextSiblingElement();
    }
}

void MetroXMLParser::parseTram(MetroSystem &system, TiXmlElement* tramElem) {
    std::pair<std::string,bool> p;

    p = readKey(tramElem, "voertuigNr");
    if (!p.second) return;
    int tramNr = atoi(p.first.c_str());

    p = readKey(tramElem, "lijnNr");
    if (!p.second) return;
    int lijnNr = atoi(p.first.c_str());

    p = readKey(tramElem, "beginStation");
    if (!p.second) return;
    std::string begin = p.first;

    p = readKey(tramElem, "type");
    if (!p.second) return;
    std::string type = p.first;
    Tram *newTram;
    if (type=="PCC") {
        p = readKey(tramElem, "aantalDefecten");
        if (!p.second) return;
        int aantalDefecten = atoi(p.first.c_str());

        p = readKey(tramElem, "reparatieTijd");
        if (!p.second) return;
        int reparatieTijd = atoi(p.first.c_str());

        p = readKey(tramElem, "reparatieKost");
        if (!p.second) return;
        int reparatieKost = atoi(p.first.c_str());

        newTram = new PCC(tramNr, NULL,reparatieTijd,aantalDefecten, reparatieKost);
    } else if (type=="Stadslijner") {
        newTram = new Stadslijner(tramNr, NULL);
    } else if (type=="Albatros") {
        newTram = new Albatros(tramNr, NULL);
    } else {
        Logger::error("Invalid Tram type");
        return;
    }
    system.deployTram(newTram, begin, lijnNr);
}

void MetroXMLParser::parseConnection(MetroSystem &system, TiXmlElement *stationElem) {
    std::pair<std::string,bool> p;
    p = readKey(stationElem, "naam");
    if (!p.second) return;
    std::string name = p.first;

    TiXmlElement *elem = stationElem->FirstChildElement();
    while (elem) {
        std::string elemName = elem->Value();
        if (elemName == "SPOOR") {
            p = readKey(elem, "volgende");
            if (!p.second) return;
            std::string next = p.first;

            p = readKey(elem, "vorige");
            if (!p.second) return;
            std::string prev = p.first;

            p = readKey(elem, "spoorNr");
            if (!p.second) return;
            int lineNr = atoi(p.first.c_str());

            system.addConnection(name, next, lineNr);
            system.addConnection(prev, name, lineNr);
        }
        elem = elem->NextSiblingElement();
    }
}
