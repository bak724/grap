cmake_minimum_required(VERSION 2.8)
project(grap)
CMAKE_POLICY(SET CMP0015 NEW)
set (GRAP_VERSION "1.3.1")

# Default build type: Release
if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "No build type selected, default to Release")
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build type (default Release)" FORCE)
endif()


# Options
set (SECCOMP OFF CACHE BOOL "Seccomp")
if(${SECCOMP})
  add_definitions(-DSECCOMP)
endif()

# Cmake Modules-------------------------------------------------------------
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake-modules")
include(ListCombinations)

# Variables-----------------------------------------------------------------
# Describe property
define_property(GLOBAL PROPERTY SRCS_BINDING
    BRIEF_DOCS "Bindings sources"
    FULL_DOCS "Bindings sources")

set_property(GLOBAL PROPERTY SRCS_BINDING "")

# Macros--------------------------------------------------------------------
macro(binding_add_srcs var)
  set_property(GLOBAL APPEND PROPERTY SRCS_BINDING "${var}")
endmacro(binding_add_srcs)

# Compiler------------------------------------------------------------------
if(${MSVC})
  # Don't include uinstd.h in Lexer.h
  add_definitions(-DYY_NO_UNISTD_H)
  
  # Increase stack size
  set(CMAKE_EXE_LINKER_FLAGS "/STACK:1000000000")
  set(CMAKE_CXX_FLAGS_RELEASE "/MT")
  set(CMAKE_CXX_FLAGS_DEBUG "/MTd -DDEBUG")
else()
  # Less warnings in C in order to avoid warnings about flex/bison code
  set(CMAKE_CXX_FLAGS " -D__STDC_FORMAT_MACROS -std=gnu++11 -D_hypot=hypot -pedantic -Wall -Wno-write-strings -Wextra -Wcast-align -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Woverloaded-virtual -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused")

  set(CMAKE_CXX_FLAGS_VALGRIND " -g")
  set(CMAKE_C_FLAGS_VALGRIND " -g")

  set(CMAKE_CXX_FLAGS_DEBUG " -g -fsanitize=address -DDEBUG")
  set(CMAKE_C_FLAGS_DEBUG " -g -fsanitize=address -DDEBUG")

  set(CMAKE_CXX_FLAGS_ERRALL " -g -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused")

  set(CMAKE_C_FLAGS_ERRALL " -g -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused")

endif()


# Boost package
if(${MSVC})
  set(Boost_USE_STATIC_LIBS ON)
else()
  set(Boost_USE_STATIC_LIBS OFF)
endif()

find_package(Boost REQUIRED COMPONENTS regex system filesystem)

include_directories(
  ./
  libs/common/
  libs/libgraph/
  libs/dotparser/
  libsGTSI/
  libsGTSI/Traversal/
  libs/node_info/
  ${CMAKE_BINARY_DIR}/libs/dotparser/
  ${Boost_INCLUDE_DIR}
  )

# Libraries-----------------------------------------------------------------
# Libs
add_subdirectory(libs)

# GTSI
add_subdirectory(libsGTSI)

# Executables---------------------------------------------------------------
add_subdirectory(tools)

# Bindings------------------------------------------------------------------
add_subdirectory(bindings)
