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
    parse(filename);
    ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
}

MetroXMLParser::~MetroXMLParser() {
    REQUIRE(properlyInitialized(), "MetroXMLParser was not initialized when calling parse");
}

void MetroXMLParser::parse(const std::string &filename) {
    REQUIRE(properlyInitialized(), "MetroXMLParser was not initialized when calling parse");

    TiXmlDocument doc(filename.c_str());
    if (!doc.LoadFile()) {
        Logger::writeError(errorstream,"Failed to load file: File not found");
        properlyParsed = false;
        return;
    }
    TiXmlElement* root = doc.FirstChildElement("METRODATA");
    if (root==NULL) {
        Logger::writeError(errorstream, "Failed to load file: No METRODATA element");
        properlyParsed = false;
        return;
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
            properlyParsed = false;
        }
        elem = elem->NextSiblingElement();
    }
    doc.Clear();
    handleStations();
    handleTrams();
    convertObjectMaps();
    verify();
}

std::pair<std::string,bool> MetroXMLParser::readKey(TiXmlElement *elem, const std::string &key) {
    REQUIRE(properlyInitialized(), "MetroXMLParser was not initialized when calling readKey");
    elem = elem->FirstChildElement(key.c_str());
    if (elem == NULL) {
        Logger::writeError(errorstream, "Invalid Information: \"" + key + "\" element not found");
        properlyParsed = false;
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

    if (!stationObjectMap.count(name)) {
        stationObjectMap[name] = new Station(name);
    }

    stationMap[name].push_back(trackStringPair (trackConnectionsStringPair (next, prev),lineNr));
}

void MetroXMLParser::parseTram(TiXmlElement *tramElem) {
    REQUIRE(properlyInitialized(), "MetroXMLParser was not initialized when calling parseTram");
    std::pair<std::string,bool> p;

    p = readKey(tramElem, "tramNr");
    if (!p.second) return;
    int tramNr = atoi(p.first.c_str());

    p = readKey(tramElem, "lijnNr");
    if (!p.second) return;
    int lijnNr = atoi(p.first.c_str());

    p = readKey(tramElem, "snelheid");
    if (!p.second) return;
    int snelheid = atoi(tramElem->FirstChildElement("snelheid")->GetText());

    p = readKey(tramElem, "beginStation");
    if (!p.second) return;
    std::string begin = p.first;

    if (!tramObjectMap.count(tramNr)) {
        tramObjectMap[tramNr] = new Tram(tramNr, snelheid, NULL);
    }

    if (tramMap.count(lijnNr)) {
        Logger::writeError(errorstream, "VerificationError: er mogen geen twee trams zijn met hetzelfde voertuignummer");
        properlyParsed = false;
    } else {
        tramMap[tramNr] = std::pair<std::string, int> (begin, lijnNr);
    }
}

void MetroXMLParser::handleTrams() {
    REQUIRE(properlyInitialized(), "MetroXMLParser was not initialized when calling handleTrams");
    tramMap::iterator it = tramMap.begin();
    while (it!=tramMap.end()) {
        std::pair<int, std::pair<std::string,int> > p = *it;
        int tramNumber = p.first;
        std::string begin = p.second.first;
        int lijnNr = p.second.second;
        Tram *tram = tramObjectMap[tramNumber];
        tram->setStartStation(stationObjectMap[begin]);

        if (!lineObjectMap.count(lijnNr)) {
            lineObjectMap[lijnNr] = new Line(lijnNr);
        }

        lineObjectMap[lijnNr]->addTram(tram);
        it++;
    }
}

void MetroXMLParser::handleStations() {
    REQUIRE(properlyInitialized(), "MetroXMLParser was not initialized when calling handleStations");

    stationMap::iterator it = stationMap.begin();

    while (it!=stationMap.end()) {
        std::pair<std::string, trackStringPairs> p = *it;
        std::string name = p.first;
        trackStringPairs pairs = p.second;
        int lijnNr;
        for (int i = 0; i < static_cast<int>(pairs.size()); i++) {
            trackStringPair pair = pairs[i];
            std::string next = pair.first.first;
            std::string prev = pair.first.second;
            lijnNr = pair.second;

            if (!lineObjectMap.count(lijnNr)) {
                lineObjectMap[lijnNr] = new Line(lijnNr);
            }

            Track *nextTrack = new Track(stationObjectMap[name], stationObjectMap[next],0);
            Track *prevTrack = new Track(stationObjectMap[prev], stationObjectMap[name],0);
            lineObjectMap[lijnNr]->addTrack(nextTrack);
            lineObjectMap[lijnNr]->addTrack(prevTrack);
        }
        lineObjectMap[lijnNr]->addStation(stationObjectMap[name]);
        it++;
    }
}

void MetroXMLParser::verify() {
    std::vector<Line*>::iterator it = lines.begin();
    while (it!=lines.end()) {
        properlyParsed = properlyParsed && (*it)->verify(errorstream);
        it++;
    }
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

void MetroXMLParser::convertObjectMaps() {
    std::map<std::string, Station*>::iterator it = stationObjectMap.begin();
    while (it!=stationObjectMap.end()) {
        stations.push_back((*it).second);
        it++;
    }

    std::map<int, Tram*>::iterator it1 = tramObjectMap.begin();
    while (it1!=tramObjectMap.end()) {
        trams.push_back((*it1).second);
        it1++;
    }

    std::map<int, Line*>::iterator it2 = lineObjectMap.begin();
    while (it2!=lineObjectMap.end()) {
        lines.push_back((*it2).second);
        it2++;
    }
}

