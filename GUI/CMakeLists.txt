cmake_minimum_required(VERSION 3.5)

project(PSE_GUI VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-std=c++98 -Wall -Werror -O2")
set(CMAKE_EXE_LINKER_FLAGS -pthread)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "/Users/cedric/Qt/6.5.0/macos/lib/cmake")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main_GUI.cpp
        mainwindow.cpp
        mainwindow.ui
        SimThread.cpp
        GUI_MetroSimulation.cpp)

set(METRO_SOURCE_FILES
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
        ../src/MetroRenderer.cpp
        ../src/MetroSimStatistics.cpp)

set(TINY_XML_SOURCE_FILES
        # Set source files for tinyXml
        ../tinyxml/tinystr.cpp
        ../tinyxml/tinyxmlerror.cpp
        ../tinyxml/tinystr.cpp
        ../tinyxml/tinyxml.cpp
        ../tinyxml/tinyxmlparser.cpp
        )

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SimGUI
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
            ${METRO_SOURCE_FILES}
            ${TINY_XML_SOURCE_FILES}
            )
    # Define target properties for Android with Qt 6 as:
    #    set_property(TARGET SimGUI APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
    #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
    # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(SimGUI SHARED
                ${PROJECT_SOURCES}
                )
        # Define properties for Android with Qt 5 after find_package() calls as:
        #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(SimGUI
                ${PROJECT_SOURCES}
                ${METRO_SOURCE_FILES}
                ${TINY_XML_SOURCE_FILES}
                )
    endif()
endif()

target_link_libraries(SimGUI PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(SimGUI PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
        )

install(TARGETS SimGUI
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SimGUI)
endif()
