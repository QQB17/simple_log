#pragma once

#include <string>

namespace log_level 
{

	enum class level {debug , info, warn, error, critical };
	
	extern level setting_level;

	std::string get_level(const level& lvl);
	
	void set_level(const level& lvl);
};