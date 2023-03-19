#include "MetroSimulation.h"
#include "MetroXMLParser.h"
#include "DesignByContract.h"
#include "Line.h"
#include "Station.h"
#include "Tram.h"

MetroSimulation::MetroSimulation(const std::string& filename, std::ostream *logstream, unsigned int runtime) : runtime(runtime), time(0) {
    _initCheck = this;
    logger = new Logger(logstream);
    MetroXMLParser parser(logger, filename);
    if (parser.isProperlyParsed()) {
        lines = parser.getLines();
        stations = parser.getStations();
        trams = parser.getTrams();
    } else {
        logger->error("File was not parsed properly");
    }

    ENSURE(properlyInitialized(), "Metrosimulation was not initialized properly");
    ENSURE(parser.isProperlyParsed(), "File was not parsed properly");
}

const std::vector<Station *> &MetroSimulation::getStations() const {
    return stations;
}

const std::vector<Tram *> &MetroSimulation::getTrams() const {
    return trams;
}

void MetroSimulation::startSystem(std::ostream &os) {
    REQUIRE(properlyInitialized(), "Metrosimulation was not properly initialised.");
    while (time<runtime) {
        updateSystem(os);
        time++;
    }
}

void MetroSimulation::updateSystem(std::ostream &os) {
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
