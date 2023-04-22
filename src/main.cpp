#include "MetroSimulation.h"
#include "iostream"
#include "fstream"
#include "TramStop.h"
#include "MetroSystemOutput.h"
#include "MetroRenderer.h"
#include "MetroXMLParser.h"

const std::string INPUTPATH = "./xmlFiles/sims/input/";
const std::string OUTPUTPATH = "./xmlFiles/sims/output/";

int main() {
    std::string filename = "simFile";

    MetroSystem sys;
    MetroSimulation sim(INPUTPATH+filename+".xml", std::cerr,10);
    MetroSystemOutput::simpleSystemOutput(sim.getSystem(),std::cout);
}