#ifndef PSE_GUI_SIMTHREAD_H
#define PSE_GUI_SIMTHREAD_H

#include <QThread>
#include "GUI_MetroSimulation.h"

/**
 * @brief A QThread subclass for running a metro simulation.
 */
class SimThread : public QThread{
public:
    /**
     * @brief Constructor for SimThread class.
     * @param sim A pointer to the GUI_MetroSimulation.
     * @param ss A reference to an the outputstream of the sim.
     */
    SimThread(GUI_MetroSimulation *sim, std::ostringstream &ss);
private:
    GUI_MetroSimulation *sim;
    std::ostringstream &ss;

protected:
    void run(){
        sim->run(ss);
    }
};


#endif //PSE_GUI_SIMTHREAD_H
