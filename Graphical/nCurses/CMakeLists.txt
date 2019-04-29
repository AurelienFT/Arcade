cmake_minimum_required(VERSION 3.5)

if (NOT ARCADE_HOME)
    message(FATAL_ERROR "Arcade home should be defined")
endif()

set(SOURCE_FILES
    "Srcs/Graphic.cpp"
    "Srcs/Window.cpp"
    "Srcs/Event.cpp"
    "Srcs/Text.cpp"
    "Srcs/Font.cpp"
    "Srcs/Vector2f.cpp"
    "Srcs/Vector2i.cpp"
    "Srcs/Texture.cpp"
    "Srcs/Sprite.cpp")

add_library(ncurses SHARED ${SOURCE_FILES})

set_target_properties(
    ncurses
    PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${ARCADE_HOME}/lib
    PREFIX "lib_arcade_"
)

target_link_libraries(ncurses Arcade_Interface)
target_link_libraries(
    ncurses
    -lncurses
)

target_include_directories(ncurses PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)