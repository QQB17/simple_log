#include "log_level.h"

namespace log_level {
	level default_level = level::debug;

	std::string get_level(level lvl) {
		switch (lvl)
		{
		case level::debug:
			return "DEBUG";
			break;
		case level::info:
			return "INFO";
			break;
		case level::warn:
			return "WARN";
			break;
		case level::error:
			return "ERROR";
			break;
		case level::critical:
			return "CRIT";
			break;
		default:
			break;
		}
	}

	void set_level(level lvl) {
		default_level = lvl;
	}
}