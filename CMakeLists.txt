cmake_minimum_required(VERSION 3.30)
project(InfiniteBackgrounds)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenCV REQUIRED)

if(NOT OpenCV_FOUND)
    message(FATAL_ERROR "OpenCV not found!")
endif()

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/RepeatingRow.cpp
        src/Row.cpp
        src/StepFigure.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenCV_LIBS})
