#include "LogSystem.h"
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/async.h>

YuEngine::FLogSystem::FLogSystem()
{
	auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
	console_sink->set_level(spdlog::level::trace);

	const spdlog::sinks_init_list sinks = { console_sink };

	spdlog::init_thread_pool(8192, 1);

	logger = std::make_shared<spdlog::async_logger>("console", 
													sinks.begin(), 
													sinks.end(),
													spdlog::thread_pool(),
													spdlog::async_overflow_policy::block);

	logger->set_level(spdlog::level::trace);
	spdlog::register_logger(logger);
}

YuEngine::FLogSystem::~FLogSystem()
{
	logger->flush();  // 强制刷新所有缓冲的日志消息到输出设备
	spdlog::drop_all(); // 注销并删除所有 logger，释放资源

}
