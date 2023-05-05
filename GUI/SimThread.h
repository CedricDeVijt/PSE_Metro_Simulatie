#ifndef PSE_GUI_SIMTHREAD_H
#define PSE_GUI_SIMTHREAD_H

#include <QThread>
#include "GUI_MetroSimulation.h"

class SimThread : public QThread{
public:
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
