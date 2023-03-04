#ifndef PSE_METRO_SIMULATIE_STATION_H
#define PSE_METRO_SIMULATIE_STATION_H
#include <string>

class Track;

class Station {
public:
    // Constructor
    Station(const std::string &name, Track *nextTrack, Track *prevTrack, int lineNumber);
    Station();

    // Destructor
    ~Station();

    // Getters
    const std::string &getName() const;
    Track *getNextTrack() const;
    Track *getPrevTrack() const;
    int getLineNumber() const;
    bool isProperlyInitialized() const;

    // Setters
    void setName(const std::string &name);
    void setNextTrack(Station *nextStation);
    void setPrevTrack(Station *prevStation);
    void setLineNumber(int lineNumber);
    void setProperlyInitialized(bool properlyInitialized);
private:
    std::string name;
    Track *nextTrack;
    Track *prevTrack;
    int lineNumber;

    bool properlyInitialized;
};


#endif //PSE_METRO_SIMULATIE_STATION_H
