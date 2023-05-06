#ifndef PSE_GUI_GUI_METROSIMULATION_H
#define PSE_GUI_GUI_METROSIMULATION_H

#include <Qt>
#include <QObject>
#include "../src/MetroSimulation.h"

/**
 * @brief The GUI_MetroSimulation class is responsible for creating and running a metro simulation with GUI support.
 * It inherits from QObject and MetroSimulation classes.
 */
class GUI_MetroSimulation : public QObject, public MetroSimulation {
Q_OBJECT
public:
    /**
     * Initializes a Metrosimulation
     *
     * @param inputFile is a .xml file that contains METRODATA
     * @param errorstream is the stream the errors get outputted to
     * @param runtime is the time the simulation needs to run
     * @param createPng if the system needs to create png's of all the conditions the system goes through
     * @ENSURE properlyInitialized(), "constructor must end in properlyInitialized state"
     */
    GUI_MetroSimulation(const std::string &inputFile, std::ostream &errorstream, unsigned int runtime, bool createPng);

private:
    void emitSimulationProgressed() override;

signals:
    void simulationProgressed();

};
#endif //PSE_GUI_GUI_METROSIMULATION_H
