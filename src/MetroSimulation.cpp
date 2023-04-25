#include "MetroSimulation.h"
#include "MetroXMLParser.h"
#include "DesignByContract.h"
#include "Logger.h"
#include "MetroSystemOutput.h"

MetroSimulation::MetroSimulation(const std::string& inputfile, std::ostream &errorstream, unsigned int runtime) : runtime(runtime), time(0) {
    _initCheck = this;
    system = new MetroSystem();
    MetroXMLParser::loadMetroSystem(*system, inputfile, errorstream);
    ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
}

void MetroSimulation::run(std::ostream &os) {
    REQUIRE(properlyInitialized(), "Metrosimulation was not properly initialised.");

    while (time<runtime) {
//        std::string timeStr = std::string(1,'0'+time);
//        MetroSystemOutput::createDotPng(system, "time"+timeStr);
//        os << "time: " + timeStr << std::endl;
        system->updateSystem(os);
        time++;
    }
//    std::string timeStr = std::string(1,'0'+time);
//    MetroSystemOutput::createDotPng(system, "time"+timeStr);
}

bool MetroSimulation::properlyInitialized() const {
    return _initCheck==this;
}

MetroSystem *MetroSimulation::getSystem() const {
    REQUIRE(properlyInitialized(), "Metrosimulation was not properly initialised.");
    return system;
}

MetroSimulation::~MetroSimulation() {
    REQUIRE(properlyInitialized(), "Metrosimulation was not properly initialised.");
    delete system;
}

void MetroSimulation::evaluate(std::ostream &os) {
    std::cout << "System:\n";
    MetroSystemOutput::simpleSystemOutput(system, os);

    std::vector<Line*> lines = system->getLines();
    std::vector<Line*>::iterator it = lines.begin();
    int totalcost = 0;
    while (it!=lines.end()) {
        std::vector<Tram*> trams = (*it)->getTrams();
        std::vector<Tram*>::iterator tramIt = trams.begin();
        while (tramIt!=trams.end()) {
            totalcost += (*tramIt)->getTotalCost();
            tramIt++;
        }
        it++;
    }
    std::cout << "Total Cost: " << totalcost << " euro\n";
}




