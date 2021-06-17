# Spdlog
add_subdirectory(vendor/spdlog)
find_package(spdlog REQUIRED)

# Definitions
add_compile_definitions(TPZ_BUILD)

if (WIN32)
    add_compile_definitions(TPZ_PLATFORM_WINDOWS)
endif (WIN32)

if (UNIX)
    add_compile_definitions(TPZ_PLATFORM_UNIX)
endif (UNIX)

install(TARGETS Topaze
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)

# Add library
add_library(Topaze SHARED src/Topaze/Application.cpp)

# Link libraries
target_link_libraries(Topaze PRIVATE spdlog::spdlog)