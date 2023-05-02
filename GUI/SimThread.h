#ifndef PSE_GUI_SIMTHREAD_H
#define PSE_GUI_SIMTHREAD_H

#include <QThread>
#include "../src/MetroSimulation.h"

class SimThread : public QThread{
public:
    SimThread(MetroSimulation *sim, std::ostringstream &ss);
private:
    MetroSimulation *sim;
    std::ostringstream &ss;

protected:
    void run(){
        sim->run(ss);
    }
};


#endif //PSE_GUI_SIMTHREAD_H
