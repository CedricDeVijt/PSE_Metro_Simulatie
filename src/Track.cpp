#include "Track.h"

Track::Track(Station *begin, Station *anEnd) : begin(begin), end(anEnd) {}
Track::~Track() {}

Station *Track::getBegin() const { return begin; }
Station *Track::getAnEnd() const { return end; }
