cmake_minimum_required(VERSION 3.29)
project(DifferenceSchema)

set(CMAKE_CXX_STANDARD 20)

add_executable(DifferenceSchema main.cpp)

include_directories(MatrixLib)
add_subdirectory(MatrixLib)
target_link_libraries(DifferenceSchema MatrixLib)

include_directories(FDM)
add_subdirectory(FDM)
target_link_libraries(DifferenceSchema FDM)

add_subdirectory(Tests)


