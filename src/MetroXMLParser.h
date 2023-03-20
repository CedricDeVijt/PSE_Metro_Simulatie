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

/**
 * Parser for MetroSimulation
 */
class MetroXMLParser {
public:
    // Constructor
    explicit MetroXMLParser(const std::string &filename, std::ostream &errorStream);
    // Destructor
    virtual ~MetroXMLParser();

    /**
     * Parses the filename
     * \n Creates Objects who are not completely initialised
     * \n Creates 2 maps with content to init these objects completely
     *
     * @REQUIRE properlyInitialized(), "MetroXMLParser was not initialized when calling parse"
     * @param filename is Path to the file to be parsed, given as a string
     * @return @b bool: True if parsed properly, False if failed to parse
     */
    bool parse(const std::string& filename);

    /**
     * Parses a single station form TiXmlElement
     * @REQUIRE properlyInitialized(), "MetroXMLParser was not initialized when calling parse"
     * @param stationElem tinyXML element that contains information about a station
     */
    void parseStation(TiXmlElement* stationElem);

    /**
     * Parses a single tram form TiXmlElement
     * @REQUIRE properlyInitialized(), "MetroXMLParser was not initialized when calling parse"
     * @param tramElem tinyXML element that contains information about a tram
     */
    void parseTram(TiXmlElement* tramElem);

    /**
     * Initialises the stations completely
     *
     * @REQUIRE THERE ARE STATIONS
     * @REQUIRE STATION MAP NOT EMPTY
     *
     * @attention parse() needs to be called before this should be called
     */
    void handleStations();

    /**
     * Initialises the trams completely
     *
     * @REQUIRE THERE ARE TRAMS
     * @REQUIRE TRAM MAP NOT EMPTY
     *
     * @attention parse() needs to be called before this should be called
     */
    void handleTrams();

    /**
     * Verifies the content after completely parsing.
     *
     * @ENSURE STATIONS CONNECTED PROPERLY
     * @ENSURE VALID STARTSTATION OF TRAM
     * @ENSURE CORRESPONDING LINENUMBER BETWEEN TRAM AND STARTSTATION
     * @ENSURE EVERY LINE HAS A TRAM
     */
    bool verify();

    bool isProperlyParsed() const;
    bool properlyInitialized() const;

    const std::vector<Tram *> &getTrams() const;
    const std::vector<Station *> &getStations() const;
    const std::vector<Line *> &getLines() const;
private:
    std::pair<std::string, bool> readKey(TiXmlElement* elem, const std::string &key);

    bool properlyParsed;
    MetroXMLParser *_initCheck;
    std::ostream &errorstream;
    std::vector<Tram*> trams;
    std::vector<Station*> stations;
    std::vector<Line*> lines;
    std::map<Station*, std::pair<std::string, std::string> > stationMap;
    std::map<Tram*, std::string> tramMap;
};

#endif //PSE_METRO_SIMULATIE_XMLPARSER_H
