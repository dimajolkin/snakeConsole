cmake_minimum_required(VERSION 3.5)
project(snake)
set(CMAKE_C_FLAGS_DEBUG -lgraph)
set(CMAKE_CXX_FLAGS_DEBUG  -lgraph)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp driver/Driver.cpp driver/Driver.h scene/Map.cpp scene/Map.h types/Array.cpp types/Array.h scene/Sector.cpp scene/Sector.h scene/SectorTypeEnum.cpp scene/SectorTypeEnum.cpp scene/SectorTypeEnum.h scene/Color.cpp scene/Color.h scene/Scene.cpp scene/Scene.h scene/Player.cpp scene/Player.h scene/SectorFactory.cpp scene/SectorFactory.h)

add_executable(snake ${SOURCE_FILES} )