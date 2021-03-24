#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>

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
 
    };
}

void sortV(std::vector<int> v) {
    std::cout << "Sort...\n";
    std::sort(v.begin(), v.end());
}

int main() {
    std::vector<int> v{ 5,63,2,1,68,3 };
    mylog::clog::info("Hello");
    mylog::clog::elapsed_time(sortV,v);
    mylog::clog::display_time();

    spdlog::info("Hello world!");
   
    return 0;
}