#include "Track.h"
#include "DesignByContract.h"

Track::Track(Station *begin, Station *anEnd, const int &length) : begin(begin), end(anEnd), length(length) {
    _initCheck = this;
    ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
}

Track::~Track() {
    REQUIRE(properlyInitialized(), "Track was not properly initialised.");
}

Station *Track::getBegin() const {
    REQUIRE(properlyInitialized(), "Track was not properly initialised.");
    return begin;
}
Station *Track::getAnEnd() const {
    REQUIRE(properlyInitialized(), "Track was not properly initialised.");
    return end;
}

bool Track::properlyInitialized() const {
    return _initCheck == this;
}

int Track::getLength() const {
    return length;
}
