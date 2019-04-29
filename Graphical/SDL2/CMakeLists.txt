cmake_minimum_required(VERSION 3.5)

if (NOT ARCADE_HOME)
    message(FATAL_ERROR "Arcade home should be defined")
endif()

set(SOURCE_FILES
    "Srcs/Graphic.cpp"
    "Srcs/Vector2i.cpp"
    "Srcs/Window.cpp"
    "Srcs/Vector2f.cpp"
    "Srcs/Event.cpp"
    "Srcs/Font.cpp"
    "Srcs/Text.cpp"
    "Srcs/Texture.cpp"
    "Srcs/Sprite.cpp"
    "Srcs/Rectangle.cpp"
)

add_library(sdl2 SHARED ${SOURCE_FILES})

set_target_properties(
    sdl2
    PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${ARCADE_HOME}/lib
    PREFIX "lib_arcade_"
)

target_link_libraries(sdl2 Arcade_Interface)
target_link_libraries(
    sdl2
    "-lSDL2_ttf"
    "SDL2"
    "freetype"
    "-lSDL2_image"
)

target_include_directories(sdl2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)