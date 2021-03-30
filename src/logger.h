#pragma once

namespace qlog {

	enum class level { debug, info, warn, error, critical };

	void log(level lvl = level::debug, std::string msg = "" , std::string arg = "");

	std::string get_level(level lvl);

	void debug(std::string msg, std::string arg = "");

	void info(std::string msg, std::string arg = "");

	void warn(std::string msg, std::string arg = "");

	void error(std::string msg, std::string arg = "");

	void critical(std::string msg, std::string arg = "");


};

