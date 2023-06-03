cmake_minimum_required(VERSION 3.10.2)

project(a_star)

aux_source_directory(${PROJECT_SOURCE_DIR} a_star_FILES)
add_library(${PROJECT_NAME} STATIC ${a_star_FILES})