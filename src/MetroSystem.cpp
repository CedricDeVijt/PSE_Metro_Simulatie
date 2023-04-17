#include <sstream>
#include <iomanip>
#include "MetroSystem.h"

MetroSystem::MetroSystem() : consistent(true) {
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

    for (std::vector<Line*>::iterator it = lines.begin(); it != lines.end(); it++){
        os << std::string(*(*it));
    }

//    std::vector<Line*>::iterator it = lines.begin();
//    while (it!=lines.end()) {
//        os << std::string(*(*it));
//        it++;
//    }

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

    std::vector<std::string> colors;
    colors.push_back("red");
    colors.push_back("green");
    colors.push_back("blue");
    colors.push_back("yellow");
    stream << "digraph system {" << std::endl;
    for (int i = 0; i < static_cast<int>(lines.size()); i++) {
        Line *l = lines[i];
        for (int j = 0; j < static_cast<int>(l->getTracks().size()); ++j) {
            Track *t = l->getTracks()[j];
            stream << t->getAnEnd()->getName() << "->" << t->getBegin()->getName() << " [color=" << colors[i] << "];\n";
            stream << t->getBegin()->getName()<< "->" <<  t->getAnEnd()->getName() << " [color=" << colors[i] << "];\n";
        }
        for (int j = 0; j < static_cast<int>(l->getTrams().size()); ++j) {
            Tram *tram = l->getTrams()[j];
            stream << "tram" << tram->getTramNumber() << "->" << tram->getCurrentStation()->getName() << ";\n";
            stream << "tram" << tram->getTramNumber() << "[label=\"Tram " << tram->getTramNumber() << "\", color=" << colors[i] << ", shape=box];\n";
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

void MetroSystem::addStation(TramStop *newStation, const int &lineNumber, std::ostream &errorStream) {
    REQUIRE(properlyInitialized(), "MetroSystem is not properly initialised.");
    //Dont make a new Pointer if a Statoin with this name exists
    std::vector<TramStop*>::iterator it1 = stations.begin();
    while (it1 != stations.end()) {
        TramStop *station = *it1;
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
    Logger::writeError(errorStream, "addStation: Line not found, station not added");
}

void MetroSystem::deployTram(Tram *newTram, const std::string &startStation, const int &lineNumber,std::ostream &errorStream) {
    REQUIRE(properlyInitialized(), "MetroSystem is not properly initialised.");
    //Check for double tramnumbers
    int newNumber = newTram->getTramNumber();
    std::vector<int>::iterator it1 = takenTramNumbers.begin();
    while (it1!=takenTramNumbers.end()) {
        if (*it1==newNumber) {
            Logger::writeError(errorStream, "Deploy Error: er zijn twee trams met hetzelfde voertuignummer");
            consistent = false;
            return;
        }
        it1++;
    }
    takenTramNumbers.push_back(newNumber);

    //Try to deploy tram at right TramStop*
    std::vector<Line*>::iterator it = lines.begin();
    while (it != lines.end()) {
        Line* line = *it;
        if (line->getLineNumber()==lineNumber) {
            line->deployTram(newTram, startStation, errorStream);
            return;
        }
        it++;
    }
    Logger::writeError(errorStream, "deployTram: Line Not found");
    Logger::writeError(errorStream, "deployTram: Niet elke tram heeft een lijn die overeenkomt met een spoor in zijn beginstation");
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
        consistent = consistent && line->verify(errorStream);
        it++;
    }
    if (!consistent) {
        Logger::writeError(errorStream, "Inconsistent Metronet");
    }
}

const std::vector<Line *> &MetroSystem::getLines() const {
    return lines;
}

const std::vector<TramStop *> &MetroSystem::getStations() const {
    return stations;
}
