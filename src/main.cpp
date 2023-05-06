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
    std::string filename = "simAdvanced";

    MetroSimulation sim(INPUTPATH+filename+".xml", std::cerr,10, true);
    sim.run(std::cout);
    std::cout << std::endl;
    sim.evaluate(std::cout);

    MetroSystemOutput::advancedSystemOutput(sim.getSystem(), std::cout);

    MetroRenderer::createIni(sim.getSystem(),std::cout);
}