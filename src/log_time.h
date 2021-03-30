#pragma once

#include <chrono>
#include <string>

class log_time {
private:
	time_t cur_time;
	tm info_time;
	char t_str[80];
public:

	std::string display_time();

};