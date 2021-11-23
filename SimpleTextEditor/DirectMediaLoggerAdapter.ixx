export module DirectMediaLoggerAdapter;

#include "unordered_map"

#include "SDL.h"

import Singleton;

enum class LoggingPriority: unsigned char
{
	Info, Debug, Error,
	Verbose, Warning, 
	Critical
};

export class DirectMediaLoggerAdapter final: public Singleton<DirectMediaLoggerAdapter>
{
public:	
	inline const void SetLoggingPriority(LoggingPriority NewLoggingPriority);

private:

private:
	const std::unordered_map<LoggingPriority, SDL_LogPriority> m_PriorityMap = {
		{LoggingPriority::Info,     SDL_LOG_PRIORITY_INFO},
		{LoggingPriority::Warning,  SDL_LOG_PRIORITY_WARN},
		{LoggingPriority::Debug,    SDL_LOG_PRIORITY_DEBUG},
		{LoggingPriority::Error,    SDL_LOG_PRIORITY_ERROR},
		{LoggingPriority::Verbose,  SDL_LOG_PRIORITY_VERBOSE},
		{LoggingPriority::Critical, SDL_LOG_PRIORITY_CRITICAL},
	};
};

inline const void DirectMediaLoggerAdapter::SetLoggingPriority(LoggingPriority NewLoggingPriority=LoggingPriority::Info)
{
	SDL_LogCategory NewN = this->m_PriorityMap[NewLoggingPriority];
	SDL_LogSetPriority(SDL_LOG_CATEGORY_APPLICATION, );
}