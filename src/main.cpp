#include <iostream>
#include "logger.h"

int main() {
    // Simple log message
    qlog::log("Hello world!");

    // Select log_level 
    qlog::log(log_level::level::debug, "Debuging: ", "Selected log level");

    // Debug log
    qlog::debug("This is a debug message.");

    // Info log
    qlog::info("Information");

    // Error log 
    qlog::error("Error");

    // Crititcal log
    qlog::critical("Critical operator: ", "1");

    // Set log level to filter the output log
    log_level::set_level(log_level::level::critical);

    // Any information will not output if the the level is lower than setting level
    qlog::info("This message unable to log.", "Log failed");
   
    return 0;
}