#include "MetroSimulation.h"
#include "MetroXMLParser.h"
#include "DesignByContract.h"
#include "Line.h"

MetroSimulation::MetroSimulation(const std::string& filename) {
    MetroXMLParser parser(filename);
    if (parser.isProperlyInitialized() && parser.isProperlyParsed()) {
        lines = parser.getLines();
        properlyInitialized = true;
    } else {
        properlyInitialized = false;
    }
}

bool MetroSimulation::isProperlyInitialized() const { return properlyInitialized; }

void MetroSimulation::start(std::ostream &os) {
    REQUIRE(properlyInitialized, "Metrosimulation was not properly initialised.");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < static_cast<int>(lines.size()); ++j) {
            lines[j]->update(os);
        }
    }
}
