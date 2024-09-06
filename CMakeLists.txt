cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME "Color-Picker")

project(${PROJECT_NAME} LANGUAGES CXX)

set(QT_VERSION_MAJOR 6)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets)
find_package(OpenCV REQUIRED)

file(GLOB_RECURSE PROJECT_FILES "_Source/*.h" "_Source/*.cpp" "_Source/*.ui" "_Source/*.qrc" "_Source/*.rc")
qt_add_executable(${PROJECT_NAME} ${PROJECT_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE "_Source")
target_link_libraries(${PROJECT_NAME} PRIVATE
	Qt${QT_VERSION_MAJOR}::Core
	Qt${QT_VERSION_MAJOR}::Gui
	Qt${QT_VERSION_MAJOR}::Widgets
	${OpenCV_LIBS}
)
set_target_properties(${PROJECT_NAME} PROPERTIES
	AUTOMOC ON
	AUTOUIC ON
	AUTORCC ON
	WIN32_EXECUTABLE TRUE
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

set(PROJECT_CL_OPTIONS "-Ofast;-flto;-march=x86-64-v3;-mtune=generic")
target_compile_options(${PROJECT_NAME} PRIVATE $<$<CONFIG:Release>:${PROJECT_CL_OPTIONS}>)
target_link_options(${PROJECT_NAME} PRIVATE $<$<CONFIG:Release>:${PROJECT_CL_OPTIONS}>)

install(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/Binary
)