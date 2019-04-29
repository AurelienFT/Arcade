/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Submenu
*/

#ifndef SUBMENU_HPP_
#define SUBMENU_HPP_

#pragma once
#include <iostream>
#include <dlfcn.h>
#include <arcade/interface/graphic/Keyboard.hpp>
#include <arcade/interface/graphic/IWindow.hpp>
#include "Button.hpp"
#include <SFML/Graphics.hpp>
#include <cstring>

class Submenu {
	public:
		Submenu(arcade::interface::graphic::WindowPtr window, const std::string options, int32_t nb_option);
		~Submenu() = default;
		bool createBackground();
		bool createTitle(const std::string style, const std::string txt);
		bool submenuLoop();
		bool optionsDisplay();
		void printArrows();
		bool arrowsManager();
		void eventRight();
		void eventLeft();
		void printButton();
		int32_t getValue();
	
	protected:
	private:
		arcade::Button _option;
        arcade::Button _l_arrow;
		arcade::Button _r_arrow;
		int32_t _index;
		int32_t _value;
		bool _left;
		bool _right;
		bool _validate;
		bool _end;
		arcade::interface::graphic::SpritePtr _background;
		arcade::interface::graphic::WindowPtr _window;
		arcade::interface::graphic::EventPtr _event;
		arcade::interface::graphic::TextPtr _title;
};

#endif /* !SUBMENU_HPP_ */
