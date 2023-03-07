#include "MetroSimulation.h"
#include "iostream"

int main() {
    MetroSimulation sim("xmlFiles/simFile.xml");
    sim.start(std::cout);
}
