#ifndef PSE_METRO_SIMULATIE_LOGGER_H
#define PSE_METRO_SIMULATIE_LOGGER_H

#include <ostream>

class Logger {
public:
    explicit Logger(std::ostream *stream);
    void output(std::string s);
    void error(std::string s);
private:
    std::ostream *stream;
};


#endif //PSE_METRO_SIMULATIE_LOGGER_H
