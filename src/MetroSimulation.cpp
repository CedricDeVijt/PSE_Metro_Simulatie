#include "MetroSimulation.h"
#include "MetroXMLParser.h"
#include "DesignByContract.h"
#include "Logger.h"

MetroSimulation::MetroSimulation(const std::string& inputfile, std::ostream &errorstream, unsigned int runtime) : runtime(runtime), time(0) {
    _initCheck = this;
    system = new MetroSystem(inputfile, errorstream);

    ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
}



void MetroSimulation::run(std::ostream &os) {
    REQUIRE(properlyInitialized(), "Metrosimulation was not properly initialised.");
    while (time<runtime) {
        system->updateSystem(os);
        time++;
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




