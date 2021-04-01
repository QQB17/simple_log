#include <iostream>
#include "logger.h"

int main() {
    log_level::set_level(log_level::level::info);
    qlog::debug("hello");
    qlog::info("Information");
    qlog::error("Error");
    qlog::critical("Critical operator: ", "set function in header file");
    qlog::log(log_level::level::debug ,"Debuging..."); 
    
    return 0;
}