#include <iostream>
#include <string>
#include <sstream>
#include "logger.h" 
#include "log_time.h"
#include "log_file.h"

namespace qlog {

	void log(std::string msg) {
		std::string cur_lvl = log_level::get_level(log_level::setting_level);

		log_time time;
		std::string c_time = time.display_time();

		std::stringstream ss;
		ss << c_time << "\t[" << cur_lvl << "]\t" << msg << '\n';
		std::cout << ss.str();
		log_file::write_log(ss.str());
		
	}

	void log(log_level::level lvl, std::string msg, std::string arg) {
		if (lvl < log_level::setting_level) return;
		std::string cur_lvl = log_level::get_level(lvl);

		log_time time;
		std::string c_time = time.display_time();

		std::stringstream ss;
		ss << c_time << "\t[" << cur_lvl << "]\t" << msg << " " << arg << '\n';
		std::cout << ss.str();
		log_file::write_log(ss.str());
		
	}

	void debug(std::string msg, std::string arg) {
		log(log_level::level::debug, msg, arg);
	}

	void info(std::string msg, std::string arg) {
		log(log_level::level::info, msg, arg);
	}

	void warn(std::string msg, std::string arg) {
		log(log_level::level::warn, msg, arg);
	}

	void error(std::string msg, std::string arg) {
		log(log_level::level::error, msg, arg);
	}
	
	void critical(std::string msg, std::string arg) {
		log(log_level::level::critical, msg, arg);
	}

}