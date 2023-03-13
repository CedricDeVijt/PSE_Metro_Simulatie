#ifndef PSE_METRO_SIMULATIE_XMLPARSER_H
#define PSE_METRO_SIMULATIE_XMLPARSER_H
#include "string"
#include "vector"
#include "map"

class Tram;
class Station;
class Line;

/**
 * Parser for MetroSimulation
 */
class MetroXMLParser {
public:
    //CONSTRUCT-DESTRUCT
    MetroXMLParser();
    explicit MetroXMLParser(const std::string &filename);
    virtual ~MetroXMLParser();

    /**
     * Parses the filename
     * Creates Objects who are not completely initialised
     * Creates 2 maps with content to init these objects completely
     *
     * @ENSURE LOAD FILE
     * @ENSURE LOAD CONTENT
     *
     * @param filename: Path to the file to be parsed, given as a string
     * @return bool: True if parsed properly, False if failed to parse
     */
    bool parse(const std::string& filename);

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
    void verify();

    //GETTERS
    bool isProperlyInitialized() const;
    bool isProperlyParsed() const;
    const std::vector<Tram *> &getTrams() const;
    const std::vector<Station *> &getStations() const;
    const std::vector<Line *> &getLines() const;
private:
    std::vector<Tram*> trams;
    std::vector<Station*> stations;
    std::vector<Line*> lines;

    bool properlyInitialized;
    bool properlyParsed;
    bool isVerified;

    std::map<Station*, std::pair<std::string, std::string> > stationMap;
    std::map<Tram*, std::string> tramMap;
};

#endif //PSE_METRO_SIMULATIE_XMLPARSER_H
