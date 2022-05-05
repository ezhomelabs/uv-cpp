# CMakeLists.txt
# Copyright (C) orcaer@yeah.net. All rights reserved.
# Last modified: 2019-9-3

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(uv_cpp)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/
		    /home/haicam/workspace/libs/libuv/gm8136/armv5/include)

AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/uv  SOURCES)
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/uv/http  SOURCES)

LINK_DIRECTORIES(/home/haicam/workspace/libs/libuv/gm8136/armv5/lib)

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11   -O2 -Dnullptr=NULL")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x  -O2 -Dnullptr=NULL")


MESSAGE("building...")

ADD_LIBRARY (${PROJECT_NAME} STATIC ${SOURCES} )
TARGET_LINK_LIBRARIES(${PROJECT_NAME} "libuv_a.a" -pthread)
