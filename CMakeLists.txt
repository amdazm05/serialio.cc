cmake_minimum_required(VERSION 3.12)
project(serialcc)
include_directories(${CMAKE_SOURCE_DIR}/include/)
add_library(${PROJECT_NAME} STATIC ${CMAKE_SOURCE_DIR}/src/stream/serialstreamer.cc)
target_link_directories(${PROJECT_NAME}
    PUBLIC
    ${CMAKE_SOURCE_DIR}/include/
)
add_executable(test ${CMAKE_SOURCE_DIR}/tests/serialtest.cc)
target_link_libraries(test PUBLIC ${PROJECT_NAME} )