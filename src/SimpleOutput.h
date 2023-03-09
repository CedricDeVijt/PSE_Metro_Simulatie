#ifndef PSE_METRO_SIMULATIE_SIMPLEOUTPUT_H
#define PSE_METRO_SIMULATIE_SIMPLEOUTPUT_H

#include "MetroSimulation.h"

class SimpleOutput {
    SimpleOutput();

    void outputMetroSimulation(MetroSimulation simulation, std::ofstream stream);
};


#endif //PSE_METRO_SIMULATIE_SIMPLEOUTPUT_H
