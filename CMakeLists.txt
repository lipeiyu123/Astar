cmake_minimum_required(VERSION 3.10.2)

project(A_star)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

add_subdirectory(a_star)


set(a_star_DIR ${PROJECT_SOURCE_DIR}/a_star)

include_directories(${PROJECT_SOURCE_DIR}
    ${a_star_DIR} 
)


add_executable(${PROJECT_NAME} main.cpp )
target_link_libraries(${PROJECT_NAME} a_star)