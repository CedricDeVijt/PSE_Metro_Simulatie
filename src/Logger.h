#ifndef PSE_METRO_SIMULATIE_LOGGER_H
#define PSE_METRO_SIMULATIE_LOGGER_H

#include <iostream>

enum logLevel {  ERROR, INFO };

/**
 * Singleton class responsible for logging
 */
class Logger {
public:
    /**
     * Writes an error message to the set error stream
     * @param msg is the message that needs to be formatted
     */
    static void error(const std::string& msg) {
        Logger *logger = getLogger();
        if (logger->logLevel >= ERROR) {
            *logger->errorstream << "ERROR: " << msg << std::endl;
        }
    }

    /**
     * Writes an info message to the set output stream
     * @param msg is the message that needs to be formatted
     */
    static void info(const std::string& msg) {
        Logger* logger = getLogger();
        if (logger->logLevel >= INFO) {
            *logger->outputstream << "INFO: " << msg << std::endl;
        }
    }

    /**
     * Sets the loglevel
     * @param level
     */
    static void setLogLevel(const logLevel& level) {
        Logger* logger = getLogger();
        logger->logLevel = level;
    }

    /**
     * Sets the errorstream
     * @param errorstream
     */
    static void setErrorStream(std::ostream* errorstream) {
        Logger* logger = getLogger();
        logger->errorstream = errorstream;
    }

    /**
     * Sets the outputstream
     * @param outputstream
     */
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
    logLevel logLevel;
    std::ostream* errorstream;
    std::ostream* outputstream;
};

#endif //PSE_METRO_SIMULATIE_LOGGER_H
