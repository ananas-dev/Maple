set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(VENDOR_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendor")

# Files
file(GLOB SRCS
    "${SRC_DIR}/Maple/Application.cpp"
    "${SRC_DIR}/Maple/Layer.cpp"
    "${SRC_DIR}/Maple/LayerStack.cpp"
    "${SRC_DIR}/Maple/Log.cpp"
    "${SRC_DIR}/Platform/WindowsWindow.cpp"
)

# Definitions
add_compile_definitions("MP_BUILD")

if (WIN32)
    add_compile_definitions("MP_PLATFORM_WINDOWS")
endif (WIN32)

if (UNIX)
    add_compile_definitions("MP_PLATFORM_UNIX")
endif (UNIX)

# Create a static library
add_library(Maple STATIC ${SRCS})

# Precompiled header
target_precompile_headers(Maple PRIVATE "${SRC_DIR}/mppch.h")

# Include directories
target_include_directories(Maple PUBLIC "${SRC_DIR}")

################
# DEPENDENCIES #
################

# SPDLOG

add_subdirectory("${VENDOR_DIR}/spdlog")

# Link it to our library
target_link_libraries(Maple PRIVATE spdlog::spdlog)

# Make sure we can import the headers from our code
target_include_directories(Maple PUBLIC "${VENDOR_DIR}/spdlog/include")

# GLFW and OpenGL
add_subdirectory("${VENDOR_DIR}/glfw")
target_link_libraries(Maple PRIVATE glfw)
target_include_directories(Maple PUBLIC "${VENDOR_DIR}/glfw/include")
find_package(OpenGL REQUIRED)
target_link_libraries(Maple PRIVATE OpenGL::GL)

# Glad
add_subdirectory("${VENDOR_DIR}/glad/cmake")
glad_add_library(glad_gl_core_mx_46 REPRODUCIBLE MX API gl:core=4.6)
target_link_libraries(Maple PRIVATE glad_gl_core_mx_46)

# Instructions for global installation
install(TARGETS Maple
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)
