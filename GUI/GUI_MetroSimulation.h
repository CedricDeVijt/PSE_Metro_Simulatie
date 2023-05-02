#ifndef PSE_GUI_GUI_METROSIMULATION_H
#define PSE_GUI_GUI_METROSIMULATION_H

#include <Qt>
#include <QObject>
#include "../src/MetroSimulation.h"

class GUI_MetroSimulation : public QObject, public MetroSimulation{
Q_OBJECT
public:
    GUI_MetroSimulation(const std::string &inputFile, std::ostream &errorstream, unsigned int runtime, bool createPng);

private:
    void emitSimulationProgressed() override;

signals:
    void simulationProgressed();

};
#endif //PSE_GUI_GUI_METROSIMULATION_H
