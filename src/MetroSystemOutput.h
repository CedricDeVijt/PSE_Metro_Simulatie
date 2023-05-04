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

    /**
     * Creates DOT file of the current metro-system
     *
     * @param system metro-system that is used for the output.
     * @param os is the outputstream where the current metroSystem gets written to
     * @outputs - URL to the visualizer with the DOT file loaded in \n
     *          - DOT file format
     */
    static void createDotFile(MetroSystem *system, std::ostream &os);

    /**
     * Outputs the dot file output to a given file type, and a filename
     *
     * @param system is the system the dot needs to get created to
     * @param filename is the name of the file
     * @param outputType is the type of the file: .svg or .dot
     */
    static void createDotOutput(MetroSystem *system, const std::string &filename, const std::string &outputType);
};


#endif //PSE_METRO_SIMULATIE_METROSYSTEMOUTPUT_H


