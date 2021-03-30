#pragma once

#include <fstream>
#include <sstream>

namespace log_file {
	std::ofstream file;
	std::stringstream ss_log;

	inline const void write_log(std::string ss_log) {
		file.open("log.txt", std::ios::app);
		if (file.is_open()) {
			file << ss_log;
		}
		file.close();
	}

};
