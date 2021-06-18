add_executable(Sandbox src/SandboxApp.cpp)
target_include_directories(Sandbox PUBLIC ${CMAKE_SOURCE_DIR}/Maple/src)
target_link_libraries(Sandbox Maple)

if (WIN32)
    add_compile_definitions(MP_PLATFORM_WINDOWS)
endif (WIN32)

if (UNIX)
    add_compile_definitions(MP_PLATFORM_UNIX)
endif (UNIX)

install(TARGETS Sandbox RUNTIME DESTINATION bin)
