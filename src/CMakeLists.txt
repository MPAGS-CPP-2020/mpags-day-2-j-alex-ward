# - Cmake requirements and declaring project
cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.1.0)

# - 
set(CMAKE_VERBOSE_MAKEFILE ON)

# - Dont need yet but this sets standard make to requested  (C++ 11, 14, 17, etc.)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_STANDARD 11)

add_executable(mpags-cipher 
            mpags-cipher.cpp
            MPAGSCipher/TransformChar.cpp
            MPAGSCipher/ProcessCommandLine.cpp)

target_include_directories(mpags-cipher
            PRIVATE MPAGSCipher)   

# - Dont allow C++ compiler vendor extensions
set(CMAKE_CXX_EXTENSIONS OFF)

# - set standard srt of flags
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")

target_compile_features(mpags-cipher
    PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization
    )
