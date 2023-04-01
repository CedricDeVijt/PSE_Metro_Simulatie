#ifndef PSE_METRO_SIMULATIE_METROSYSTEMOUTPUT_H
#define PSE_METRO_SIMULATIE_METROSYSTEMOUTPUT_H

#include <sstream>
#include <sstream>
#include "MetroSystem.h"

class MetroSystemOutput {
public:
    MetroSystemOutput();

    void outputMetroSystem(MetroSystem *system, std::ostream &os);
};


#endif //PSE_METRO_SIMULATIE_METROSYSTEMOUTPUT_H
