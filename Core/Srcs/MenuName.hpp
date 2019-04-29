/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** MenuName
*/

#ifndef MENUNAME_HPP_
#define MENUNAME_HPP_
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include "Button.hpp"
#include <arcade/interface/graphic/Keyboard.hpp>
#include <arcade/interface/graphic/IWindow.hpp>

namespace arcade {
    class MenuName {
	    public:
	    MenuName(interface::graphic::WindowPtr window);
		~MenuName() = default;
        bool createBackground();
        bool createTitle(const std::string style, const std::string txt);
        bool nameBuild();
        bool loop();
        void display();
        std::string getName();
	protected:
	private:
        std::string _name;
        arcade::Button _button;
        arcade::interface::graphic::EventPtr _event;
		arcade::interface::graphic::TextPtr _title;
        arcade::interface::graphic::SpritePtr _background;
		arcade::interface::graphic::WindowPtr _window;
        bool _end;
        bool _is_writting;
    };
}

#endif /* !MENUNAME_HPP_ */
