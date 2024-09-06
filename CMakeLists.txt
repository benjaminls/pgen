cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

PROJECT(pgen VERSION 0.1.0)

include(cmake/CPM.cmake)

CPMAddPackage(
    NAME argparse
    # I don't know why "GIT_TAG v1.0" is needed but it is. Removing it, 
    # using v${ARGPARSE_VERSION}, or using v3.1 all fail. 
    GIT_TAG v1.0
    GITHUB_REPOSITORY p-ranav/argparse
)
CPMAddPackage(
    NAME spdlog
    GIT_TAG v1.14.1
    GITHUB_REPOSITORY gabime/spdlog # to use our installed fmt lib
    # OPTIONS "SPDLOG_FMT_EXTERNAL YES"
)

add_executable(pgen main.cpp)
target_link_libraries(pgen argparse spdlog)
