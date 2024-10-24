project(MatrixLib)

add_library(MatrixLib INTERFACE)
target_include_directories(MatrixLib INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)