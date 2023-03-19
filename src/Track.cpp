#include "Track.h"
#include "DesignByContract.h"

Track::Track(Station *begin, Station *anEnd) : begin(begin), end(anEnd) {
    _initCheck = this;
}
Track::~Track() {}

Station *Track::getBegin() const {
    return begin; }
Station *Track::getAnEnd() const {
    return end; }

bool Track::properlyInitialized() const {
    return _initCheck == this;
}
