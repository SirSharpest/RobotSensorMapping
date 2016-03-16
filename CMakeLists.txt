cmake_minimum_required(VERSION 2.6)
project(CS22510)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")


# Define sources and executable
set(EXECUTABLE_NAME "CS22510")

set(SOURCE_FILES src/main.cpp src/grid.cpp src/headers/grid.hpp src/dataManager.cpp src/headers/dataManager.hpp  src/sensorData.cpp src/headers/sensorData.hpp )
add_executable(CS22510 ${SOURCE_FILES})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)


# CPack packaging
include(InstallRequiredSystemLibraries)
