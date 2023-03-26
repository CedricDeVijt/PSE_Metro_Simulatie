#include <sstream>
#include <iomanip>
#include "MetroSystem.h"

MetroSystem::MetroSystem(){
    _initCheck = this;
    ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
}

MetroSystem::~MetroSystem() {
    REQUIRE(properlyInitialized(), "Metrosimulation is not properly initialised.");
    for (int i = 0; i < static_cast<int>(lines.size()); ++i) {
        delete lines[i];
    }
}

bool MetroSystem::properlyInitialized() const {
    return _initCheck==this;
}

void MetroSystem::updateSystem(std::ostream &os) {
    REQUIRE(properlyInitialized(), "Metrosimulation is not properly initialised.");
    for (int j = 0; j < static_cast<int>(lines.size()); ++j) {
        lines[j]->update(os);
    }
}

void MetroSystem::outputSystem(std::ostream &os) {
    REQUIRE(properlyInitialized(), "Metrosimulation was not properly initialised.");
    std::vector<Line*>::iterator it = lines.begin();
    while (it!=lines.end()) {
        os << std::string(*(*it));
        it++;
    }
}

//source: https://stackoverflow.com/questions/154536/encode-decode-urls-in-c
std::string url_encode(const std::string &value) {
    std::ostringstream escaped;
    escaped.fill('0');
    escaped << std::hex;

    for (std::string::const_iterator i = value.begin(), n = value.end(); i != n; ++i) {
        std::string::value_type c = (*i);

        // Keep alphanumeric and other accepted characters intact
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            escaped << c;
            continue;
        }

        // Any other characters are percent-encoded
        escaped << std::uppercase;
        escaped << '%' << std::setw(2) << int((unsigned char) c);
        escaped << std::nouppercase;
    }

    return escaped.str();
}

void MetroSystem::createDotFile(std::ostream &os) {
    REQUIRE(properlyInitialized(), "Metrosimulation is not properly initialised.");
    std::stringstream stream;
    stream << "digraph system {" << std::endl;
    for (int i = 0; i < static_cast<int>(lines.size()); i++) {
        Line *l = lines[i];
        for (int j = 0; j < static_cast<int>(l->getTracks().size()); ++j) {
            Track *t = l->getTracks()[j];
            stream << t->getAnEnd()->getName() << "->" << t->getBegin()->getName() << ";" << std::endl;
            stream << t->getBegin()->getName()<< "->" <<  t->getAnEnd()->getName()<< ";" << std::endl;
        }
        for (int j = 0; j < static_cast<int>(l->getTrams().size()); ++j) {
            Tram *tram = l->getTrams()[j];
            stream << "tram" << tram->getTramNumber() << "->" << tram->getCurrentStation()->getName() << ";" << std::endl;
            stream << "tram" << tram->getTramNumber() << "[label=\"Tram " << tram->getTramNumber() << "\", color=blue, shape=box];" << std::endl;
        }
    }
    stream << "}" << std::endl;
    os << "https://dreampuf.github.io/GraphvizOnline/#" << url_encode(stream.str()) << std::endl;
    os << stream.str();
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

void MetroSystem::addStation(Station *newStation, const int &lineNumber) {
    REQUIRE(properlyInitialized(), "MetroSystem is not properly initialised.");
    std::vector<Station*>::iterator it1 = stations.begin();
    while (it1 != stations.end()) {
        Station *station = *it1;
        if (station->getName()==newStation->getName()) {
            delete newStation;
            newStation = station;
            break;
        }
        it1++;
    }

    std::vector<Line*>::iterator it = lines.begin();
    while (it != lines.end()) {
        Line* line = *it;
        if (line->getLineNumber()==lineNumber) {
            line->addStation(newStation);
            return;
        }
        it++;
    }
}

void MetroSystem::deployTram(Tram *newTram, const std::string &startStation, const int &lineNumber,std::ostream &errorStream) {
    REQUIRE(properlyInitialized(), "MetroSystem is not properly initialised.");
    std::vector<Line*>::iterator it = lines.begin();
    while (it != lines.end()) {
        Line* line = *it;
        if (line->getLineNumber()==lineNumber) {
            line->deployTram(newTram, startStation, errorStream);
            return;
        }
        it++;
    }
}

void MetroSystem::addConnection(const std::string &start, const std::string &end, const int &lineNumber,std::ostream &errorStream) {
    REQUIRE(properlyInitialized(), "MetroSystem is not properly initialised.");
    std::vector<Line*>::iterator it = lines.begin();
    while (it != lines.end()) {
        Line* line = *it;
        if (line->getLineNumber()==lineNumber) {
            line->connect(start, end, errorStream);
            return;
        }
        it++;
    }
}

void MetroSystem::verify(std::ostream &errorStream) {
    REQUIRE(properlyInitialized(), "MetroSystem is not properly initialised.");
    std::vector<Line*>::iterator it = lines.begin();
    while (it != lines.end()) {
        Line* line = *it;
        if (!line->verify(errorStream)) {
            lines.erase(it);
        }
        it++;
    }
}
