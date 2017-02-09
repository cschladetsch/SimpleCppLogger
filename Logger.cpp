#include <sstream>
#include <ctime>
#include <stdarg.h>  

#include "Logger.h"

namespace KAI
{
	Logger::Logger(const char *logFileName)
		: _log(new std::ofstream(logFileName))
	{
		Log("Started at %s", GetTimeNow().c_str());
	}

	Logger::~Logger()
	{
		Log("Ended at %s", GetTimeNow().c_str());
		_log.release();
	}

	void Logger::Log(const char *fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		char buffer[10*1024];
		vsnprintf(buffer, sizeof(buffer)/sizeof(char), fmt, args);
		*_log << GetTimeNow() << ": " << buffer << std::endl;
		_log->flush();
	}

	std::string Logger::GetTimeNowFormatted(const char *fmt)
	{
		std::time_t time = std::time(nullptr);
		std::ostringstream ss;
		ss << std::put_time(std::localtime(&time), fmt);
		return ss.str();
	}

	std::string Logger::GetTimeNow()
	{
		return GetTimeNowFormatted("%H-%M-%S");
	}
}
