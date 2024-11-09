cmake_minimum_required(VERSION 3.27)
project(CVRefine)

# Compile options
set(CMAKE_CXX_STANDARD 17)
set(REF_FOLDER "${PROJECT_SOURCE_DIR}/references")
set(CMAKE_BUILD_TYPE Debug)

# Source and lib files
set(INCLUDES ${REF_FOLDER}/mlpack/include
        ${REF_FOLDER}/armadillo/include
        ${REF_FOLDER}/cereal/include
        ${REF_FOLDER}/ensmallen/include
        ${REF_FOLDER}/opencv/include)

set(SOURCE_FILES main.cpp)
set(LIB_FILES ${REF_FOLDER}/armadillo/bin/lib/libopenblas.lib
        ${REF_FOLDER}/opencv/bin/lib/opencv_world490.lib)

# Project structure
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDES})
target_link_libraries(${PROJECT_NAME} PUBLIC ${LIB_FILES})

# Copy dll to executable folder
add_custom_command(
        TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${REF_FOLDER}/armadillo/bin/dll/libopenblas.dll"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>)

add_custom_command(
        TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${REF_FOLDER}/opencv/bin/dll/opencv_world490.dll"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>)
