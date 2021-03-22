#include <iostream>
#include <chrono>
#include "spdlog/spdlog.h"

namespace mylog 
{
    class clog {
    private:
    public:

        template <typename T>
        static void info(T msg) {
            std::cout << msg << std::endl;
        }

        static void displayTime() {
            time_t now = time(NULL);
            tm ltm;
            localtime_s(&ltm, &now);
            std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch());
            long int round_ms = (ms.count() / 1000);
            std::cout << "[" << (ltm.tm_year + 1900) << "-" << (ltm.tm_mon +1) << "-" << ltm.tm_mday<< " "
                << ltm.tm_hour << ":" << ltm.tm_min << ":" << ltm.tm_sec << "." << ms.count() << "]" <<std::endl;
        }


        template <typename T, typename... Args>
        static auto elapsedTime(T func,Args... args) {
            auto start = std::chrono::high_resolution_clock::now();
            func(std::forward<Args>(args)...);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elpased_now = end - start;
            std::chrono::microseconds::duration<double> elpased_now1 = end - start;
            std::cout << "Elapsed time: " << elpased_now1.count() << " ms\n";
        }


        
    };
}

void sortV(std::vector<int> v) {
    std::cout << "Sort vector.\n";
    std::sort(v.begin(), v.end());
}


int main() {
    std::vector<int> v{ 5,63,2,1,68,3 };
    mylog::clog::info("Hello");
    mylog::clog::elapsedTime(sortV,v);
    mylog::clog::displayTime();
   
        spdlog::info("Welcome to spdlog!");
    //spdlog::error("Some error message with arg: {}", 1);


    //spdlog::warn("Easy padding in numbers like {:08d}", 12);
    //spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    //spdlog::info("Support for floats {:03.2f}", 1.23456);
    //spdlog::info("Positional args are {1} {0}..", "too", "supported");
    //spdlog::info("{:<30}", "left aligned");

    //spdlog::set_level(spdlog::level::debug); // Set global log level to debug
    //spdlog::debug("This message should be displayed..");

    //// change log pattern
    //spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");

    //// Compile time log levels
    //// define SPDLOG_ACTIVE_LEVEL to desired level
    //SPDLOG_TRACE("Some trace message with param {}", 42);
    //SPDLOG_DEBUG("Some debug message");
}