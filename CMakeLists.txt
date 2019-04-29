cmake_minimum_required(VERSION 3.5)

set(ARCADE_HOME ${CMAKE_CURRENT_SOURCE_DIR})

set (CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g3)

add_subdirectory("${ARCADE_HOME}/Interface")
add_subdirectory("${ARCADE_HOME}/Core")
add_subdirectory("${ARCADE_HOME}/Graphical/SFML")
add_subdirectory("${ARCADE_HOME}/Graphical/SDL2")
add_subdirectory("${ARCADE_HOME}/Graphical/nCurses")
add_subdirectory("${ARCADE_HOME}/Games/Nibbler")
add_subdirectory("${ARCADE_HOME}/Games/SolarFox")

add_custom_target(
    core
    DEPENDS arcade
)

add_custom_target(
    graphicals
    DEPENDS sfml
    DEPENDS ncurses
    DEPENDS sdl2
)

add_custom_target(
    games
    DEPENDS nibbler
    DEPENDS solarfox
)

add_custom_target(
    fclean
    COMMAND rm -rf ${ARCADE_HOME}/lib
    COMMAND rm -rf ${ARCADE_HOME}/games
)

add_custom_target(
    re
    DEPENDS fclean
    DEPENDS all
)