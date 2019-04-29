/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Core
*/

#pragma once
#include <iostream>
#include <dlfcn.h>
#include "Menu.hpp"
#include "arcade/interface/graphic/Graphic.hpp"
#include "arcade/interface/IGame.hpp"
#include "DLLoader.hpp"

namespace arcade {
	class Core {
		public:
			enum coreState {
				MENU,
				GAME
			};
			Core(std::string lib);
			Core(Core const &) {};
			int run();
			~Core();
		protected:
		private:
			coreState _state;
			arcade::interface::graphic::WindowPtr _window;
			arcade::interface::GamePtr _game;
			DLLoader _loader;
	};
}