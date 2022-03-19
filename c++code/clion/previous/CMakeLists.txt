cmake_minimum_required(VERSION 3.20)
project(previous)

set(CMAKE_CXX_STANDARD 14)

add_executable(previous main.cpp)
add_executable(joseph_ring pre/joseph_ring.cc)
add_executable(zigzag pre/zigzag.cc)
add_executable(train_rearrange pre/train_rearrange.cc)