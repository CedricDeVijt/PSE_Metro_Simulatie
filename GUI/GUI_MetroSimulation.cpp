#include "GUI_MetroSimulation.h"

void GUI_MetroSimulation::emitSimulationProgressed() {
    emit simulationProgressed();
}

GUI_MetroSimulation::GUI_MetroSimulation(const std::string &inputFile, std::ostringstream* errorstream, unsigned int runtime,
                                         bool createPng) : MetroSimulation(inputFile, runtime, createPng) {

}
