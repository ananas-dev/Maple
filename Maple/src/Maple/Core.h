#ifdef MP_PLATFORM_WINDOWS
    #ifdef MP_BUILD
        #define Maple_API __declspec(dllexport)
    #else
        #define Maple_API __declspec(dllimport)
    #endif
#elif MP_PLATFORM_UNIX
    #ifdef MP_BUILD
        #define Maple_API __attribute__((visibility("default")))
    #else
        #define Maple_API
    #endif
#else
    #error Platform not supported !
#endif