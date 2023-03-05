#include "Track.h"

Track::Track(Station *begin, Station *anEnd) : begin(begin), end(anEnd) {}

Station *Track::getBegin() const { return begin; }
Station *Track::getAnEnd() const { return end; }