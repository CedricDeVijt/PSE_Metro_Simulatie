#ifndef PSE_METRO_SIMULATIE_STATION_H
#define PSE_METRO_SIMULATIE_STATION_H
#include <string>
#include <ostream>

class Track;

class Station {
public:
    // Constructor
    Station();
    Station(const std::string &name, Track *nextTrack, Track *prevTrack, int lineNumber);
    // Destructor
    ~Station();

    // Operators
    /**
     * Converts Track into a string
     * @REQUIRE(properlyInitialized(), "Station was not properly initialised.");
     */
    operator std::string();

    // Getters
    /**
     * Gives the name of the station
     * @return string: name of the station
     */
    const std::string &getName() const;

    /**
     * Gives a pointer to the next track of the station
     * @return Track* to the next track
     */
    Track *getNextTrack() const;

    /**
     * Gives a pointer to the previous track of the station
     * @return Track* to the previous track
     */
    Track *getPrevTrack() const;

   /**
    * Gives the line number of the station
    * @return
    */
    int getLineNumber() const;

    // Setters
    /**
     * Sets the name of the station
     * @param name name to be given to the station
     */
    void setName(const std::string &name);

    /**
     * Sets next station of the station
     * @param nextStation the next station given to the station
     */
    void setNextTrack(Station *nextStation);

    /**
     * Sets the previous station
     * @param prevStation the previous station given to the station
     */
    void setPrevTrack(Station *prevStation);

    /**
     * Sets the line number of the station
     * @param lineNumber the line number given to the station
     */
    void setLineNumber(int lineNumber);

private:
    // other
    bool properlyInitialized() const;

    // Data
    std::string name;
    Track *nextTrack;
    Track *prevTrack;
    int lineNumber;

    Station* _initCheck;

    // OS
    friend std::ostream &operator<<(std::ostream &os, const Station &station);
};


#endif //PSE_METRO_SIMULATIE_STATION_H
