cmake_minimum_required(VERSION 3.2)
project(yuv)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)
add_executable(yuv
        yuv.cpp)
target_include_directories(yuv PRIVATE
        ${OpenCV_INCLUDE_DIRS}
)
target_link_libraries(yuv PRIVATE
        ${OpenCV_LIBS}
)
