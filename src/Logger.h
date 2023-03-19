#ifndef PSE_METRO_SIMULATIE_LOGGER_H
#define PSE_METRO_SIMULATIE_LOGGER_H

#include <iostream>

/**
 * Logger object for simple output formatting
 */
class Logger {
public:
    /**
     * Writes an error message to the given stream, with right formatting
     * @param stream is the stream the error message needs to be written to
     * @param msg is the message that needs to be formatted \b !newline \b gets \b added \b by \b default!
     */
    static void writeError(std::ostream &stream, const std::string &msg) {
        stream << "ERROR: " << msg << std::endl;
    }
};


#endif //PSE_METRO_SIMULATIE_LOGGER_H
