#include "Track.h"
#include "DesignByContract.h"

Track::Track(TramStop *begin, TramStop *anEnd, const int &length) : begin(begin), end(anEnd), length(length) {
    _initCheck = this;
    ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
}

Track::~Track() {
    REQUIRE(properlyInitialized(), "Track was not properly initialised.");
}

TramStop *Track::getBegin() const {
    REQUIRE(properlyInitialized(), "Track was not properly initialised.");
    return begin;
}
TramStop *Track::getAnEnd() const {
    REQUIRE(properlyInitialized(), "Track was not properly initialised.");
    return end;
}

bool Track::properlyInitialized() const {
    return _initCheck == this;
}

int Track::getLength() const {
    return length;
}
