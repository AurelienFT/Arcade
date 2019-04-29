cmake_minimum_required(VERSION 3.5)

if (NOT ARCADE_HOME)
    message(FATAL_ERROR "Arcade home should be defined")
endif()

set(SOURCE_FILES
    "Srcs/Bonus.cpp"
    "Srcs/Enemy.cpp"
    "Srcs/Game.cpp"
    "Srcs/Player.cpp"
    "Srcs/Shoot.cpp"
    "Srcs/ScoreSolarFox.cpp"
    "../Pause.cpp"
    "../Score.cpp"
    "../EndMenu.cpp")

add_library(solarfox SHARED ${SOURCE_FILES})

set_target_properties(
    solarfox
    PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${ARCADE_HOME}/games
    PREFIX "lib_arcade_"
)

target_link_libraries(solarfox Arcade_Interface)