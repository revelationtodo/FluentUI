cmake_minimum_required(VERSION 3.20)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${PROJECT_BINARY_DIR}/bin")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Svg Charts Core5Compat)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Svg Charts Core5Compat)

if (USE_QRC)
if (MSVC_IDE)
	message(STATUS "Qt6Widgets_LIBRARIES: ${Qt6Widgets_LIBRARIES}")
	get_target_property(V_LOCATION ${Qt6Widgets_LIBRARIES} IMPORTED_LOCATION)
	message(STATUS "V_LOCATION: ${V_LOCATION}")
	cmake_path(GET V_LOCATION PARENT_PATH V_RUN_PATH)
	message(STATUS "V_RUN_PATH: ${V_RUN_PATH}")
	set(CMAKE_VS_DEBUGGER_ENVIRONMENT "PATH=%PATH%;${V_RUN_PATH}")
	message(STATUS "CMAKE_VS_DEBUGGER_ENVIRONMENT: ${CMAKE_VS_DEBUGGER_ENVIRONMENT}")
endif()
endif()

# qt_standard_project_setup()

add_subdirectory("3rdparty")
add_subdirectory("FluControls")
add_subdirectory("FluUtils")
# add_subdirectory("res")
# add_subdirectory("StyleSheet")

install(DIRECTORY res
    DESTINATION .
)

install(DIRECTORY StyleSheet
    DESTINATION .
)

install(DIRECTORY code
    DESTINATION .
)

set(CPACK_SYSTEM_NAME ${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR})
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    string(APPEND CPACK_SYSTEM_NAME "-debug")
endif()

include(InstallRequiredSystemLibraries)
set(CPACK_GENERATOR "ZIP")
include(CPack)

message(STATUS "Configuration Options Summary --
    Target system:          ${CMAKE_SYSTEM}
    Compiler:
        Build type:         ${CMAKE_BUILD_TYPE}
        C compiler:         ${CMAKE_C_COMPILER}
        Qt version:         ${QT_DEFAULT_MAJOR_VERSION}
        Qt toolchain:       ${QT_QMAKE_EXECUTABLE}")
