#include "MetroSimulation.h"
#include "MetroXMLParser.h"

MetroSimulation::MetroSimulation(const std::string& filename) {
    MetroXMLParser parser(filename);
    trams = parser.getTrams();
    stations = parser.getStations();
}
