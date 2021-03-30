#include "log_time.h"

std::string log_time::display_time() {
	using namespace std::chrono;

	memset(t_str, 0, sizeof(t_str));
	time(&cur_time);
	localtime_s(&info_time, &cur_time);

	milliseconds cur_ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	size_t round_cur_ms = cur_ms.count() % 1000 ;
	std::string ms  = std::to_string(round_cur_ms);

	strftime(t_str, sizeof(t_str), "%Y-%m-%d %H:%M:%S.", &info_time);	
	return (t_str + ms);
}

