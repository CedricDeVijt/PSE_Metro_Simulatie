#ifndef PSE_METRO_SIMULATIE_LINE_H
#define PSE_METRO_SIMULATIE_LINE_H
#include "vector"

class Track;
class Tram;

class Line {
public:
    explicit Line(int lineNumber);

    const std::vector<Track *> &getTracks() const;

    const std::vector<Tram *> &getTrams() const;

    void addTrack(Track* newTrack);
    void addTram(Tram* newTram);
    int getLineNumber() const;
private:
    int lineNumber;
    std::vector<Track*> tracks;
    std::vector<Tram*> trams;
};


#endif //PSE_METRO_SIMULATIE_LINE_H
