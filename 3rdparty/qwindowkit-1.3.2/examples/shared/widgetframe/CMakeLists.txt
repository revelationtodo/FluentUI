project(WidgetFrame)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

file(GLOB _src *.h *.cpp)

add_library(${PROJECT_NAME} STATIC)

qm_configure_target(${PROJECT_NAME}
    FEATURES cxx_std_17
    SOURCES ${_src}
    QT_LINKS Core Gui Widgets
)

target_include_directories(${PROJECT_NAME} PUBLIC . ..)

if(MSVC)
    get_property(_t DIRECTORY PROPERTY BUILDSYSTEM_TARGETS)

    foreach(tgt IN LISTS _t)
        if(TARGET "${tgt}")
            set_target_properties("${tgt}" PROPERTIES FOLDER Dependencies/QWindowKit)
        endif()
    endforeach()
endif()