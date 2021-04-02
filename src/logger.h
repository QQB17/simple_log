#pragma once

#include "log_level.h"

namespace qlog { 

	void log(const std::string& msg);

	void log(const log_level::level& lvl, const std::string& msg = "" , const std::string& arg = "");

	void debug(const std::string& msg, const std::string& arg = "");

	void info(const std::string& msg, const std::string& arg = "");

	void warn(const std::string& msg, const std::string& arg = "");

	void error(const std::string& msg, const std::string& arg = "");

	void critical(const std::string& msg, const std::string& arg = "");
};

