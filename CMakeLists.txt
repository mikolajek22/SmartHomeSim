cmake_minimum_required(VERSION 3.10)
project(SmartHomeSimulator)

# set the c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

include_directories(include include/gui)

set(SOURCES
    src/main.cpp
    src/smartDevice.cpp
    src/logger.cpp
    src/smartManager.cpp
    src/smartBulb.cpp
    src/appMenu.cpp
    src/appGui.cpp
)

# for MOC
set(HEADERS
    include/gui/guiBasePage.h
    include/gui/guiPageMain.h
    include/gui/guiPageConfig.h
    include/gui/guiPageControl.h
)
#generate MOC for Q_OBJECT
qt5_wrap_cpp(MOC_SOURCES ${HEADERS})

add_executable(SmartHomeSimulator ${SOURCES} ${MOC_SOURCES})
target_link_libraries(SmartHomeSimulator Qt5::Core Qt5::Gui Qt5::Widgets)
# set_target_properties(SmartHomeSimulator PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})