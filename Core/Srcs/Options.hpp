/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Options
*/

#ifndef OPTIONS_HPP_
#define OPTIONS_HPP_

#pragma once
#include <iostream>
#include <dlfcn.h>
#include <arcade/interface/graphic/Keyboard.hpp>
#include <arcade/interface/graphic/IWindow.hpp>
#include "Button.hpp"
#include <SFML/Graphics.hpp>
#include <cstring>

class Options {
	public:
		Options(arcade::interface::graphic::WindowPtr window);
		~Options() = default;
		bool createBackground();
		bool createTitle(const std::string style, const std::string txt);
		bool optionsLoop();
		bool optionsDisplay();
		void printArrows();
		bool arrowsManager();
		void eventRight();
		void eventLeft();
		void printButton();
		void submenu();
		void fpsManage();
		void soundManage();
		void libManage();

	protected:
	private:
		int32_t _sound;
		int32_t _fps;
		int32_t _index;
		int32_t _nb_option;
		bool _left;
		bool _right;
		bool _end;
		int32_t _validate;
		std::vector<std::string> _tab_options;
		std::vector<std::string> _tab_lib;
		arcade::interface::graphic::SpritePtr _o_background;
		arcade::interface::graphic::WindowPtr _o_window;
		arcade::interface::graphic::EventPtr _event;
		arcade::interface::graphic::TextPtr _o_title;
		arcade::Button _options;
		arcade::Button _l_arrow;
		arcade::Button _r_arrow;
};

#endif /* !OPTIONS_HPP_ */
