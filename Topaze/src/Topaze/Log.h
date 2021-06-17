#pragma once

#include <memory>

#include <spdlog/spdlog.h>

#include "Core.h"


namespace Topaze {

    class TOPAZE_API Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };

}

// Core logs macro
#define TPZ_CORE_ERROR(...) ::Topaze::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TPZ_CORE_WARN(...)  ::Topaze::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TPZ_CORE_INFO(...)  ::Topaze::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TPZ_CORE_TRACE(...) ::Topaze::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client logs macro
#define TPZ_ERROR(...) ::Topaze::Log::GetClientLogger()->error(__VA_ARGS__)
#define TPZ_WARN(...)  ::Topaze::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TPZ_INFO(...)  ::Topaze::Log::GetClientLogger()->info(__VA_ARGS__)
#define TPZ_TRACE(...) ::Topaze::Log::GetClientLogger()->trace(__VA_ARGS__)