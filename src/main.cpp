#include "MetroSimulation.h"
#include "iostream"
#include "TramStop.h"
#include "MetroSystemOutput.h"
#include "MetroRenderer.h"
#include "MetroXMLParser.h"

const std::string INPUTPATH = "./xmlFiles/sims/input/";
const std::string OUTPUTPATH = "./xmlFiles/sims/output/";

void useCase1_1to1_4() {
    MetroSystem sys;
    MetroXMLParser::loadMetroSystem(sys, INPUTPATH+"simFile.xml", std::cerr);
}

void useCase2_2() {
    MetroSystem sys;
    MetroXMLParser::loadMetroSystem(sys, INPUTPATH+"simFile.xml", std::cerr);

    MetroSystemOutput::simpleSystemOutput(&sys, std::cout);
}

void useCase2_3() {
    MetroSystem sys;
    MetroXMLParser::loadMetroSystem(sys, INPUTPATH+"simFile.xml", std::cerr);

    MetroSystemOutput::advancedSystemOutput(&sys, std::cout);
}

void useCase2_4() {
    MetroSystem sys;
    MetroXMLParser::loadMetroSystem(sys, INPUTPATH+"simFile.xml", std::cerr);

    MetroRenderer::createIni(&sys, std::cout);
}

void useCase3_1to3_8() {
    MetroSimulation sim(INPUTPATH+"simFile.xml", std::cerr,10, false);

    sim.run(std::cout);
}

void useCase3_9() {
    MetroSimulation sim(INPUTPATH+"simFile.xml", std::cerr,10, false);

    std::stringstream ignoreStream;
    sim.run(ignoreStream);

    sim.evaluate(std::cout);
}

void extraUseCase_dot() {
    //Dot png files generated for every frame of the simulation
    MetroSimulation sim(INPUTPATH+"simFile.xml", std::cerr,10, true);

    sim.run(std::cout);

    std::cout << std::endl;

    MetroSystemOutput::createDotFile(sim.getSystem(), std::cout);
}

int main() {
//    useCase1_1to1_4();

//    useCase2_2();
//    useCase2_3();
//    useCase2_4();

//    useCase3_1to3_8();
//    useCase3_9();
//
//    extraUseCase_dot();
}