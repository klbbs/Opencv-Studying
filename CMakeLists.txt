cmake_minimum_required(VERSION 3.1)
Project(hello)
find_package(OpenCV REQUIRED)

add_executable(aTest4 mycpp4.cpp)

target_link_libraries(aTest4 ${OpenCV_LIBS})

include_directories(${OpenCV_INCLUDE_DIRS})

