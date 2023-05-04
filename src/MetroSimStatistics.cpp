#include "MetroSimStatistics.h"

MetroSimStatistics::MetroSimStatistics(MetroSimulation *sim) : _initCheck(this) {
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
    ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
}

void MetroSimStatistics::printStats(std::ostream &os) const {
    REQUIRE(properlyInitialized(), "MetroSimStatistics was not properly initialised.");

    os << "Time: " << time << std::endl;
    os << "TotalCost: " << totalCost << std::endl;
    os << "#Working Trams: " << workingTrams << std::endl;
    os << "#Defect Trams: " << defectTrams << std::endl;
}

int MetroSimStatistics::getTime() const {
    REQUIRE(properlyInitialized(), "MetroSimStatistics was not properly initialised.");
    return time;
}
int MetroSimStatistics::getTotalCost() const {
    REQUIRE(properlyInitialized(), "MetroSimStatistics was not properly initialised.");
    return totalCost;
}
int MetroSimStatistics::getDefectTrams() const {
    REQUIRE(properlyInitialized(), "MetroSimStatistics was not properly initialised.");
    return defectTrams;
}
int MetroSimStatistics::getWorkingTrams() const {
    REQUIRE(properlyInitialized(), "MetroSimStatistics was not properly initialised.");
    return workingTrams;
}
bool MetroSimStatistics::properlyInitialized() const { return _initCheck == this; }
