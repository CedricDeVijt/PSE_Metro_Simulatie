cmake_minimum_required(VERSION 3.6)
project(PSE_Metro_Simulatie)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-std=c++98 -Wall -Werror -O2")
set(CMAKE_EXE_LINKER_FLAGS -pthread)

# Set include dir
include_directories(./gtest/include)

# Set Library dir
link_directories(./gtest/lib)

# Set source files for RELEASE target
set(METRO_SOURCE_FILES
        # Metro Files
        src/MetroSimulation.cpp
        src/TramStop.cpp
        src/Tram.cpp
        src/MetroXMLParser.cpp
        src/Track.cpp
        src/Line.cpp
        src/MetroSystem.cpp
        src/Logger.h
        src/MetroSystemOutput.cpp
        src/MetroSimStatistics.cpp
        )

set(TINY_XML_SOURCE_FILES
        # Set source files for tinyXml
        ./tinyxml/tinystr.cpp
        ./tinyxml/tinyxmlerror.cpp
        ./tinyxml/tinystr.cpp
        ./tinyxml/tinyxml.cpp
        ./tinyxml/tinyxmlparser.cpp
        )

set(TEST_SOURCE_FILES
        #Tests
        tst/TestParser.cpp
        tst/TestFuncs.h tst/TestSim.cpp
        tst/testf.cpp tst/TestOuput.cpp tst/LineTest.cpp tst/StatisticsTest.cpp tst/TramTest.cpp)

# Create RELEASE target
add_executable(main_executable src/main.cpp ${METRO_SOURCE_FILES}   ${TINY_XML_SOURCE_FILES})

# Create DEBUG target
add_executable(testing_tool tst/main.cpp ${METRO_SOURCE_FILES}  ${TINY_XML_SOURCE_FILES} ${TEST_SOURCE_FILES})

# Link library
target_link_libraries(testing_tool gtest)