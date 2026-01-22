
set(FRAMELESSHELPER_BUILD_STATIC ON)
set(FRAMELESSHELPER_BUILD_QUICK OFF)
set(FRAMELESSHELPER_NO_INSTALL ON)
add_subdirectory("framelesshelper-2.5.0")
set_property(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/framelesshelper-2.5.0"
    PROPERTY FOLDER "FramelessWidget"
)

set(TGT framelesshelper)
add_library(framelesshelper INTERFACE)
target_link_libraries(${TGT}
    INTERFACE
    FramelessHelperCore
    FramelessHelperWidgets
)
set_property(TARGET framelesshelper PROPERTY FOLDER "FramelessWidget")


set(QWINDOWKIT_BUILD_STATIC ON)
set(QWINDOWKIT_BUILD_QUICK OFF)
set(QWINDOWKIT_INSTALL OFF)
add_subdirectory("qwindowkit-1.3.2")
set_property(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/qwindowkit-1.3.2"
    PROPERTY FOLDER "FramelessWidget"
)

set(TGT qwindowkit)
add_library(qwindowkit INTERFACE)
target_link_libraries(${TGT}
    INTERFACE
    QWKCore
    QWKWidgets
)
set_property(TARGET qwindowkit PROPERTY FOLDER "FramelessWidget")

add_subdirectory("qscintilla-2.14.0")
add_subdirectory("qrcode-1.4.0")
set_property(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/qscintilla-2.14.0"
    PROPERTY FOLDER "FramelessWidget"
)
set_property(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/qrcode-1.4.0"
    PROPERTY FOLDER "FramelessWidget"
)
