# Add dependency directories
add_subdirectory(vendor/spdlog)

file(GLOB SRCS
    "src/Maple/Application.cpp"
    "src/Maple/Log.cpp"
)

# Definitions
add_compile_definitions("MP_BUILD")

if (WIN32)
    add_compile_definitions("MP_PLATFORM_WINDOWS")
endif (WIN32)

if (UNIX)
    add_compile_definitions("MP_PLATFORM_UNIX")
endif (UNIX)

# Create a shared library
add_library(Maple SHARED ${SRCS})

################
# DEPENDENCIES #
################

set(VENDOR_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendor")

# SPDLOG

# This makes it possible to compile spdlog as a static library and link it with our dynamic library
set_property(TARGET spdlog PROPERTY POSITION_INDEPENDENT_CODE ON)

# Link it to our library
target_link_libraries(Maple PRIVATE spdlog::spdlog)

# Make sure we can import the headers from our code
target_include_directories(Maple PUBLIC "${VENDOR_DIR}/spdlog/include")

# Instructions for global installation
install(TARGETS Maple
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)
