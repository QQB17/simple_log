# simple_log
This is a simple logging system for learning purpose.

## Usage Sample

### Basic message
``` c++
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
```
---

### Log.txt
``` text.txt
2021-04-02 15:19:32.175	[DEBUG]	Hello world!
2021-04-02 15:19:32.183	[DEBUG]	Debuging:  Selected log level
2021-04-02 15:19:32.192	[DEBUG]	This is a debug message. 
2021-04-02 15:19:32.201	[INFO]	Information 
2021-04-02 15:19:32.214	[ERROR]	Error 
2021-04-02 15:19:32.224	[CRIT]	Critical operator:  1
```
---
## Reference:
- spdlog : https://github.com/gabime/spdlog
