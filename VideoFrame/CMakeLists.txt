cmake_minimum_required(VERSION 3.15)
project(VideoFrame)

find_package(OpenCV REQUIRED)

add_executable(VideoFrame VideoFrame.cpp)
target_link_libraries(VideoFrame ${OpenCV_LIBS})