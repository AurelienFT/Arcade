/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** MenuGame
*/

#ifndef MENUGAME_HPP_
#define MENUGAME_HPP_

#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <dlfcn.h>
#include <arcade/interface/graphic/IWindow.hpp>
#include "Button.hpp"
#include "Menu.hpp"

class MenuGame : public arcade::Menu {
	public:
		MenuGame(arcade::interface::graphic::WindowPtr window);
		~MenuGame() = default;
		virtual bool create_elemt();
		virtual bool create_background();
		virtual bool create_title(const std::string style, const std::string txt);
		virtual bool display_menu();
		virtual bool loop_menu();
		virtual bool find_game();
		virtual bool event_manager();
		virtual void print_button();
		virtual void print_arrows();
		virtual void event_left();
		virtual void event_right();
		virtual std::string parse_game(std::string name);
		bool goLib();
		virtual std::string getLib();
		virtual std::vector<std::string> getLibs() const;
		std::string getGame() const;
		std::vector<std::string> getGames() const;
		std::string getPlayer() const;

	protected:
	private:
		bool _end;
		size_t _nb_game;
		int32_t _index;
		int32_t _a_index;
		int32_t _go_lib;
		std::string _player;
		arcade::interface::graphic::SpritePtr _g_background;
		arcade::interface::graphic::WindowPtr _g_window;
		arcade::interface::graphic::EventPtr _event;
		arcade::interface::graphic::TextPtr _g_title;
		arcade::Button _game;
		arcade::Button _l_arrow;
		arcade::Button _r_arrow;
		std::vector<std::string> _tab_game;
		std::vector<std::string> _tabLib;
		std::string _is_game;
		std::string _is_lib;
		bool _enterPressed = false;
};

#endif /* !MENUGAME_HPP_ */