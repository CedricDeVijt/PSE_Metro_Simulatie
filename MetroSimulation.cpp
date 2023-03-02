#include "MetroSimulation.h"
#include "MetroXMLParser.h"
#include "DesignByContract.h"

MetroSimulation::MetroSimulation(const std::string& filename) {
    MetroXMLParser parser(filename);
    if (parser.isProperlyInitialized() && parser.isProperlyParsed()) {
        trams = parser.getTrams();
        stations = parser.getStations();
        properlyInitialized = true;
    } else {
        properlyInitialized = false;
    }
}
