cmake_minimum_required(VERSION 3.15)
project(Leetcode)

set(CMAKE_CXX_STANDARD 14)

add_executable(heap HeapSort.cpp)
add_executable(quick QuickSort.cpp)
add_executable(merge MergeSort.cpp)
