/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Cores
*/

#include <SFML/Graphics/Color.hpp>
#include "arcade/interface/ResourceAllocator.hpp"
#include "arcade/interface/graphic/Keyboard.hpp"
#include "Core.hpp"

arcade::Core::Core(std::string lib)
{
	arcade::interface::graphic::GLibPtr (*getGraphicalLibrary)();

	getGraphicalLibrary = (arcade::interface::graphic::GLibPtr(*)()) _loader.openGraphicLib(lib);
	arcade::interface::ResourceAllocator::instance()->setGLib(getGraphicalLibrary());
	_state = arcade::Core::MENU;
	_window = arcade::interface::ResourceAllocator::instance()->createWindow();
}

int arcade::Core::run()
{
	int i = 0;
	int j = 0;
	arcade::interface::graphic::EventPtr event;
	arcade::Menu startMenu(_window);
	startMenu.loop_menu();
	std::string game = "games/lib_arcade_" + startMenu.getGame() + ".so";

	arcade::interface::GamePtr (*getGameLibrary)();
	getGameLibrary = (arcade::interface::GamePtr(*)()) _loader.openGameLib(game);
	_game = std::move(getGameLibrary());

	arcade::interface::graphic::GLibPtr (*getGraphicalLibrary)();
	getGraphicalLibrary = (arcade::interface::graphic::GLibPtr(*)()) _loader.openGraphicLib("lib/lib_arcade_" + startMenu.getLib() + ".so");

	arcade::interface::ResourceAllocator::instance()->setGLib(getGraphicalLibrary());
	delete _window.get();
	_window = arcade::interface::ResourceAllocator::instance()->createWindow();
	_game->init(arcade::interface::ResourceAllocator::instance(), _window);
	while (_window->isOpen() && _game->isRunning()) {
		_window->clear();
		while(_window->processEvent()) {
			_game->handleEvent();
			event = _window->getCurrentEvent();
			if (!event)
				continue;
			if (event->getType() == arcade::interface::graphic::IEvent::EventType::OnClosed)
				exit (0);
			if (event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyPressed
			&& event->getKey() == arcade::interface::graphic::Key::C) {
				//getGraphicalLibrary = (arcade::interface::graphic::GLibPtr(*)()) _loader.openGraphicLib("lib/lib_arcade_sdl2.so");
				//arcade::interface::ResourceAllocator::instance()->copy(getGraphicalLibrary());
			}
			if (event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyPressed
			&& event->getKey() == arcade::interface::graphic::Key::P) {
				i++;
				game = "games/lib_arcade_" + startMenu.getGame(i) + ".so";
				getGameLibrary = (arcade::interface::GamePtr(*)()) _loader.openGameLib(game);
				_game = std::move(getGameLibrary());
				_game->init(arcade::interface::ResourceAllocator::instance(), _window);
			}
			if (event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyPressed
			&& event->getKey() == arcade::interface::graphic::Key::N) {
				i--;
				game = "games/lib_arcade_" + startMenu.getGame(i) + ".so";
				getGameLibrary = (arcade::interface::GamePtr(*)()) _loader.openGameLib(game);
				_game = std::move(getGameLibrary());
				_game->init(arcade::interface::ResourceAllocator::instance(), _window);
			}
			if (event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyPressed
			&& event->getKey() == arcade::interface::graphic::Key::L) {
				j++;
				std::cout << "lib name " << startMenu.getLib(j) << std::endl;
				delete _window.get();
				getGraphicalLibrary = (arcade::interface::graphic::GLibPtr(*)()) _loader.openGraphicLib("lib/lib_arcade_" + startMenu.getLib(j) + ".so");
				arcade::interface::ResourceAllocator::instance()->setGLib(getGraphicalLibrary());
				_window = arcade::interface::ResourceAllocator::instance()->createWindow();
				_game = std::move(getGameLibrary());
				_game->init(arcade::interface::ResourceAllocator::instance(), _window);
				continue;
			}
			if (event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyPressed
			&& event->getKey() == arcade::interface::graphic::Key::M) {
				j--;
				std::cout << "lib name " << startMenu.getLib(j) << std::endl;
				delete _window.get();
				getGraphicalLibrary = (arcade::interface::graphic::GLibPtr(*)()) _loader.openGraphicLib("lib/lib_arcade_" + startMenu.getLib(j) + ".so");
				arcade::interface::ResourceAllocator::instance()->setGLib(getGraphicalLibrary());
				_window = arcade::interface::ResourceAllocator::instance()->createWindow();
				_game = std::move(getGameLibrary());
				_game->init(arcade::interface::ResourceAllocator::instance(), _window);
				continue;
			}
		}
		_game->refresh();
		_window->display();
	}
	run();
}

arcade::Core::~Core()
{
}