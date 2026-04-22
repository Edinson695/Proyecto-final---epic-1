cmake_minimum_required(VERSION 3.10.2)
project(prog3_pf_epic1_feature1_v2026_1)

set(CMAKE_CXX_STANDARD 23)
add_compile_definitions(_SILENCE_CXX23_DENORM_DEPRECATION_WARNING)
if(UNIX AND NOT APPLE)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
endif()

if(MINGW OR CYGWIN)
    add_definitions(-O3)
endif()

include_directories(./include)
include_directories(include/utec/algebra)
file(GLOB source_files
        main.cpp
        src/*.cpp)

add_executable(${PROJECT_NAME}
        ${source_files}
    )

find_package(Eigen3 QUIET NO_MODULE)

if(TARGET Eigen3::Eigen)
    target_link_libraries(${PROJECT_NAME} PRIVATE Eigen3::Eigen)
elseif(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/third_party/eigen/Eigen")
    target_include_directories(${PROJECT_NAME} PRIVATE
            "${CMAKE_CURRENT_SOURCE_DIR}/third_party/eigen")
else()
    message(WARNING "Eigen3 was not found. Install it system-wide or vendor it in third_party/eigen-3.4.0.")
endif()

if(UNIX AND NOT APPLE)
    find_package(TBB)
    target_link_libraries(${PROJECT_NAME} TBB::tbb)
endif()

add_subdirectory(autograder)
