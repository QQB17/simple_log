#pragma once

namespace qlog {

	enum class level { debug, info, warn, error, critical };

	void log(level lvl = level::debug, const char* msg = "" , const char* arg = "");

	const char* get_level(level lvl);

	void debug(const char* msg, const char* arg = "");

	void info(const char* msg, const char* arg = "");

	void warn(const char* msg, const char* arg = "");

	void error(const char* msg, const char* arg = "");

	void critical(const char* msg, const char* arg = "");


};

