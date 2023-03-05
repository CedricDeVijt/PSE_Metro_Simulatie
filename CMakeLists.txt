cmake_minimum_required(VERSION 3.6)
project(PSE_Metro_Simulatie)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-std=c++98 -Wall -Werror")
set(CMAKE_EXE_LINKER_FLAGS -pthread)

# Set include dir
include_directories(./gtest/include)

# Set Library dir
link_directories(./gtest/lib)

# Set source files for RELEASE target
set(RELEASE_SOURCE_FILES main.cpp
        DesignByContract.h
        # Metro Files
        MetroSimulation.cpp MetroSimulation.h
        Station.cpp Station.h
        Tram.cpp Tram.h
        MetroXMLParser.cpp MetroXMLParser.h
        # Set source files for tinyXml
        ./tinyxml/tinystr.cpp
        ./tinyxml/tinyxmlerror.cpp
        ./tinyxml/tinystr.cpp ./tinyxml/tinystr.h
        ./tinyxml/tinyxml.cpp ./tinyxml/tinyxml.h
        ./tinyxml/tinyxmlparser.cpp
        Track.cpp Track.h
        Line.cpp Line.h
        )

# Set source files for DEBUG target
set(DEBUG_SOURCE_FILES ParserTest.cpp tests.cpp)

# Create RELEASE target
add_executable(MetroSim main.cpp ${RELEASE_SOURCE_FILES})

# Create DEBUG target
add_executable(testing_tool ${DEBUG_SOURCE_FILES})

# Link library
target_link_libraries(testing_tool gtest)