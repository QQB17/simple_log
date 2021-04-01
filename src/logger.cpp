#include <iostream>
#include <string>
#include <sstream>
#include "logger.h"
#include "log_time.h"
#include "log_file.h"


void qlog::log(log_level::level lvl , std::string msg, std::string arg )  {
	if (lvl < log_level::default_level) return;
	std::string cur_lvl = log_level::get_level(lvl);
	log_time time;
	auto c_time = time.display_time();
	std::stringstream ss;
	ss << c_time << "\t[" << cur_lvl << "]\t" << msg << " " << arg << '\n';
	std::cout << ss.str();
	log_file::write_log(ss.str());
}


void qlog::debug(std::string msg, std::string arg) {
	qlog::log(log_level::level::debug, msg, arg);
}

void qlog::info(std::string msg, std::string arg ) {
	qlog::log(log_level::level::info, msg, arg);
}

void qlog::warn(std::string msg, std::string arg) {
	qlog::log(log_level::level::warn, msg, arg);
}

void qlog::error(std::string msg, std::string arg) {
	qlog::log(log_level::level::error, msg, arg);
}

void qlog::critical(std::string msg, std::string arg) {
	qlog::log(log_level::level::critical, msg, arg);
}