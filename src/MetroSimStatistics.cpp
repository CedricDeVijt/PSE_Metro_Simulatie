#include "MetroSimStatistics.h"

MetroSimStatistics::MetroSimStatistics(MetroSimulation *sim){
    MetroSystem *system = sim->getSystem();

    time = sim->getTime();

    totalCost = 0;
    workingTrams = 0;
    defectTrams = 0;

    std::vector<Line*> lines = system->getLines();
    std::vector<Line*>::iterator it = lines.begin();
    while (it!=lines.end()) {
        std::vector<Tram*> trams = (*it)->getTrams();
        std::vector<Tram*>::iterator tramIt = trams.begin();
        while (tramIt!=trams.end()) {
            Tram *tram = *tramIt;
            totalCost += tram->getTotalCost();
            workingTrams += (tram->isDefect()) ? 0 : 1;
            defectTrams += (tram->isDefect()) ? 1 : 0;
            tramIt++;
        }
        it++;
    }
}

void MetroSimStatistics::printStats(std::ostream &os) const {
    os << "Time: " << time << std::endl;
    os << "TotalCost: " << totalCost << std::endl;
    os << "#Working Trams: " << workingTrams << std::endl;
    os << "#Defect Trams: " << defectTrams << std::endl;
}

int MetroSimStatistics::getTime() const { return time;}
int MetroSimStatistics::getTotalCost() const { return totalCost;}
int MetroSimStatistics::getDefectTrams() const { return defectTrams;}
int MetroSimStatistics::getWorkingTrams() const { return workingTrams;}