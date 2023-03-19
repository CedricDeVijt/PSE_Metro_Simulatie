#include <sstream>
#include <iomanip>
#include "MetroSystem.h"

MetroSystem::MetroSystem(const std::string &inputFile, std::ostream &errorstream) : errorstream(errorstream) {
        _initCheck = this;
        MetroXMLParser parser(inputFile, errorstream);
        if (parser.isProperlyParsed()) {
            lines = parser.getLines();
            stations = parser.getStations();
            trams = parser.getTrams();
        } else {
            Logger::writeError(errorstream,"File was not parsed properly");
        }

        ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
        ENSURE(parser.isProperlyParsed(), "File was not parsed properly");
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

void MetroSystem::outputSystem(std::ostream &stream) {
    REQUIRE(properlyInitialized(), "Metrosimulation was not properly initialised.");
    // Stations
    for (int i = 0; i < static_cast<int>(stations.size()); i++) {
        stream << std::string(*stations[i]) << std::endl;
    }

    // Trams
    for (int i = 0; i < static_cast<int>(trams.size()); i++) {
        stream << std::string(*trams[i]) << std::endl;
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

void MetroSystem::createDotFile(std::ostream &ostream) {
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
    ostream << "https://dreampuf.github.io/GraphvizOnline/#" << url_encode(stream.str()) << std::endl;
    ostream << stream.str();
}