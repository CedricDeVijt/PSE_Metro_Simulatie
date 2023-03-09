#include "MetroSimulation.h"
#include "iostream"

int main() {
    MetroSimulation sim("xmlFiles/simFile.xml", 6);

    sim.outputMetroSimulation(std::cout);

    sim.start(std::cout);

}
