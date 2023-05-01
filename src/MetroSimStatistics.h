#ifndef PSE_METRO_SIMULATIE_METROSIMSTATISTICS_H
#define PSE_METRO_SIMULATIE_METROSIMSTATISTICS_H

#include "MetroSystem.h"
#include "MetroSimulation.h"

class MetroSimStatistics {
public:
    explicit MetroSimStatistics(MetroSimulation *sim);

    void printStats(std::ostream &os) const;

    int getTime() const;
    int getTotalCost() const;
    int getDefectTrams() const;
    int getWorkingTrams() const;
private:
    MetroSimulation *sim;
    int time;
    int totalCost;
    int defectTrams;
    int workingTrams;
};


#endif //PSE_METRO_SIMULATIE_METROSIMSTATISTICS_H
