cmake_minimum_required(VERSION 3.5)

if (NOT ARCADE_HOME)
    message(FATAL_ERROR "Arcade home should be defined")
endif()

set(SOURCE_FILES
    "Srcs/Main.cpp"
    "Srcs/Core.cpp"
    "Srcs/Menu.cpp"
    "Srcs/Button.cpp"
    "Srcs/DLLoader.cpp"
    "Srcs/MenuGame.cpp"
    "Srcs/MenuLib.cpp"
    "Srcs/Options.cpp"
    "Srcs/Submenu.cpp"
    "Srcs/MenuName.cpp"
    "Srcs/MenuScore.cpp")

add_executable(arcade ${SOURCE_FILES})

set_target_properties(
    arcade
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${ARCADE_HOME}
)

target_link_libraries(arcade PUBLIC Arcade_Interface dl)