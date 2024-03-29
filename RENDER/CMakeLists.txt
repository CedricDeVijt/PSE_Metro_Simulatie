cmake_minimum_required(VERSION 3.5)

project(engine)

############################################################
# Set compiler flags
############################################################
# If supported by your compiler, you can add the -Wall, -Wextra, –fstack-protector-all and -g3 flags here.
set(OWN_GXX_FLAGS "-std=c++14")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${OWN_GXX_FLAGS}")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${OWN_GXX_FLAGS}")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${OWN_GXX_FLAGS}")

############################################################
# List all sources
############################################################
set(engine_sources
        engine.cc
        ./Include/easy_image.cc
        ./Include/ini_configuration.cc
        ./Include/vector3d.cc ./Include/vector3d.h
        ./Include/l_parser.cc
        ./Include/obj_parser.cc

        ./Objects/Face.h
        ./Objects/Object3D.cpp ./Objects/Object3D.h
        ./Objects/Camera.h
        ./Objects/Line2D.h ./Objects/Point2D.h
        ./Objects/LSystem2D.cpp
        ./Objects/Calculator.cpp ./Objects/Calculator.h

        ./Objects/Face.cpp ./Objects/IniLoader.cpp ./Objects/IniLoader.h ./Objects/LSystem3D.cpp ./Objects/LSystem3D.h
        ./Objects/ZBuffer.cpp ./Objects/Scene.cpp ./Objects/Triangle.h Objects/Renderer.h Objects/Renderer.cpp Objects/Light.h Objects/Object3DFactory.cpp Objects/ShadowLight.cpp Objects/ImageDetails.h Objects/ImageDetails.cpp Objects/AmbientLight.cpp Objects/PointLight.cpp Objects/InfLight.cpp)

############################################################
# List all metro sources
############################################################

set(metro_sources
        # Metro Files
        ../src/MetroSimulation.cpp
        ../src/TramStop.cpp
        ../src/Tram.cpp
        ../src/MetroXMLParser.cpp
        ../src/Track.cpp
        ../src/Line.cpp
        ../src/MetroSystem.cpp
        ../src/Logger.h
        ../src/MetroSystemOutput.cpp
        ../src/MetroSimStatistics.cpp
        MetroRenderer.cpp
        RenderObject.cpp)

set(TINY_XML_SOURCE_FILES
        # Set source files for tinyXml
        ../tinyxml/tinystr.cpp
        ../tinyxml/tinyxmlerror.cpp
        ../tinyxml/tinystr.cpp
        ../tinyxml/tinyxml.cpp
        ../tinyxml/tinyxmlparser.cpp
)
############################################################
# Create an executable
############################################################
set(exe_name "renderer")
add_executable( ${exe_name} ${engine_sources} ${metro_sources} ${TINY_XML_SOURCE_FILES})
