/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include <iostream>
#include <cstring>
#include <dlfcn.h>
#include <SFML/Graphics.hpp>
#include <arcade/interface/graphic/Keyboard.hpp>
#include <arcade/interface/graphic/IWindow.hpp>
#include "Button.hpp"

namespace arcade {
	class Menu {
		public:
			Menu(arcade::interface::graphic::WindowPtr window);
			~Menu();
			virtual bool create_elemt();
			virtual bool create_background();
			virtual bool create_title(const std::string style, const std::string txt);
			virtual bool display_menu();
			bool display_game();
			virtual bool loop_menu();
			bool display_options();
			std::string getLib() const;
			std::string getLib(int i) const;
			std::string getGame() const;
			std::string getGame(int i) const;
			std::string getPlayer() const;
			bool displayScore();
		protected:
		private:
			int32_t _index;
			int32_t _menu;
			arcade::interface::graphic::WindowPtr _window;
			arcade::interface::graphic::EventPtr _event;
			arcade::interface::graphic::SpritePtr _background;
			arcade::Button _play;
			arcade::Button _option;
			arcade::Button _score;
            		arcade::interface::graphic::TextPtr _title;
			std::string _is_game;
			std::string _is_lib;
			std::string _player;
			std::vector<std::string> _tab;
			std::vector<std::string> _libTab;
			bool _end;
			bool _enterPressed = false;
	};
}

#endif /*MENU_HPP*/
