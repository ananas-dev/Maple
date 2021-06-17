add_executable(Sandbox src/SandboxApp.cpp)
include_directories(${CMAKE_SOURCE_DIR}/Topaze/src)
target_link_libraries(Sandbox Topaze)

if (WIN32)
    add_compile_definitions(TPZ_PLATFORM_WINDOWS)
endif (WIN32)

if (UNIX)
    add_compile_definitions(TPZ_PLATFORM_UNIX)
endif (UNIX)

install(TARGETS Sandbox RUNTIME DESTINATION bin)
