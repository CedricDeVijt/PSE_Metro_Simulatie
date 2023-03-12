#include "MetroSimulation.h"
#include "iostream"

int main() {
    std::string FOLDERPATH = "./xmlFiles/sims/";
    MetroSimulation sim(FOLDERPATH+"simFile.xml", 10);
//    sim.outputMetroSimulation(std::cout);
    sim.start(std::cout);
}
