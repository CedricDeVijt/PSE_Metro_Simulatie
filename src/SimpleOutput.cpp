//
// Created by Cedric De Vijt on 09/03/2023.
//

#include <fstream>
#include "SimpleOutput.h"
#include "Station.h"
#include "Tram.h"

void SimpleOutput::outputMetroSimulation(MetroSimulation simulation, std::ofstream stream) {
    std::vector<Station *> stations = simulation.getStations();
    std::vector<Tram *> trams = simulation.getTrams();

    // Stations
    for (int i = 0; i < stations.size(); ++i) {
        stream << std::string(*stations[i]) << std::endl;
    }

    for (int i = 0; i < trams.size(); ++i) {
        stream << std::string(*trams[i]) << std::endl;
    }
}
