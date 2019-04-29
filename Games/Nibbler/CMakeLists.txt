cmake_minimum_required(VERSION 3.5)

if (NOT ARCADE_HOME)
    message(FATAL_ERROR "Arcade home should be defined")
endif()

set(SOURCE_FILES
    "Srcs/Game.cpp"
    "Srcs/Head.cpp"
    "Srcs/Snake.cpp"
    "Srcs/ScoreNibbler.cpp"
    "../Pause.cpp"
    "../Score.cpp"
    "../EndMenu.cpp")

add_library(nibbler SHARED ${SOURCE_FILES})

set_target_properties(
    nibbler
    PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${ARCADE_HOME}/games
    PREFIX "lib_arcade_"
)

target_link_libraries(nibbler Arcade_Interface)