project(FDM)

add_library(FDM Calculate.cpp)
target_include_directories(FDM PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
include_directories(MatrixLib)
target_link_libraries(FDM PUBLIC MatrixLib)