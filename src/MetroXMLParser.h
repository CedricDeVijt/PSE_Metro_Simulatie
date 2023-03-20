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
    /**
     * creates MetroXMLParser object
     *
     * @param filename is a .xml file that contains METRODATA
     * @param errorStream is the stream the errors get outputted to
     * @ENSURE properlyInitialized(), "constructor must end in properlyInitialized state"
     */
    explicit MetroXMLParser(const std::string &filename, std::ostream &errorStream);

    /**
     * Destructs MetroXMLParser object
     *
     * @REQUIRE properlyInitialized(), "MetroXMLParser was not initialized when calling parse"
     */
    virtual ~MetroXMLParser();

    bool properlyInitialized() const;

    /**
     * Parses the filename
     * \n Creates (Station + Tram) Objects who are not completely initialised
     * \n Creates 2 maps with content to init these objects completely
     *
     * @REQUIRE properlyInitialized(), "MetroXMLParser was not initialized when calling parse"
     * @param filename is Path to the file to be parsed, given as a string
     * @return @b bool: True if parsed properly, False if failed to parse
     */
    bool parse(const std::string& filename);

    /**
     * Returns properlyParser bool
     *
     * @REQUIRE properlyInitialized(), "MetroXMLParser was not initialized when calling handleStations"
     */
    bool isProperlyParsed() const;

    /**
     * Gets a vector with all the trams of the system
     *
     * @REQUIRE properlyInitialized(), "MetroXMLParser was not initialized when calling handleStations"
     * @return vector with all the trams
     */
    const std::vector<Tram *> &getTrams() const;

    /**
     * Gets a vector with all the stations of the system
     *
     * @REQUIRE properlyInitialized(), "MetroXMLParser was not initialized when calling handleStations"
     * @return vector with all the stations of the system
     */
    const std::vector<Station *> &getStations() const;

    /**
     * Gets a vector with all the lines of the system
     *
     * @REQUIRE properlyInitialized(), "MetroXMLParser was not initialized when calling handleStations"
     * @return a vector with all the stations of the system
     */
    const std::vector<Line *> &getLines() const;
private:
    /**
    * Verifies the content after completely parsing.
    *
    * @REQUIRE properlyInitialized(), "MetroXMLParser was not initialized when calling handleStations"
    * @return @b bool: returns True if its a valid MetroSystem, False if otherwise
    */
    bool verify();

    /**
     * Parses a single station from TiXmlElement \n
     * If there is a mistake an error gets written to the errorstream
     *
     * @REQUIRE properlyInitialized(), "MetroXMLParser was not initialized when calling parse"
     * @param stationElem tinyXML element that contains information about a station
     */
    void parseStation(TiXmlElement* stationElem);

    /**
     * Parses a single tram from TiXmlElement
     *
     * @REQUIRE properlyInitialized(), "MetroXMLParser was not initialized when calling parse"
     * @param tramElem tinyXML element that contains information about a tram
     */
    void parseTram(TiXmlElement* tramElem);

    /**
     * Initialises the stations completely
     *
     * @REQUIRE properlyInitialized(), "MetroXMLParser was not initialized when calling parse"
     * @attention parse() needs to be called before this should be called
     */
    void handleStations();

    /**
     * Initialises the trams completely
     *
     * @REQUIRE properlyInitialized(), "MetroXMLParser was not initialized when calling parse"
     * @attention parse() needs to be called before this should be called
     */
    void handleTrams();

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
