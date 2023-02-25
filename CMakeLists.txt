cmake_minimum_required(VERSION 3.20)

#setting project name and version
project(Tic-tac-toe VERSION 0.1)

#specifying c++ standard
set(CMAKE_CXX_STANDARD 14
        CMAKE_CXX_STANDARD_REQUIRED True)
add_subdirectory(lib)
list(APPEND EXTRA_LIBS
        board
)
list(APPEND EXTRA_INCLUDES
        "${PROJECT_SOURCE_DIR}/lib"
)

add_executable(Tic-tac-toe kk.cpp)


target_link_libraries(Tic-tac-toe PUBLIC
        ${EXTRA_LIBS}
)
target_include_directories(Tic-tac-toe PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${EXTRA_INCLUDES}"
)
