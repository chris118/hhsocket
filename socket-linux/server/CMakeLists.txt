cmake_minimum_required (VERSION 2.8)

project (server)

cmake_policy(SET CMP0015 NEW)

aux_source_directory(. PROJECT_SOURCE_DIR)
aux_source_directory(./protobuf PROTOC_SRC_LIST)
list(APPEND PROJECT_SOURCE_DIR ${PROTOC_SRC_LIST})
aux_source_directory(./socket_base SB_SRC_LIST)
list(APPEND PROJECT_SOURCE_DIR ${SB_SRC_LIST})
aux_source_directory(./utility UT_SRC_LIST)
list(APPEND PROJECT_SOURCE_DIR ${UT_SRC_LIST})


#$ cmake -DCMAKE_BUILD_TYPE=Debug .
#SET(CMAKE_CXX_FLAGS_DEBUG"$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
#SET(CMAKE_CXX_FLAGS_RELEASE"$ENV{CXXFLAGS} -O3 -Wall")

add_definitions(-std=c++11)

LINK_DIRECTORIES(
)

include_directories (
./protobuf
./socket_base
./utility
/usr/local/include
/usr/include
/usr/local/cuda/include
)

add_executable(server ${PROJECT_SOURCE_DIR})

target_link_libraries(server   
   protobuf
   pthread
)
