#include "MetroSimulation.h"
#include "MetroXMLParser.h"
#include "DesignByContract.h"
#include "Logger.h"
#include "MetroSystemOutput.h"
#include "MetroSimStatistics.h"

MetroSimulation::MetroSimulation(const std::string& inputfile, std::ostream &errorstream, unsigned int runtime, bool createPng) : runtime(runtime), time(0), createPng(createPng) {
    _initCheck = this;
    system = new MetroSystem();
    MetroXMLParser::loadMetroSystem(*system, inputfile, errorstream);
    ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
}

void MetroSimulation::run(std::ostream &os) {
    REQUIRE(properlyInitialized(), "Metrosimulation was not properly initialised.");

    while (time<runtime) {
        if (createPng) {
            std::stringstream s;
            s << time;
            std::string timeStr = s.str();
            MetroSystemOutput::createDotPng(system, "time"+timeStr);
        }
        system->updateSystem(os);
        time++;
    }
    if (createPng) {
        std::stringstream s;
        s << time;
        std::string timeStr = s.str();
        MetroSystemOutput::createDotPng(system, "time"+timeStr);
    }
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
    os << "System:\n";
    MetroSystemOutput::simpleSystemOutput(system, os);

    os << "Stats:\n";
    MetroSimStatistics stats(this);
    stats.printStats(os);
}

unsigned int MetroSimulation::getTime() const {
    return time;
}




