/*
#ifdef TPZ_PLATFORM_WINDOWS
    #ifdef TPZ_BUILD
        #define TOPAZE_API __declspec(dllexport)
    #else
        #define TOPAZE_API __declspec(dllimport)
    #endif
#elif TPZ_PLATFORM_UNIX
    #ifdef TPZ_BUILD
        #define TOPAZE_API __attribute__((visibility("default")))
    #else
        #define TOPAZE_API
    #endif
#else
    #error Platform not supported !
#endif

*/

#define TOPAZE_API
