/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Game
*/

//temp
#include <iostream>

#include "../../../Core/Srcs/Core.hpp"
#include "Game.hpp"

arcade::SolarFox::Game::Game()
{
}

arcade::SolarFox::Game::~Game()
{
}

void arcade::SolarFox::Game::init(arcade::interface::ResourceAllocator *manager, const arcade::interface::graphic::WindowPtr &window)
{
	srand(time(NULL));
	_window = window;
	_manager = manager;
	arcade::interface::graphic::FontPtr font;
    arcade::interface::graphic::TextPtr text;
	_endMenu.init(_manager, _window);
	_pause.init(_manager, _window);
	_player.init(_manager, _window);
	_bonus.init(_manager, _window, "map.txt");
	_enemies.init(_manager, _window);
	_wallTexture = _manager->createTexture("wall1.png");
	_wallVertTexture = _manager->createTexture("wallVert.png");
	_walls.push_back(_manager->createSprite(_wallTexture));
	_walls[_walls.size() - 1]->setPosition(100, 200);
	_walls.push_back(_manager->createSprite(_wallTexture));
	_walls[_walls.size() - 1]->setPosition(100, _window->getSize()->getY() - 100);
	_walls.push_back(_manager->createSprite(_wallVertTexture));
	_walls[_walls.size() - 1]->setPosition(100, 200);
	_walls.push_back(_manager->createSprite(_wallVertTexture));
	_walls[_walls.size() - 1]->setPosition(_window->getSize()->getX() - 100, 200);
	font = _manager->createFont("neon2.ttf");	
    _score_text = _manager->createText(font);
	_score_text->setString(std::to_string(_score));
}

void arcade::SolarFox::Game::handleEvent()
{
	if (_end) {
		_endMenu.refresh();
		return;
	}
	arcade::interface::graphic::EventPtr event = _window->getCurrentEvent();
	if (event) {
		if (_isPaused && _pause.handleEvent() == 1)
			_isPaused = false;
		if (_pause.handleEvent() == 3) {
			_isPaused = false;
			init(_manager, _window);
		}
		else if (_isPaused && _pause.handleEvent() == 2)
			_isRunning = false;
		else if (event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyPressed) {
			arcade::interface::graphic::Key key = event->getKey(); 
			if (key == arcade::interface::graphic::Key::Left)
				_direction = 1;
			else if (key == arcade::interface::graphic::Key::Right)
				_direction = 2;
			else if (key == arcade::interface::graphic::Key::Up)
				_direction = 3;
			else if (key == arcade::interface::graphic::Key::Down)
				_direction = 4;
			else if (key == arcade::interface::graphic::Key::Space)
				_player.shoot();
			else if (key == arcade::interface::graphic::Key::Escape)
				_isPaused = true;
		}
	}
}

void arcade::SolarFox::Game::move()
{
	_player.move(_direction);
	_enemies.move();
	if (detection(_player.getShoot().getShoot(), _bonus.getBonus())) {
		_player.hit();
		_score += 1;
		_bonus.hit(_listHit);
		if (_bonus.getBonus().size() == 0) {
			_end = true;
		}
	}
	if (detection(_player.getShoot().getShoot(), _enemies.getShoots())) {
		_player.getShoot().reset();
		_enemies.hit(_listHit);
	}
	if (detection(_player.getShoot().getShoot(), _enemies.getShootsDown())) {
		_player.getShoot().reset();
		_enemies.hitDown(_listHit);
	}
	if (detection(_player.getPlayer(), _enemies.getShoots()) || detection(_player.getPlayer(), _enemies.getShootsDown())) {
		_end = true;
	}
}

void arcade::SolarFox::Game::pause()
{
	_pause.refresh();
	_bonus.draw();
	_player.draw();
	_enemies.draw();
}

void arcade::SolarFox::Game::end()
{
	_endMenu.refresh();
	if (_endMenu.isEnd()) {
		_isRunning = false;
		_scores.saveScore(_score, _endMenu.getName().c_str(), "scores/SolarFox.txt");
	}
	_bonus.draw();
	_player.draw();
	_enemies.draw();
}

void arcade::SolarFox::Game::refresh()
{
	if (_isPaused) {
		pause();
		return;
	}
	if (_end) {
		end();
		return;
	}
	else if (_isRunning)
		move();
	_bonus.draw();
	_score_text->setString("SCORE :");
	_score_text->setPosition(60, 60);
	_window->draw(_score_text);
	_score_text->setString(std::to_string(_score));
	_score_text->setPosition(220, 60);
	_window->draw(_score_text);
	_player.draw();
	_enemies.draw();
	for (auto i = 0; i < _walls.size(); i++)
		_window->draw(_walls[i]);
}

bool arcade::SolarFox::Game::detection(arcade::interface::graphic::SpritePtr first, arcade::interface::graphic::SpritePtr second) const
{
	if (first->getPosition()->getX() == 10000 && first->getPosition()->getY() == 10000)
		return false;
	if (	((first->getPosition()->getX() >= second->getPosition()->getX() && first->getPosition()->getX() <= second->getPosition()->getX() + 30) &&
		(first->getPosition()->getY() >= second->getPosition()->getY() && first->getPosition()->getY() <= second->getPosition()->getY() + 30)) ||
		((first->getPosition()->getX() + 30 >= second->getPosition()->getX() && first->getPosition()->getX() + 30 <= second->getPosition()->getX() + 30) &&
		(first->getPosition()->getY() >= second->getPosition()->getY() && first->getPosition()->getY() <= second->getPosition()->getY() + 30)) ||
		((first->getPosition()->getX() >= second->getPosition()->getX() && first->getPosition()->getX() <= second->getPosition()->getX() + 30) &&
		(first->getPosition()->getY() + 30 >= second->getPosition()->getY() && first->getPosition()->getY()  + 30 <= second->getPosition()->getY() + 30)) ||
		((first->getPosition()->getX() + 30 >= second->getPosition()->getX() && first->getPosition()->getX() + 30 <= second->getPosition()->getX() + 30) &&
		(first->getPosition()->getY() + 30 >= second->getPosition()->getY() && first->getPosition()->getY() + 30 <= second->getPosition()->getY() + 30)))
			return true;
	if (	(first->getPosition()->getX() < _walls[0]->getPosition()->getX() + 30 || first->getPosition()->getX() >= _walls[3]->getPosition()->getX() - 30) ||
		first->getPosition()->getY() < _walls[2]->getPosition()->getY() + 30 || first->getPosition()->getY() >= _walls[1]->getPosition()->getY() - 30)
			return true;
	return false;
}

bool arcade::SolarFox::Game::detection(arcade::interface::graphic::SpritePtr first, std::vector<arcade::interface::graphic::SpritePtr> second)
{
	for (auto i = 0; i < second.size(); i++)
		if (detection(first, second[i])) {
			_listHit = i;
			return true;
		}
	return false;
}

arcade::interface::GamePtr getGameLibrary() {return arcade::interface::GamePtr(new arcade::SolarFox::Game());}
bool arcade::SolarFox::Game::isRunning() const {return _isRunning;}
