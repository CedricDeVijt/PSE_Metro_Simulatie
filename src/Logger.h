#ifndef PSE_METRO_SIMULATIE_LOGGER_H
#define PSE_METRO_SIMULATIE_LOGGER_H

#include <iostream>

enum LogLevel {  ERROR, INFO };

/**
 * Logger object for simple output formatting
 */
class Logger {
public:
    /**
     * Writes an error message to the given stream, with right formatting
     * @param stream is the stream the error message needs to be written to
     * @param msg is the message that needs to be formatted
     * @attention newline gets added by default
     */
    static void error(const std::string& msg) {
        Logger *logger = getLogger();
        if (logger->logLevel >= ERROR) {
            *logger->errorstream << "ERROR: " << msg << std::endl;
        }
    }

    static void info(const std::string& msg) {
        Logger* logger = getLogger();
        if (logger->logLevel >= INFO) {
            *logger->outputstream << "INFO: " << msg << std::endl;
        }
    }

    static void setLogLevel(const LogLevel& level) {
        Logger* logger = getLogger();
        logger->logLevel = level;
    }

    static void setErrorStream(std::ostream* errorstream) {
        Logger* logger = getLogger();
        logger->errorstream = errorstream;
    }

    static void setOutputStream(std::ostream* outputstream) {
        Logger* logger = getLogger();
        logger->outputstream = outputstream;
    }

private:
    Logger() : logLevel(INFO), errorstream(&std::cerr), outputstream(&std::cout) {}

    static Logger* getLogger() {
        static Logger myLogger;
        return &myLogger;
    }
    LogLevel logLevel;
    std::ostream* errorstream;
    std::ostream* outputstream;
};

#endif //PSE_METRO_SIMULATIE_LOGGER_H
