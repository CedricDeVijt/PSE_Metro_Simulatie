#include "Tram.h"
#include <sstream>
#include <iostream>
#include "DesignByContract.h"


Tram::Tram(int tramNumber, int speed, TramStop *startStation, int repairTime, int defectAmount, int repairCost) :
tramNumber(tramNumber), speed(speed), _initCheck(this), startStation(startStation), currentStation(startStation),
repairCost(repairCost), repairTime(repairTime), defectAmount(defectAmount), totalCost(0), defect(false), repairSteps(0), steps(0) {
    ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
}

Tram::~Tram() {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
}

int Tram::getSpeed() const {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
    return speed;
}

void Tram::setSpeed(int speed_) {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
    Tram::speed = speed_;
    ENSURE(getSpeed()==speed_, "Failed to set speed.");
}

TramStop *Tram::getStartStation() const {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
    return startStation;
}

int Tram::getTramNumber() const {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
    return tramNumber;
}

TramStop *Tram::getCurrentStation() const {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
    return currentStation;
}

void Tram::setStartStation(TramStop *startStation_) {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
    Tram::startStation = startStation_;
    currentStation = startStation_;
    ENSURE(getStartStation()==startStation_, "SetStartstation failed.");
}

std::ostream &operator<<(std::ostream &os, const Tram &tram) {
    return os << "Tram " << tram.tramNumber;
}

Tram::operator std::string() {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
    std::ostringstream output;
    output << "Tram " << this->tramNumber << " in TramStop " << this->getCurrentStation()->getName();
    std::string outputString  = output.str();
    return outputString;
}

bool Tram::properlyInitialized() const {
    return _initCheck == this;
}

void Tram::drive(TramStop *destination, std::ostream &os) {
    REQUIRE(currentStation->isOccupied(), "Tram is leaving a station but is was not occupied in the first place.");
    REQUIRE(!destination->isOccupied(), "Tram is entering an occupied station.");

    currentStation->setOccupied(false);
    destination->setOccupied(true);

    os << *this << " reed van " << *currentStation << " naar ";
    currentStation = destination;
    os << *currentStation << "." << std::endl;
}

int Tram::getTotalCost() const {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
    return totalCost;
}

void Tram::handleDefect(std::ostream &os) {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
    if (defect) {
        repairSteps++;
        defect = repairSteps<repairTime;
        if (!defect) {
            os << *this << " was repaired.\n";
            steps = 0;
        }
    } else {
        steps++;
        defect = steps >= defectAmount;
        if (defect) {
            os << *this << " broke down.\n";
            totalCost += repairCost;
            repairSteps = 0;
        }
    }
}

bool Tram::isDefect() const {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
    return defect;
}

PCC::PCC(int tramNumber, TramStop *startStation, int repairTime, int defectAmount, int repairCost) :
Tram(tramNumber, 40, startStation, repairTime, defectAmount, repairCost) {}

Albatros::Albatros(int tramNumber, Metrostation *startStation, int repairTime, int defectAmount, int repairCost) :
Tram(tramNumber, 70, startStation, repairTime, defectAmount, repairCost)  {}

Stadslijner::Stadslijner(int tramNumber, Metrostation *startStation, int repairTime, int defectAmount, int repairCost) :
Tram(tramNumber, 70, startStation, repairTime, defectAmount, repairCost)  {}
