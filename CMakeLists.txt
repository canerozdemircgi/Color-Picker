cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME "Color-Picker")
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

project(${PROJECT_NAME})

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)
find_package(OpenCV REQUIRED)

file(GLOB_RECURSE PROJECT_FILES "_Source/*.h" "_Source/*.cpp" "_Source/*.qrc" "_Source/*.rc")
add_executable(${PROJECT_NAME} WIN32 ${PROJECT_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE "_Source")
target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Gui Qt6::Widgets ${OpenCV_LIBS})