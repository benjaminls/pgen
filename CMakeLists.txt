cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

PROJECT(pgen VERSION 0.1.0)

include(FetchContent)

# fetch latest argparse
FetchContent_Declare(
    argparse
    GIT_REPOSITORY https://github.com/p-ranav/argparse.git
)
FetchContent_MakeAvailable(argparse)

# fetch latest spdlog
FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG v1.11.0)
FetchContent_MakeAvailable(spdlog)

add_executable(pgen main.cpp)
target_link_libraries(pgen argparse)
