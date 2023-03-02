#include "string"
#include "vector"
#ifndef PSE_METRO_SIMULATIE_XMLPARSER_H
#define PSE_METRO_SIMULATIE_XMLPARSER_H

class Tram;
class Station;

class MetroXMLParser {
public:
    explicit MetroXMLParser(const std::string &filename);
    virtual ~MetroXMLParser();

    bool parse();

    const std::vector<Tram *> &getTrams() const;
    const std::vector<Station *> &getStations() const;
private:
    std::vector<Tram*> trams;
    std::vector<Station*> stations;
    std::string filename;
};

#endif //PSE_METRO_SIMULATIE_XMLPARSER_H
