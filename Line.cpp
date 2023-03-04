#include "Line.h"
#include "Track.h"

Line::Line(int lineNumber) : lineNumber(lineNumber) {}

void Line::addTrack(Track *newTrack) {
    tracks.push_back(newTrack);
}
void Line::addTram(Tram *newTram) { trams.push_back(newTram); }
int Line::getLineNumber() const { return lineNumber; }
const std::vector<Track *> &Line::getTracks() const { return tracks; }
const std::vector<Tram *> &Line::getTrams() const { return trams; }
