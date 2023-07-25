cmake_minimum_required(VERSION 3.13)

set(PROJECT_NAME "ColorPickerUD+")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "C:/msys64/mingw64/lib/cmake")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

project(${PROJECT_NAME})

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
find_package(OpenCV REQUIRED)

file(GLOB_RECURSE PROJECT_FILES "_Source/*.h" "_Source/*.cpp" "_Source/*.qrc" "_Source/*.rc")
add_executable(${PROJECT_NAME} WIN32 ${PROJECT_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE "_Source")
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::Widgets ${OpenCV_LIBS})