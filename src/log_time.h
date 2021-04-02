#pragma once

#include <string>

class log_time {
private:
	time_t cur_time;
	tm info_time;
	char t_str[26];
public:

	const std::string display_time() ;

};