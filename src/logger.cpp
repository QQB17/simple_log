#include <iostream>
#include <string>
#include <sstream>
#include "logger.h" 
#include "log_time.h"
#include "log_file.h"

namespace qlog {

	void log(const std::string& msg) {
		std::string cur_lvl = log_level::get_level(log_level::setting_level);

		log_time* l_time = new log_time();
		const std::string c_time = l_time->display_time();
		delete l_time;

		std::stringstream ss;
		ss << c_time << "\t[" << cur_lvl << "]\t" << msg << '\n';
		std::cout << ss.str();
		log_file::write_log(ss.str());
	}

	void log(const log_level::level& lvl, const std::string& msg, const std::string& arg) {
		if (lvl < log_level::setting_level) return;
		std::string cur_lvl = log_level::get_level(lvl);

		log_time* l_time = new log_time();
		const std::string c_time = l_time->display_time();
		delete l_time;

		std::stringstream ss;
		ss << c_time << "\t[" << cur_lvl << "]\t" << msg << " " << arg << '\n';
		std::cout << ss.str();
		log_file::write_log(ss.str());
		
	}

	void debug(const std::string& msg, const std::string& arg) {
		log(log_level::level::debug, msg, arg);
	}

	void info(const std::string& msg, const std::string& arg) {
		log(log_level::level::info, msg, arg);
	}

	void warn(const std::string& msg, const std::string& arg) {
		log(log_level::level::warn, msg, arg);
	}

	void error(const std::string& msg, const std::string& arg) {
		log(log_level::level::error, msg, arg);
	}
	
	void critical(const std::string& msg, const std::string& arg) {
		log(log_level::level::critical, msg, arg);
	}

}