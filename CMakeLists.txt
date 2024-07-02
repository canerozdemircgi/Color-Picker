cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME "Color-Picker")

project(${PROJECT_NAME})

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)
find_package(OpenCV REQUIRED)

file(GLOB_RECURSE PROJECT_FILES "_Source/*.h" "_Source/*.cpp" "_Source/*.qrc" "_Source/*.rc")
add_executable(${PROJECT_NAME} ${PROJECT_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE "_Source")
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets ${OpenCV_LIBS})

set_target_properties(${PROJECT_NAME} PROPERTIES
	AUTOMOC ON
	AUTOUIC ON
	AUTORCC ON
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

set(PROJECT_CL_OPTIONS "-Ofast;-flto;-march=x86-64-v3;-mtune=generic")
target_compile_options(${PROJECT_NAME} PRIVATE $<$<CONFIG:Release>:${PROJECT_CL_OPTIONS}>)
target_link_options(${PROJECT_NAME} PRIVATE $<$<CONFIG:Release>:${PROJECT_CL_OPTIONS}>)