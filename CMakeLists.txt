cmake_minimum_required(VERSION 3.2.1)
project(database)
include(FetchContent)
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt
    GIT_TAG 10.0.0
    GIT_SHALLOW TRUE)
    FetchContent_MakeAvailable(fmt)


FetchContent_Declare(
  libpqxx
  GIT_REPOSITORY https://github.com/jtv/libpqxx.git
  GIT_TAG 7.7.5
  GIT_SHALLOW TRUE
)
#set(PQXX_LIBRARIES pqxx_static)

FetchContent_MakeAvailable(libpqxx)



add_executable(${PROJECT_NAME} main.cpp Database.cpp SqlCommands.cpp AbstractTable.cpp MtvTable.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC fmt::fmt  -lpqxx)
target_include_directories(${PROJECT_NAME}  PUBLIC ./)
target_include_directories(${PROJECT_NAME}  PUBLIC ./)