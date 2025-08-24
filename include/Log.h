#ifndef PONG_LOG_H
#define PONG_LOG_H

#include "spdlog/logger.h"

namespace Pong {
    class Log {
    public:
        static void Init();

        static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; }
    private:
        static std::shared_ptr<spdlog::logger> s_Logger;
    };
} // Pong

#define PONG_TRACE(...)    ::Pong::Log::GetLogger()->trace(__VA_ARGS__)
#define PONG_INFO(...)     ::Pong::Log::GetLogger()->info(__VA_ARGS__)
#define PONG_WARN(...)     ::Pong::Log::GetLogger()->warn(__VA_ARGS__)
#define PONG_ERROR(...)    ::Pong::Log::GetLogger()->error(__VA_ARGS__)
#define PONG_FATAL(...)    ::Pong::Log::GetLogger()->fatal(__VA_ARGS__)

#endif //PONG_LOG_H