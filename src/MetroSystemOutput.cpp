#include "MetroSystemOutput.h"

MetroSystemOutput::MetroSystemOutput() {}

void MetroSystemOutput::outputMetroSystem(MetroSystem *system, std::ostream &os) {
    // Get stations
    std::vector<TramStop *> stations = system->getStations();

    os << "--== STATIONS ==--\n";

    for (std::vector<TramStop *>::iterator it = stations.begin(); it != stations.end(); it++){
        os << *it;
    }

    // Get Trams
    std::vector<Line*> lines = system->getLines();

    os << "--== TRAMS ==--\n";

    for (int i = 0; i < lines.size(); i++) {
        std::vector<Tram*> trams = lines[i]->getTrams();
        for (int j = 0; j < trams.size(); j++) {
            os << trams[j];
        }
    }
}

