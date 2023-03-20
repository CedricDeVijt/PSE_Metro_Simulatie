#include "MetroSimulation.h"
#include "iostream"
#include "fstream"

const std::string INPUTPATH = "./xmlFiles/sims/input/";
const std::string OUTPUTPATH = "./xmlFiles/sims/output/";

int main() {
    std::string filename = "simFile2";

    std::ofstream file((OUTPUTPATH+filename+"log.txt").c_str());
    if (!file.is_open()) {
        std::cerr << "File did not open";
        return 1;
    }

    MetroSimulation sim(INPUTPATH+filename+".xml", file, 10);

    sim.getSystem()->outputSystem(std::cout);
    std::cout << std::endl;
    sim.run(std::cout);
    std::cout << std::endl;
    sim.getSystem()->createDotFile(std::cout);

    file.close();
}
