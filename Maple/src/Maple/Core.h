#pragma once

#ifdef MP_PLATFORM_WINDOWS
    #define MP_DEBUG_BREAK __debugbreak()
#elif MP_PLATFORM_UNIX
    #define MP_DEBUG_BREAK raise(SIGTRAP)
#else
    #error Platform not supported !
#endif

#ifdef MP_ENABLE_ASSERTS
    #define MP_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); MP_DEBUG_BREAK; } }
    #define MP_CORE_ASSERT(x, ...) { if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); MP_DEBUG_BREAK; } }
#else
    #define MP_ASSERT(x, ...)
    #define MP_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)