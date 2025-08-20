cmake_minimum_required(VERSION 3.5.1)
project(sort-cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# Try to find OpenCV
find_package(OpenCV REQUIRED)
if (OpenCV_FOUND)
    # If the package has been found, several variables will
    # be set, you can find the full list with descriptions
    # in the OpenCVConfig.cmake file.
    # Print some message showing some of them
    message(STATUS "OpenCV library status:")
    message(STATUS "    version: ${OpenCV_VERSION}")
    message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
else ()
    message(FATAL_ERROR "Could not locate OpenCV")
endif()

# Try to find Boost
find_package(Boost COMPONENTS program_options filesystem REQUIRED)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
else ()
    message(FATAL_ERROR "Could not locate Boost")
endif()

include_directories(${PROJECT_SOURCE_DIR}/include)

# 라이브러리용 소스 파일들 (main.cpp 제외)
set(LIBRARY_SOURCE_FILES 
    src/kalman_filter.cpp
    src/track.cpp
    src/tracker.cpp
    src/munkres.cpp
)

# sort-cpp 라이브러리 생성
add_library(sort-cpp STATIC ${LIBRARY_SOURCE_FILES})

target_link_libraries (
        sort-cpp
        ${OpenCV_LIBS}
        ${Boost_LIBRARIES}
)

# 헤더 파일들을 다른 타겟에서 사용할 수 있도록 설정
target_include_directories(sort-cpp PUBLIC ${PROJECT_SOURCE_DIR}/include)
