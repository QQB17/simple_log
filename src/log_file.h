#pragma once

#include <fstream>

namespace log_file 
{
	
	inline const void write_log(const std::string& ss_log)
	{
		std::ofstream file;
		file.open("log.txt", std::ios::app);
		if (file.is_open()) 
		{
			file << ss_log;
		}
		file.close();
	}
};
