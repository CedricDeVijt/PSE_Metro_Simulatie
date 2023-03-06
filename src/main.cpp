#include "MetroSimulation.h"
#include "iostream"

int main() {
    MetroSimulation sim("xmlFiles/test.xml");
    sim.start(std::cout);
}
