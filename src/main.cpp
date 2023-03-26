#include "MetroSimulation.h"
#include "MetroXMLParser.h"
#include "iostream"
#include "fstream"
#include "set"
#include "Station.h"

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
    sim.run(std::cout);
    sim.getSystem()->createDotFile(std::cout);
    file.close();
}
