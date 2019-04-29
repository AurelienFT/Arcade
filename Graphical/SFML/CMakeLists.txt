cmake_minimum_required(VERSION 3.5)

if (NOT ARCADE_HOME)
    message(FATAL_ERROR "Arcade home should be defined")
endif()

set(SOURCE_FILES
    "Srcs/Graphic.cpp"
    "Srcs/Vector2i.cpp"
    "Srcs/Window.cpp"
    "Srcs/Text.cpp"
    "Srcs/Event.cpp"
    "Srcs/Vector2f.cpp"
    "Srcs/Font.cpp"
    "Srcs/Texture.cpp"
    "Srcs/Sprite.cpp"
    "Srcs/Rectangle.cpp")

add_library(sfml SHARED ${SOURCE_FILES})

set_target_properties(
    sfml
    PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${ARCADE_HOME}/lib
    PREFIX "lib_arcade_"
)

target_link_libraries(sfml Arcade_Interface)
target_link_libraries(
    sfml
    "sfml-graphics"
    "sfml-window"
    "sfml-system"
)

target_include_directories(sfml PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)