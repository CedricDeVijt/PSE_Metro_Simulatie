#include "MetroSystemOutput.h"
#include <typeinfo>

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
            os << "    type: " << typeid(tram).name() << "\n";
            os << "    snelheid: " << tram->getSpeed() << "\n";
            os << "    huidig station: " << tram->getCurrentStation()->getName() << "\n";
            os << "    reparatiekosten: " << tram->getRepairCost() << "euro\n\n";
        }
    }
}

void MetroSystemOutput::advancedSystemOutput(MetroSystem *system, std::ostream &os) {
    std::vector<Line *> lines = system->getLines();
    std::vector<TramStop *> stations = system->getStations();

    for (std::vector<Line *>::iterator lineIt = lines.begin(); lineIt != lines.end(); ++lineIt){
        Line* line = *lineIt;

        // Find a station to set as start for line
        TramStop *startStation = NULL;
        for (std::vector<TramStop*>::iterator it = stations.begin(); it != stations.end(); ++it) {
            TramStop* stop = line->getNext(*it);
            if (stop != NULL){
                startStation = stop;
                break;
            }
        }

        // Output track
        TramStop* currentStation = startStation;
        os << "=" << currentStation->getName();
        currentStation = line->getNext(currentStation);
        while (currentStation != startStation){
            os << "===" << currentStation->getName();
        }
        os << "=\n";

        // Output trams in stations
        std::vector<Tram*> trams = line->getTrams();
        currentStation = startStation;
        os << " ";
        currentStation = line->getNext(currentStation);
        while (currentStation != startStation){
            for (std::vector<Tram *>::iterator tramIt = trams.begin(); tramIt != trams.end(); ++tramIt){
                Tram* tram = *tramIt;
                if (tram->getCurrentStation() == currentStation){
                    os << "T   ";
                } else {
                    os << "    ";
                }
            }
        }
        os << " \n\n";
    }
}

