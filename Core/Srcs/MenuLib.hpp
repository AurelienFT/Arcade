/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** MenuLib
*/

#ifndef MENULIB_HPP_
#define MENULIB_HPP_

#pragma onced
#include <vector>
#include <string>
#include <iostream>
#include <dlfcn.h>
#include <arcade/interface/graphic/IWindow.hpp>
#include "Button.hpp"
#include "MenuGame.hpp"

class MenuLib : public MenuGame {
	public:
		MenuLib(arcade::interface::graphic::WindowPtr window);
		~MenuLib() = default;
		bool create_elemt();
		bool create_background();
		bool create_title(const std::string style, const std::string txt);
		bool display_menu();
		bool display_game();
		bool loop_menu();
		bool find_game();
		bool event_manager();
		void print_button();
		void print_arrows();
		void event_left();
		void event_right();
		std::string getLib();
		bool diplay_name();
		std::string getPlayer();
		std::vector<std::string> getLibs() const;
	protected:
	private:
		bool _end;
		size_t _nb_lib;
		int32_t _index;
		int32_t _a_index;
		int32_t  _go_game;
		std::string _player;
        arcade::interface::graphic::SpritePtr _l_background;
		arcade::interface::graphic::WindowPtr _l_window;
		arcade::interface::graphic::EventPtr _event;
		arcade::interface::graphic::TextPtr _l_title;
		arcade::Button _lib;
		arcade::Button _l_arrow;
		arcade::Button _r_arrow;
		std::vector<std::string> _tab_lib;
		std::string _is_lib;
		bool _enterPressed = false;
};

#endif /* !MENULIB_HPP_ */
