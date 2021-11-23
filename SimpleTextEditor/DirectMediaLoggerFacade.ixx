// DirectMediaLoggerFacade.ixx
// Making code more consistent by using SDL2 wrapper

extern "C"
{
	#include <SDL.h>
}

// Wating until STL containers will be available to be added via import >.<
#include <unordered_map>
#include <string>

export module DirectMediaLoggerFacade;

import Singleton;

export enum class LoggingPriority: unsigned char
{
	Info,
	Debug,
	Error,
	Verbose,
	Warning,
	Critical
}; typedef std::unordered_map<LoggingPriority, SDL_LogPriority> LoggingPriorityMap;

export class DirectMediaLoggerFacade final: public Singleton<DirectMediaLoggerAdapter>
{
public:		
	const void SetLoggingPriority(LoggingPriority NewLoggingPriority);
	
	const void Log(LoggingPriority MessagePriority, std::string fmt, ...);
	const void Log(LoggingPriority MessagePriority, const char* fmt, ...);

private:
	LoggingPriorityMap m_PriorityMap = 
	{
		{LoggingPriority::Info,     SDL_LOG_PRIORITY_INFO},
		{LoggingPriority::Debug,    SDL_LOG_PRIORITY_DEBUG},
		{LoggingPriority::Error,    SDL_LOG_PRIORITY_ERROR},
		{LoggingPriority::Warning,  SDL_LOG_PRIORITY_WARN},
		{LoggingPriority::Verbose,  SDL_LOG_PRIORITY_VERBOSE},
		{LoggingPriority::Critical, SDL_LOG_PRIORITY_CRITICAL},
	};
}; export typedef class DirectMediaLoggerAdapter SDLogger, DMLogger;

const void DirectMediaLoggerFacade::SetLoggingPriority(LoggingPriority NewLoggingPriority=LoggingPriority::Info)
{
	SDL_LogSetPriority(SDL_LOG_CATEGORY_APPLICATION, this->m_PriorityMap[NewLoggingPriority]);
}

const void DirectMediaLoggerFacade::Log(LoggingPriority MessagePriority, std::string fmt, ...)
{
	va_list args; va_start(args, fmt);
	SDL_LogMessageV(0, this->m_PriorityMap[MessagePriority], fmt.c_str(), args); // FIXME: Add category support
	va_end(args);
}

const void DirectMediaLoggerFacade::Log(LoggingPriority MessagePriority, const char* fmt, ...)
{
	va_list args; va_start(args, fmt);
	SDL_LogMessageV(0, this->m_PriorityMap[MessagePriority], fmt, args); // FIXME: Add category support
	va_end(args);
}
