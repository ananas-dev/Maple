add_executable(Sandbox src/SandboxApp.cpp)
target_link_libraries(Sandbox Maple)
target_include_directories(Sandbox PUBLIC "${CMAKE_SOURCE_DIR}/Maple/src")
 
# Weird stuff where I have to include the precompiled header of Maple here too
target_precompile_headers(Sandbox PRIVATE "${CMAKE_SOURCE_DIR}/Maple/src/mppch.h")

if (WIN32)
    add_compile_definitions(MP_PLATFORM_WINDOWS)
endif (WIN32)

if (UNIX)
    add_compile_definitions(MP_PLATFORM_UNIX)
endif (UNIX)

install(TARGETS Sandbox RUNTIME DESTINATION bin)
