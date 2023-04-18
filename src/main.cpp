#include "MetroSimulation.h"
#include "iostream"
#include "fstream"
#include "TramStop.h"
#include "MetroSystemOutput.h"

const std::string INPUTPATH = "./xmlFiles/sims/input/";
const std::string OUTPUTPATH = "./xmlFiles/sims/output/";

int main() {
    std::string filename = "simFile";

    std::ofstream file((OUTPUTPATH+filename+"log.txt").c_str());
    if (!file.is_open()) {
        std::cerr << "File did not open";
        return 1;
    }

    MetroSimulation sim(INPUTPATH+filename+".xml", file, 10);

    MetroSystemOutput::createDotFile(sim.getSystem(), std::cout);
    file.close();
}