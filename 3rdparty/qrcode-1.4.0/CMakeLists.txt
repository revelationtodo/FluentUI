set (TGT qrcode)

if(NOT DEFINED CMAKE_DEBUG_POSTFIX)
if(WIN32)
    set(CMAKE_DEBUG_POSTFIX "d")
endif()
endif()

add_library(${TGT} STATIC
    QrCode.cpp
    QrCode.hpp
)
target_include_directories(${TGT} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if(MSVC)
    get_property(_t DIRECTORY PROPERTY BUILDSYSTEM_TARGETS)

    foreach(tgt IN LISTS _t)
        if(TARGET "${tgt}")
            set_target_properties("${tgt}" PROPERTIES FOLDER Dependencies/QrCode)
        endif()
    endforeach()
endif()
