#ifndef PSE_METRO_SIMULATIE_XMLPARSER_H
#define PSE_METRO_SIMULATIE_XMLPARSER_H

#include "string"
#include "vector"
#include "map"
#include "ostream"
#include "../tinyxml/tinyxml.h"
#include "Tram.h"
#include "Station.h"
#include "Line.h"
#include "fstream"
#include "DesignByContract.h"
#include "Logger.h"
#include "MetroSystem.h"

/**
 * Parser for MetroSimulation
 */
class MetroXMLParser {
public:
    static void loadMetroSystem(MetroSystem &system, const std::string &filename, std::ostream &errorStream);
private:
    /**
     * Parses a single station from TiXmlElement \n
     * If there is a mistake an error gets written to the errorstream
     *
     * @REQUIRE properlyInitialized(), "MetroXMLParser was not initialized when calling parse"
     * @param stationElem tinyXML element that contains information about a station
     */
    static void parseStation(MetroSystem &system, TiXmlElement* stationElem, std::ostream &errorStream);

    /**
     * Parses a single tram from TiXmlElement
     *
     * @REQUIRE properlyInitialized(), "MetroXMLParser was not initialized when calling parse"
     * @param tramElem tinyXML element that contains information about a tram
     */
    static void parseTram(MetroSystem &system, TiXmlElement* tramElem, std::ostream &errorStream);

    static void parseConnection(MetroSystem &system, TiXmlElement* stationElem, std::ostream &errorStream);

    /**
     * Reads the given key from the TiXmlElement \n
     * If the demanded key is missing an error gets written to the errostream
     *
     * @param elem is the TiXmlElement containing the demanded key
     * @param key is the demanded key
     * @return @b pair(string,bool): \n
     * @b string: containing the result of the key retrieve \n
     * @b bool: True if key retrieve is done, else False
     */
    static std::pair<std::string, bool> readKey(TiXmlElement* elem, const std::string &key, std::ostream &errorStream);
};

#endif //PSE_METRO_SIMULATIE_XMLPARSER_H
