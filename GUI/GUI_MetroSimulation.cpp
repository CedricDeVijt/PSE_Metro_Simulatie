#include "GUI_MetroSimulation.h"

void GUI_MetroSimulation::emitSimulationProgressed() {
    emit simulationProgressed();
}

GUI_MetroSimulation::GUI_MetroSimulation(const std::string &inputFile, std::ostream &errorstream, unsigned int runtime,
                                         bool createPng) : MetroSimulation(inputFile, errorstream, runtime, createPng) {

}
