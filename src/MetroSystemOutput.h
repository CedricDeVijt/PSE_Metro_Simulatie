#ifndef PSE_METRO_SIMULATIE_METROSYSTEMOUTPUT_H
#define PSE_METRO_SIMULATIE_METROSYSTEMOUTPUT_H

#include <sstream>
#include <sstream>
#include "MetroSystem.h"

class MetroSystemOutput {
public:
    /**
     * Writes a simple system output to the given output steam. The output consists of all the stations,
     * with all it's tracks and all the trams with their specifications.
     * @REQUIRE given metro-system has a map for a virtual metro network.
     * @param system metro-system that is used for the output.
     * @param os output stream the text is written to.
     */
    static void simpleSystemOutput(MetroSystem *system, std::ostream &os);

    /**
     * Writes an advanced system output to the given output steam. The output consists all the tracks and if there are
     * any trams at those stations.
     * @REQUIRE(properlyInitialized(), "Metrosimulation is not properly initialised.");
     * @param system metro-system that is used for the output.
     * @param os output stream the text is written to.
     */
    static void advancedSystemOutput(MetroSystem *system, std::ostream &os);
};


#endif //PSE_METRO_SIMULATIE_METROSYSTEMOUTPUT_H


