#ifndef PSE_METRO_SIMULATIE_XMLPARSER_H
#define PSE_METRO_SIMULATIE_XMLPARSER_H

#include "string"
#include "vector"
#include "map"
#include "ostream"
#include "../tinyxml/tinyxml.h"
#include "Tram.h"
#include "TramStop.h"
#include "Line.h"
#include "fstream"
#include "DesignByContract.h"
#include "Logger.h"
#include "MetroSystem.h"

/**
 * Static Parser for MetroSimulation
 */
class MetroXMLParser {
public:
    /**
     * Parses a XML file containing data corresponding with the contract \n
     *
     * @param system is the MetroSystem the data needs to get added to
     * @param filename is the path to a .xml file with the data
     * @param errorStream is the stream errors get output to
     */
    static void loadMetroSystem(MetroSystem &system, const std::string &filename, std::ostream &errorStream);
private:
    /**
     * Parses a single TramStop from TiXmlElement \n
     * If data is consistent it gets added to the MetroSystem otherwise errors get written to errorStream
     *
     * @param system is the MetroSystem the data needs to get added to
     * @param stationElem tinyXML element that contains information about a station
     * @param errorStream is the stream errors get output to
     */
    static void parseStation(MetroSystem &system, TiXmlElement* stationElem, std::ostream &errorStream);
    /**
     * Parses a single tram from TiXmlElement \n
     * If data is consistent it gets added to the MetroSystem otherwise errors get written to errorStream
     *
     * @param system is the MetroSystem the data needs to get added to
     * @param tramElem tinyXML element that contains information about a tram
     * @param errorStream is the stream errors get output to
     */
    static void parseTram(MetroSystem &system, TiXmlElement* tramElem, std::ostream &errorStream);
    /**
     * Parses a connection from a TramStop TiXmlElement \n
     * If data is consistent it gets added to the MetroSystem otherwise errors get written to errorStream
     *
     * @param system is the MetroSystem the data needs to get added to
     * @param stationElem tinyXML element that contains information about a station
     * @param errorStream is the stream errors get output to
     */
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
    static std::pair<std::string, bool> readKey(const TiXmlElement* elem, const std::string &key, std::ostream &errorStream);
};

#endif //PSE_METRO_SIMULATIE_XMLPARSER_H
