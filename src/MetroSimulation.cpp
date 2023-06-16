#include "MetroSimulation.h"
#include "MetroXMLParser.h"
#include "DesignByContract.h"
#include "Logger.h"
#include "MetroSystemOutput.h"
#include "MetroSimStatistics.h"


MetroSimulation::MetroSimulation(const std::string& inputfile, unsigned int runtime, bool createPng) : runtime(runtime), time(0), createPng(createPng), stoppedSystem(false) {
    _initCheck = this;
    system = new MetroSystem();
    MetroXMLParser::loadMetroSystem(*system, inputfile);
    ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
}

void MetroSimulation::run() {
    REQUIRE(properlyInitialized(), "Metrosimulation was not properly initialised.");
    stoppedSystem = false;
    while (time<runtime && not stoppedSystem) {
        if (createPng) {
            std::stringstream s;
            s << time;
            std::string timeStr = s.str();
            MetroSystemOutput::createDotOutput(*system, "time"+timeStr, ".png");
        }
        system->updateSystem();
        emitSimulationProgressed();
        updateTime();
    }
    if (createPng) {
        std::stringstream s;
        s << time;
        std::string timeStr = s.str();
        MetroSystemOutput::createDotOutput(*system, "time"+timeStr, ".png");
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
    REQUIRE(properlyInitialized(), "Metrosimulation was not properly initialised.");
    os << "System:\n";
    MetroSystemOutput::simpleSystemOutput(*system, os);

    os << "Stats:\n";
    MetroSimStatistics stats(this);
    stats.printStats(os);
}

unsigned int MetroSimulation::getTime() const {
    REQUIRE(properlyInitialized(), "Metrosimulation was not properly initialised.");
    return time;
}

void MetroSimulation::stopSystem() {
    REQUIRE(properlyInitialized(), "Metrosimulation was not properly initialised.");

    stoppedSystem = true;

    ENSURE(stoppedSystem, "Failed to stop system");
}

void MetroSimulation::updateTime() {
    REQUIRE(properlyInitialized(), "Metrosimulation was not properly initialised.");

    unsigned int timeBefore = time;
    time++;

    ENSURE(timeBefore+1==time, "Failed to increment time");
}

void MetroSimulation::emitSimulationProgressed() {
    REQUIRE(properlyInitialized(), "Metrosimulation was not properly initialised.");
}

