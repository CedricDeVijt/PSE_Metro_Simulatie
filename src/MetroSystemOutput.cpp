#include <iomanip>
#include "MetroSystemOutput.h"

void MetroSystemOutput::simpleSystemOutput(MetroSystem *system, std::ostream &os) {
    // Get stations
    std::vector<TramStop *> stations = system->getStations();
    std::vector<Line *> lines = system->getLines();

    os << "--== STATIONS ==--\n";
    // Loop over all stops
    for (std::vector<TramStop*>::iterator it = stations.begin(); it != stations.end(); ++it) {
        TramStop* stop = *it;
        os << "= "+ stop->getName() + " =\n";

        // Get all tracks
        for (std::vector<Line *>::iterator lineIt = lines.begin(); lineIt != lines.end(); ++lineIt){
            Line* line = *lineIt;
            if (line->getNext(stop) != NULL){
                os << "* Spoor " << line->getLineNumber() << ":\n";
                os << "    -> " + line->getNext(stop)->getName() + "\n";
                os << "    <- " + line->getPrev(stop)->getName() + "\n\n";
            }
        }
    }

    // Get Trams
    os << "--== TRAMS ==--\n";
    for (std::vector<Line *>::iterator lineIt = lines.begin(); lineIt != lines.end(); ++lineIt){
        Line* line = *lineIt;
        std::vector<Tram*> trams = line->getTrams();
        for (std::vector<Tram *>::iterator tramIt = trams.begin(); tramIt != trams.end(); ++tramIt){
            Tram* tram = *tramIt;
            os << "Tram " << line->getLineNumber() << " nr " << tram->getTramNumber() << "\n";


        }
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

void MetroSystemOutput::createDotFile(MetroSystem *system, std::ostream &os) {
    std::stringstream stream;

    std::vector<std::string> colors;
    colors.push_back("red");
    colors.push_back("green");
    colors.push_back("blue");
    colors.push_back("yellow");
    stream << "digraph system {" << std::endl;
    std::vector<Line*> lines = system->getLines();
    for (int i = 0; i < static_cast<int>(lines.size()); i++) {
        Line *l = lines[i];
        for (int j = 0; j < static_cast<int>(l->getTracks().size()); ++j) {
            Track *t = l->getTracks()[j];
            stream << t->getBegin()->getName() << "->" << t->getAnEnd()->getName() << " [color=" << colors[i] << "];\n";
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
