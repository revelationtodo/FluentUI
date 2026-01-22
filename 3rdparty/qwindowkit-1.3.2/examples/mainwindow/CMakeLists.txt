project(QWKExample_MainWindow)

file(GLOB _src *.h *.cpp)

qwk_add_example(${PROJECT_NAME}
    FEATURES cxx_std_17
    SOURCES ${_src} mainwindow.qrc ../shared/resources/shared.qrc
    QT_LINKS Core Gui Widgets # MultimediaWidgets
    LINKS QWKWidgets WidgetFrame
)

if(MSVC)
    get_property(_t DIRECTORY PROPERTY BUILDSYSTEM_TARGETS)

    foreach(tgt IN LISTS _t)
        if(TARGET "${tgt}")
            set_target_properties("${tgt}" PROPERTIES FOLDER Dependencies/QWindowKit)
        endif()
    endforeach()
endif()