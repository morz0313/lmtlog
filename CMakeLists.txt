cmake_minimum_required(VERSION 3.0.0)
project(mylog VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/spdlog/include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/spdlog/lib)

add_definitions(-D SPDLOG_COMPILED_LIB)

set(SRC_DIR ./src/rotatelog.cc ./src/category.cc ./src/main.cc)

add_executable(mylog ${SRC_DIR})
target_link_libraries(mylog libspdlog.a pthread)
