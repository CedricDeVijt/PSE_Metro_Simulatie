#include "MetroSimulation.h"
#include "iostream"
#include "fstream"

std::string INPUTPATH = "./xmlFiles/sims/input/";
std::string OUTPUTPATH = "./xmlFiles/sims/output/";

int main() {
    std::string filename = "simFile";

    std::ofstream file((OUTPUTPATH+filename+"log.txt").c_str());
    if (!file.is_open()) {
        std::cerr << "File did not open";
        return 1;
    }

    MetroSimulation sim(INPUTPATH+filename+".xml", std::cout, 10);

    sim.outputMetroSimulation(std::cout);
    std::cout << std::endl;
    sim.startSystem(std::cout);

    file.close();
}
