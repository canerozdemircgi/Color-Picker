cmake_minimum_required(VERSION 4.0)

set(PROJECT_NAME Color-Picker)

project(${PROJECT_NAME} LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(QT_VERSION Qt6)
set(QT_COMPONENTS
	Widgets
	Network
	Svg
)
set(QT_LIBRARIES)
foreach(QT_COMPONENT ${QT_COMPONENTS})
	list(APPEND QT_LIBRARIES ${QT_VERSION}::${QT_COMPONENT})
endforeach()

set(OPENCV_VERSION OpenCV)
set(OPENCV_COMPONENTS
	core
)
set(OPENCV_LIBRARIES)
foreach(OPENCV_COMPONENT ${OPENCV_COMPONENTS})
	list(APPEND OPENCV_LIBRARIES $<LOWER_CASE:${OPENCV_VERSION}>_${OPENCV_COMPONENT})
endforeach()

set(BOOST_VERSION Boost)
set(BOOST_COMPONENTS
	json
)
set(BOOST_LIBRARIES)
foreach(BOOST_COMPONENT ${BOOST_COMPONENTS})
	list(APPEND BOOST_LIBRARIES ${BOOST_VERSION}::${BOOST_COMPONENT})
endforeach()

find_package(${QT_VERSION} CONFIG REQUIRED COMPONENTS ${QT_COMPONENTS})
find_package(${OPENCV_VERSION} CONFIG REQUIRED COMPONENTS ${OPENCV_COMPONENTS})
find_package(${BOOST_VERSION} CONFIG REQUIRED COMPONENTS ${BOOST_COMPONENTS})

qt_standard_project_setup()
set(QT_FORCE_CMP0156_TO_NEW ON)

file(GLOB_RECURSE PROJECT_FILES
	_Source/*.hpp
	_Source/*.cpp
	_Source/*.tpp
	_Source/*.ui
	_Source/*.qrc
	_Source/*.rc
)
qt_add_executable(${PROJECT_NAME} ${PROJECT_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE _Source)
target_compile_definitions(${PROJECT_NAME} PRIVATE QT_USE_QSTRINGBUILDER)
target_link_libraries(${PROJECT_NAME} PRIVATE
	${QT_LIBRARIES}
	${OPENCV_LIBRARIES}
	${BOOST_LIBRARIES}
)
set_target_properties(${PROJECT_NAME} PROPERTIES
	AUTOMOC ON
	AUTORCC ON
	AUTOUIC ON

	AUTOUIC_OPTIONS "--no-qt-namespace"

	WIN32_EXECUTABLE $<CONFIG:Release>

	UNITY_BUILD $<CONFIG:Release>
	INTERPROCEDURAL_OPTIMIZATION $<CONFIG:Release>
)

target_compile_options(${PROJECT_NAME} PRIVATE
	-Wall
	-Wextra
	-Wno-missing-field-initializers
	-Wno-switch

	$<$<CONFIG:Release>:
		-Ofast
		-march=x86-64-v3
		-mtune=generic
	>
)

set(EXTERNAL_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/_Source/_Resource/Style/ColorPicker.qss
	${CMAKE_CURRENT_SOURCE_DIR}/_Source/_Resource/Configuration/ColorPicker.json
)
set(EXTERNAL_DESTINATIONS
	${CMAKE_CURRENT_BINARY_DIR}/ColorPicker.qss
	${CMAKE_CURRENT_BINARY_DIR}/ColorPicker.json
)
add_custom_command(
	COMMENT "Updating external files."
	OUTPUT ${EXTERNAL_DESTINATIONS}
	COMMAND ${CMAKE_COMMAND} -E copy_if_different ${EXTERNAL_SOURCES} ${CMAKE_CURRENT_BINARY_DIR}/
	DEPENDS ${EXTERNAL_SOURCES}
)
add_custom_target(CopyExternal ALL DEPENDS ${EXTERNAL_DESTINATIONS})
add_dependencies(${PROJECT_NAME} CopyExternal)

set(INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Binary)
install(TARGETS ${PROJECT_NAME} DESTINATION ${INSTALL_DIR})
install(FILES ${EXTERNAL_SOURCES} DESTINATION ${INSTALL_DIR})