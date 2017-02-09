#pragma once

#include <fstream>
#include <memory>
#include <iomanip>
#include <string>

namespace KAI
{
	class Logger
	{
		// TODO: use PIMPL to hide this from header
		std::unique_ptr<std::ofstream> _log;

	public:
		Logger(const char *logFileName = "cpp-log.txt");
		~Logger();

		void Log(const char *text, ...);

		static std::string GetTimeNowFormatted(const char *fmt = "%m-%d-%Y %H-%M-%S");
		static std::string GetTimeNow();
	};
}

