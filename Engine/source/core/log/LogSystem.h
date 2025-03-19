#pragma once

#include <spdlog/spdlog.h>
#include <cstdint>
#include <stdexcept>

namespace YuEngine
{
	class FLogSystem
	{
	public:
		enum class ELogLevel : uint8_t
		{
			debug,
			info,
			warn,
			error,
			fatal
		};
	public:
		FLogSystem();
		~FLogSystem();

		template<typename... TArgs>
		void log(ELogLevel level, TArgs&&... args )
		{
			switch (level)
			{
			case ELogLevel::debug:
				logger->debug(std::forward<TArgs>(args)...);
				break;
			case ELogLevel::info:
				logger->info(std::forward<TArgs>(args)...);
				break;
			case ELogLevel::warn:
				logger->warn(std::forward<TArgs>(args)...);
				break;
			case ELogLevel::error:
				logger->error(std::forward<TArgs>(args)...);
				break;
			case ELogLevel::fatal:
				logger->critical(std::forward<TArgs>(args)...);
				FatalCallback(std::forward<TArgs>(args)...);
				break;
			}

		}

		template<typename... TArgs>
		void FatalCallback(TArgs&&... args)
		{
			const std::string message = fmt::format(std::forward<TArgs>(args)...);
			throw std::runtime_error(message);
		}

	private:
		std::shared_ptr<spdlog::logger> logger;
	};
}