#include "MetroSystem.h"

MetroSystem::MetroSystem(const std::string &inputFile, std::ostream &errorstream) : errorstream(errorstream) {
        _initCheck = this;
        MetroXMLParser parser(inputFile, errorstream);
        if (parser.isProperlyParsed()) {
            lines = parser.getLines();
            stations = parser.getStations();
            trams = parser.getTrams();
        } else {
            Logger::writeError(errorstream,"File was not parsed properly");
        }

        ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
        ENSURE(parser.isProperlyParsed(), "File was not parsed properly");
}

bool MetroSystem::properlyInitialized() const {
    return _initCheck==this;
}


void MetroSystem::updateSystem(std::ostream &os) {
    REQUIRE(properlyInitialized(), "Metrosimulation is not properly initialised.");
    for (int j = 0; j < static_cast<int>(lines.size()); ++j) {
        lines[j]->update(os);
    }
}

void MetroSystem::outputMetroSystem(std::ostream &stream) {
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
