#include "MetroSimulation.h"
#include "MetroXMLParser.h"
#include "DesignByContract.h"
#include "Logger.h"

MetroSimulation::MetroSimulation(const std::string& inputfile, std::ostream &errorstream, unsigned int runtime) : runtime(runtime), time(0), errorstream(errorstream) {
    _initCheck = this;
    MetroXMLParser parser(inputfile, errorstream);
    if (parser.isProperlyParsed()) {
        lines = parser.getLines();
        stations = parser.getStations();
        trams = parser.getTrams();
    } else {
        Logger::writeError(errorstream,"File was not parsed properly");
    }

    ENSURE(properlyInitialized(), "\"constructor must end in properlyInitialized state");
    ENSURE(parser.isProperlyParsed(), "File was not parsed properly");
}

const std::vector<Station *> &MetroSimulation::getStations() const {
    REQUIRE(properlyInitialized(), "Metrosimulation was not properly initialised.");
    return stations;
}

const std::vector<Tram *> &MetroSimulation::getTrams() const {
    REQUIRE(properlyInitialized(), "Metrosimulation was not properly initialised.");
    return trams;
}

void MetroSimulation::start(std::ostream &os) {
    REQUIRE(properlyInitialized(), "Metrosimulation was not properly initialised.");
    while (time<runtime) {
        update(os);
        time++;
    }
}

void MetroSimulation::update(std::ostream &os) {
    REQUIRE(properlyInitialized(), "Metrosimulation is not properly initialised.");
    for (int j = 0; j < static_cast<int>(lines.size()); ++j) {
        lines[j]->update(os);
    }
}

void MetroSimulation::outputMetroSimulation(std::ostream &stream) {
    REQUIRE(properlyInitialized(), "Metrosimulation was not properly initialised.");
    // Stations
    for (int i = 0; i < static_cast<int>(stations.size()); i++) {
        stream << std::string(*stations[i]) << std::endl;
    }

    // Trams
    for (int i = 0; i < static_cast<int>(trams.size()); i++) {
        stream << std::string(*trams[i]) << std::endl;
    }
}

bool MetroSimulation::properlyInitialized() const{
    return _initCheck == this;
}
