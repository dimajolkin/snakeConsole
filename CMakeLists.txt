cmake_minimum_required(VERSION 3.5)
project(snake)
set(CMAKE_C_FLAGS_DEBUG -lgraph)
set(CMAKE_CXX_FLAGS_DEBUG  -lgraph)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp driver/GraphocsDriver.cpp driver/GraphicsDriver.h scene/Map.cpp scene/Map.h types/Array.cpp types/Array.h scene/Sector.cpp scene/Sector.h scene/SectorTypeEnum.cpp scene/SectorTypeEnum.cpp scene/SectorTypeEnum.h scene/Color.cpp scene/Color.h scene/Scene.cpp scene/Scene.h scene/Player.cpp scene/Player.h scene/SectorFactory.cpp scene/SectorFactory.h scene/SnakePlayer.h driver/glut/Driver.h driver/AbstractDriver.h include.h driver/AbstractDriver.h driver/glut/Color.h core/Callable.h input/InputDriver.h scene/Food.h types/Point.h scene/FoodCollection.h scene/PlayerCollection.h scene/Controller.h menu.cpp scene/Menu.h types/Collection.h)

add_executable(snake ${SOURCE_FILES} )