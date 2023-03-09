#include "MetroSimulation.h"
#include "MetroXMLParser.h"
#include "DesignByContract.h"
#include "Line.h"

MetroSimulation::MetroSimulation(const std::string& filename, unsigned int runtime) : runtime(runtime), time(0) {
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
