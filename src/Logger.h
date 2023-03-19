#ifndef PSE_METRO_SIMULATIE_LOGGER_H
#define PSE_METRO_SIMULATIE_LOGGER_H

#include <iostream>

class Logger {
public:
    static void writeError(std::ostream &stream, const std::string msg) {
        stream << "ERROR: " << msg << std::endl;
    }
};


#endif //PSE_METRO_SIMULATIE_LOGGER_H
