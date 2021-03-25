#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <string>

#include "spdlog/spdlog.h"

// TODO:
// 1. print msg for different log_level
// 2. set_level to limit the output when the level is lower than current level
// 3.

// Advanced:
// 1. Able to set config (formait, date/time, level)

namespace mylog 
{
    // log level
    enum level_enum {
        trace,
        debug,
        info,
        warning,
        error,
        crtical,
        off
    };

    class clog {
    private:
    public:

        // TODO: Get mutiple args using variadic template
        template <typename T, typename... Args>
        static void info(std::string msg,T arg) {
            int x = 0;
            std::string c, log_message;

            for (int i = 0;i < msg.length();i++) 
            {
                if (msg[i] == '{') 
                {
                    while (++i != msg.length()) {
                        if (msg[i] == '}') break;
                    }
                    // type check
                    if (typeid(arg) == typeid(const char*) || typeid(arg) == typeid(char))
                        log_message += arg;
                    else
                        log_message += std::to_string(arg);
                    continue;
                }
                log_message += msg[i];
            }

            std::cout << msg << std::endl;
            std::cout << log_message << std::endl;
        }

        static void display_time() {
            time_t now;
            tm t_info;
            char str[80];
            time(&now);
            localtime_s(&t_info, &now);
           
           std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
           size_t round_ms = (ms.count() % 1000); // last 3 digit
            strftime(str, sizeof(str), "%Y-%m-%d %H:%M:%S.", &t_info);
            std::cout << "[" << str  << std::setw(3) << std::setfill('0') << round_ms << "]" << std::endl;
        }


        template <typename T, typename... Args>
        static auto elapsed_time(T func,Args... args) {
            auto start = std::chrono::high_resolution_clock::now();
            func(std::forward<Args>(args)...);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::microseconds::duration<double> elpased_now = end - start;
            auto ms = elpased_now.count();
            std::cout << "Elapsed time: " << ms << "ms\n";
            return ms;
        }

        void write_log_to_file(std::string msg) {
            std::ofstream file("log.txt",std::ios::app);
            if (file.is_open())
                file << msg << std::endl;
            else
                std::cout << "Failed log to file.\n";
        }
 
    };
}

void sortV(std::vector<int> v) {
    std::cout << "Sort...\n";
    std::sort(v.begin(), v.end());
}

int main() {
    std::vector<int> v{ 5,63,2,1,68,3 };
    mylog::clog::info("Hello world {0} {1}", 'a');
    mylog::clog::elapsed_time(sortV,v);
    mylog::clog::display_time();
        
    spdlog::info("Hello world!");
   
    return 0;
}