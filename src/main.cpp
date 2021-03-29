#include <iostream>
#include "logger.h"

int main() {
    qlog::debug("hello");
    qlog::info("Information");
    qlog::error("Error");
    qlog::critical("Critical operator: ", "set function in header file");
    qlog::log(qlog::level::debug, "Debuging...");
    qlog::log(qlog::level::debug, "Something wrong with: " ,"logger");
     
    
    return 0;
}