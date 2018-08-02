find_program(QT_UIC_PATH uic)
find_program(QT_RCC_PATH rcc )
find_program(QT_MOC_PATH moc)
if (${QT_UIC_PATH} STREQUAL QT_UIC_PATH-NOTFOUND)
    message(FATAL_ERROR "Qt form compiler (uic) not found, building the project will not be possible and was therefore stopped")
endif ()
if (${QT_RCC_PATH} STREQUAL QT_RCC_PATH-NOTFOUND)
    message(FATAL_ERROR "Qt resource compiler (rcc) not found, building the project will not be possible and was therefore stopped")
endif ()
if (${QT_MOC_PATH} STREQUAL QT_MOC_PATH-NOTFOUND)
    message(FATAL_ERROR "Qt meta object compiler (moc) not found, building the project will not be possible and was therefore stopped")
endif ()

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)

include_directories(${Qt5Core_INCLUDE_DIRS})
include_directories(${Qt5Widgets_INCLUDE_DIRS})
include_directories(${Qt5Gui_INCLUDE_DIRS})

add_definitions(${Qt5Core_DEFINITIONS})
add_definitions(${Qt5Widgets_DEFINITIONS})
add_definitions(${Qt5Gui_DEFINITIONS})


function (qt_add_moc_files output_var)
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/moc)
    foreach (src_file ${ARGN})
        file (READ ${SOURCE_DIR}/${src_file} file)
        if ("${file}" MATCHES "Q_OBJECT")
            get_filename_component(out_name ${src_file} NAME_WE)
            add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/moc/${out_name}.moc.cpp
                               COMMAND ${QT_MOC_PATH} -o ${CMAKE_CURRENT_BINARY_DIR}/moc/${out_name}.moc.cpp ${SOURCE_DIR}/${src_file} --no-notes
                               DEPENDS ${SOURCE_DIR}/${src_file})
            set(moc_output ${moc_output} ${CMAKE_CURRENT_BINARY_DIR}/moc/${out_name}.moc.cpp)
        endif ()
    endforeach ()
    SET(${output_var} "${moc_output}" PARENT_SCOPE)
endfunction ()

function (qt_add_uic_files output_var)
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/ui)
    foreach (gui_file ${ARGN})
        add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/ui/${gui_file}.h
                           COMMAND ${QT_UIC_PATH} -o ${CMAKE_CURRENT_BINARY_DIR}/ui/${gui_file}.h ${UI_DIR}/${gui_file}
                           DEPENDS ${UI_DIR}/${gui_file})
        set(uic_output ${uic_output} ${CMAKE_CURRENT_BINARY_DIR}/ui/${gui_file}.h)
    endforeach ()
    SET(${output_var} "${uic_output}" PARENT_SCOPE)
endfunction()
