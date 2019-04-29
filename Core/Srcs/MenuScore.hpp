/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** MenuScore
*/

#ifndef MENUSCORE_HPP_
#define MENUSCORE_HPP_
#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <dlfcn.h>
#include <arcade/interface/graphic/IWindow.hpp>
#include "Button.hpp"
#include "Menu.hpp"

#ifndef _POSIX_SOURCE
# define _POSIX_SOURCE
#endif
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#undef _POSIX_SOURCE
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <fstream>

namespace arcade {
    class MenuScore {
	    public:
		    MenuScore(arcade::interface::graphic::WindowPtr window);
		    ~MenuScore() = default;
            void createBackground();
            void findGame();
            void loopScore();
            void displayScore();
            void printArrows();
            void printButton();
            void displayMenu();
            void eventRight();
            void eventLeft();
            void eventManager();
            std::string parseGame(std::string str);
            void findScore(std::string game, int32_t index);
            
	    protected:
	    private:
            bool _end = false;
			size_t _nbGame;
			int32_t _index = 0;
			int32_t _arrowIndex = 0;
        	arcade::interface::graphic::SpritePtr _background;
			arcade::interface::graphic::WindowPtr _window;
			arcade::interface::graphic::EventPtr _event;
			arcade::Button _game;
            arcade::Button _leftArrow;
            arcade::Button _rightArrow;
			std::vector<std::string> _tabGame;
            std::vector<std::vector<std::string>> _tabScore;
	};
}

#endif /* !MENUSCORE_HPP_ */
