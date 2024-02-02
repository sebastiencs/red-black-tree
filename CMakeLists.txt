cmake_minimum_required(VERSION 3.12)

project(red-black-tree C)

add_library(${PROJECT_NAME} "")
target_sources(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/red-black-tree.c
    INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/red-black-tree.h
)

target_include_directories(${PROJECT_NAME}
    INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}
)
