#include "MetroSimulation.h"
#include "MetroXMLParser.h"
#include "DesignByContract.h"
#include "Line.h"
#include "Station.h"
#include "Tram.h"

MetroSimulation::MetroSimulation(const std::string& filename, unsigned int runtime) : runtime(runtime), time(0) {
    MetroXMLParser parser(filename);
    if (parser.isProperlyInitialized() && parser.isProperlyParsed()) {
        lines = parser.getLines();
        stations = parser.getStations();
        trams = parser.getTrams();
        properlyInitialized = true;
    } else {
        properlyInitialized = false;
    }
}

const std::vector<Station *> &MetroSimulation::getStations() const {
    return stations;
}

const std::vector<Tram *> &MetroSimulation::getTrams() const {
    return trams;
}

bool MetroSimulation::isProperlyInitialized() const { return properlyInitialized; }

void MetroSimulation::start(std::ostream &os) {
    REQUIRE(properlyInitialized, "Metrosimulation was not properly initialised.");
    while (time<runtime) {
        update(os);
        time++;
    }
}

void MetroSimulation::update(std::ostream &os) {
    for (int j = 0; j < static_cast<int>(lines.size()); ++j) {
        lines[j]->update(os);
    }
}

void MetroSimulation::outputMetroSimulation(std::ostream &stream) {
    // Stations
    for (int i = 0; i < static_cast<int>(stations.size()); i++) {
        stream << std::string(*stations[i]) << std::endl;
    }

    for (int i = 0; i < static_cast<int>(trams.size()); i++) {
        stream << std::string(*trams[i]) << std::endl;
    }
}
