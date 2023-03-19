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

    MetroSimulation sim(INPUTPATH+filename+".xml", file, 10);

    sim.getSystem()->outputMetroSystem(std::cout);
    std::cout << std::endl;
    sim.run(std::cout);

    file.close();
}
