#ifndef PSE_METRO_SIMULATIE_STATION_H
#define PSE_METRO_SIMULATIE_STATION_H


#include <string>

class Station {
public:
    // Constructor
    Station(std::string name, Station nextStation, Station previousStaion, int trackNumber);
    // Destructor
    ~Station();

    getName();
    getNextStation();
    getPreviousStation();
    get


};


#endif //PSE_METRO_SIMULATIE_STATION_H
