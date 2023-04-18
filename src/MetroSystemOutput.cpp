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

