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

std::pair<std::string,bool> MetroXMLParser::readKey(const TiXmlElement *elem, const std::string &key, std::ostream &errorStream) {
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

    p = readKey(stationElem, "type", errorStream);
    if (!p.second) return;
    std::string type = p.first;
    TramStop* newStop;
    if (type=="Metrostation") {
        newStop = new Metrostation(name);
    } else if (type=="Halte") {
        newStop = new Halte(name);
    } else {
        Logger::writeError(errorStream, "Invalid Station type");
        return;
    }

    TiXmlElement *elem = stationElem->FirstChildElement();
    while (elem) {
        std::string elemName = elem->Value();
        if (elemName == "SPOOR") {
            p = readKey(elem, "spoorNr", errorStream);
            if (!p.second) return;
            int lineNr = atoi(p.first.c_str());

            system.addLine(lineNr);
            system.addStation(newStop, lineNr, errorStream);
        }
        elem = elem->NextSiblingElement();
    }
}

void MetroXMLParser::parseTram(MetroSystem &system, TiXmlElement* tramElem, std::ostream &errorStream) {
    std::pair<std::string,bool> p;

    p = readKey(tramElem, "voertuigNr", errorStream);
    if (!p.second) return;
    int tramNr = atoi(p.first.c_str());

    p = readKey(tramElem, "lijnNr", errorStream);
    if (!p.second) return;
    int lijnNr = atoi(p.first.c_str());

    p = readKey(tramElem, "beginStation",errorStream);
    if (!p.second) return;
    std::string begin = p.first;

    p = readKey(tramElem, "type", errorStream);
    if (!p.second) return;
    std::string type = p.first;
    Tram *newTram;
    if (type=="PCC") {
        p = readKey(tramElem, "aantalDefecten", errorStream);
        if (!p.second) return;
        int aantalDefecten = atoi(p.first.c_str());

        p = readKey(tramElem, "reparatieTijd", errorStream);
        if (!p.second) return;
        int reparatieTijd = atoi(p.first.c_str());

        p = readKey(tramElem, "reparatieKost", errorStream);
        if (!p.second) return;
        int reparatieKost = atoi(p.first.c_str());

        newTram = new PCC(tramNr, NULL,reparatieTijd,aantalDefecten, reparatieKost);
    } else if (type=="Stadslijner") {
        newTram = new Stadslijner(tramNr, NULL);
    } else if (type=="Albatros") {
        newTram = new Albatros(tramNr, NULL);
    } else {
        Logger::writeError(errorStream, "Invalid Tram type");
        return;
    }
    system.deployTram(newTram, begin, lijnNr,errorStream);
}

void MetroXMLParser::parseConnection(MetroSystem &system, TiXmlElement *stationElem, std::ostream &errorStream) {
    std::pair<std::string,bool> p;
    p = readKey(stationElem, "naam", errorStream);
    if (!p.second) return;
    std::string name = p.first;

    TiXmlElement *elem = stationElem->FirstChildElement();
    while (elem) {
        std::string elemName = elem->Value();
        if (elemName == "SPOOR") {
            p = readKey(elem, "volgende", errorStream);
            if (!p.second) return;
            std::string next = p.first;

            p = readKey(elem, "vorige", errorStream);
            if (!p.second) return;
            std::string prev = p.first;

            p = readKey(elem, "spoorNr", errorStream);
            if (!p.second) return;
            int lineNr = atoi(p.first.c_str());

            system.addConnection(name, next, lineNr, errorStream);
            system.addConnection(prev, name, lineNr, errorStream);
        }
        elem = elem->NextSiblingElement();
    }
}
