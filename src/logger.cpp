#include <iostream>
#include <string>
#include "logger.h"
#include "log_time.h"

void qlog::log(level lvl , std::string msg, std::string arg )  {
	std::string cur_lvl = get_level(lvl);
	log_time time;
	auto c_time = time.display_time();
	std::cout  << c_time << "[" << cur_lvl << "]\t" << msg  << " "  << arg << std::endl;
}

std::string qlog::get_level(level lvl) {
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

void qlog::debug(std::string msg, std::string arg) {
	qlog::log(level::debug, msg, arg);
}

void qlog::info(std::string msg, std::string arg ) {
	qlog::log(level::info, msg, arg);
}

void qlog::warn(std::string msg, std::string arg) {
	qlog::log(level::warn, msg, arg);
}

void qlog::error(std::string msg, std::string arg) {
	qlog::log(level::error, msg, arg);
}

void qlog::critical(std::string msg, std::string arg) {
	qlog::log(level::critical, msg, arg);
}