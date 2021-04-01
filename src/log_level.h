#pragma once

#include <string>


namespace log_level {
	enum class level { debug, info, warn, error, critical };
	
	extern level default_level;

	std::string get_level(level lvl);
	
	void set_level(level lvl);
};