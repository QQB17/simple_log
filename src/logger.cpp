#include <iostream>
#include "logger.h"

void qlog::log(level lvl , const char* msg, const char* arg )  {
	const char* cur_lvl = get_level(lvl);
	std::cout  << "[" << cur_lvl << "]\t" << msg  << " "  << arg<< std::endl;
}

const char* qlog::get_level(level lvl) {
	switch (lvl)
	{
	case qlog::level::debug:
		return "DEBUG";
		break;
	case qlog::level::info:
		return "INFO";
		break;
	case qlog::level::warn:
		return "WARN";
		break;
	case qlog::level::error:
		return "ERROR";
		break;
	case qlog::level::critical:
		return "CRIT";
		break;
	default:
		break;
	}
}

void qlog::debug(const char* msg, const char* arg) {
	qlog::log(level::debug, msg, arg);
}

void qlog::info(const char* msg, const char* arg ) {
	qlog::log(level::info, msg, arg);
}

void qlog::warn(const char* msg, const char* arg) {
	qlog::log(level::warn, msg, arg);
}

void qlog::error(const char* msg, const char* arg) {
	qlog::log(level::error, msg, arg);
}

void qlog::critical(const char* msg, const char* arg) {
	qlog::log(level::critical, msg, arg);
}