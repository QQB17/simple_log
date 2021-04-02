#pragma once

#include "log_level.h"

namespace qlog { 

	void log(std::string msg);

	void log(log_level::level lvl, std::string msg = "" , std::string arg = "");

	void debug(std::string msg, std::string arg = "");

	void info(std::string msg, std::string arg = "");

	void warn(std::string msg, std::string arg = "");

	void error(std::string msg, std::string arg = "");

	void critical(std::string msg, std::string arg = "");
};

