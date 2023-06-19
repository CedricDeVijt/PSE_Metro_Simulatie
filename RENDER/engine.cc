#include "MetroRenderer.h"
#include "../src/MetroXMLParser.h"
#include "../src/MetroSimulation.h"
#include "../src/MetroSystemOutput.h"

const std::string INPUTPATH = "./xmlFiles/sims/input/";
const std::string OUTPUTPATH = "./xmlFiles/sims/output/";

int main()
{
    MetroSimulation sim(INPUTPATH+"simFile.xml",10, false);
    MetroRenderer::renderSystem(*sim.getSystem(), "test");
}
