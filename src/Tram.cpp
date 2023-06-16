#include "Tram.h"
#include <sstream>
#include <iostream>
#include "DesignByContract.h"
#include "Logger.h"
#include "sstream"

Tram::Tram(int tramNumber, int speed, TramStop *startStation) :
tramNumber(tramNumber), speed(speed), _initCheck(this), startStation(startStation), currentStation(startStation) {
    vehicleType = "Tram";
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

void Tram::drive(TramStop *destination, bool blocked) {
    if (blocked) return;

    REQUIRE(currentStation->isOccupied(), "Tram is leaving a station but is was not occupied in the first place.");
    REQUIRE(!destination->isOccupied(), "Tram is entering an occupied station.");

    currentStation->setOccupied(false);
    destination->setOccupied(true);

    std::stringstream num;
    num << getTramNumber();
    Logger::info("Tram " + num.str() + " reed van " + currentStation->getName() + " naar " + destination->getName() + ".");
}

void PCC::drive(TramStop *destination, bool blocked) {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
    handleDefect();
    if (!defect) {
        Tram::drive(destination, blocked);
    }
}

int PCC::getTotalCost() const {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
    return totalCost;
}

void PCC::handleDefect() {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
    if (defect) {
        repairSteps++;
        defect = repairSteps<repairTime;
        if (!defect) {
            std::stringstream num;
            num << getTramNumber();
            Logger::info("Tram " + num.str() + " was repaired.");
            steps = 0;
        }
    } else {
        steps++;
        defect = steps >= defectAmount;
        if (defect) {
            std::stringstream num;
            num << getTramNumber();
            Logger::info("Tram " + num.str() + " broke down.");
            totalCost += repairCost;
            repairSteps = 0;
        }
    }
}

const std::string &Tram::getVehicleType() const {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
    return vehicleType;
}

PCC::PCC(int tramNumber, TramStop *startStation, int repairTime, int defectAmount, int repairCost) :
Tram(tramNumber, 40, startStation), repairCost(repairCost), repairTime(repairTime), defectAmount(defectAmount), totalCost(0), defect(false), repairSteps(0), steps(0) {
     vehicleType = "PCC";
}

bool PCC::isDefect() const {
    REQUIRE(properlyInitialized(), "Tram was not properly initialised.");
    return defect;
}

Albatros::Albatros(int tramNumber, Metrostation *startStation) :
Tram(tramNumber, 70, startStation)  {
    vehicleType = "Albatros";
}

Stadslijner::Stadslijner(int tramNumber, Metrostation *startStation) :
Tram(tramNumber, 70, startStation)  {
    vehicleType = "Stadslijner";
}
