#ifndef PSE_METRO_SIMULATIE_XMLPARSER_H
#define PSE_METRO_SIMULATIE_XMLPARSER_H
#include "string"
#include "vector"
#include "map"

class Tram;
class Station;
class Line;

class MetroXMLParser {
public:
    MetroXMLParser();

    explicit MetroXMLParser(const std::string &filename);
    virtual ~MetroXMLParser();

    bool parse();

    const std::vector<Tram *> &getTrams() const;
    const std::vector<Station *> &getStations() const;
    const std::vector<Line *> &getLines() const;

    void handleStations();
    void handleTrams();
    void verify();
    bool isProperlyInitialized() const;
    bool isProperlyParsed() const;
private:
    std::vector<Tram*> trams;
    std::vector<Station*> stations;
    std::vector<Line*> lines;
    std::string filename;

    bool properlyInitialized;
    bool properlyParsed;
    bool isVerified;

    std::map<Station*, std::pair<std::string, std::string> > stationMap;
    std::map<Tram*, std::string> tramMap;
};

#endif //PSE_METRO_SIMULATIE_XMLPARSER_H
