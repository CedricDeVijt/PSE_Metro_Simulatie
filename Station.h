#ifndef PSE_METRO_SIMULATIE_STATION_H
#define PSE_METRO_SIMULATIE_STATION_H


#include <string>

class Station {
public:
    // Constructor
    Station(const std::string &name, Station *nextStation, Station *previousStation, int trackNumber);
    // Destructor
    ~Station();

    // Getters
    const std::string &getName() const;
    Station *getNextStation() const;
    Station *getPreviousStaion() const;
    int getTrackNumber() const;

    // Setters
    void setName(const std::string &name);
    void setNextStation(Station *nextStation);
    void setPreviousStaion(Station *previousStaion);
    void setTrackNumber(int trackNumber);

private:
    std::string name;
    Station* nextStation;
    Station* previousStation;
    int trackNumber;
};


#endif //PSE_METRO_SIMULATIE_STATION_H
