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


arcade::Nibbler::Game::Game()
{
}

arcade::Nibbler::Game::~Game()
{
}

void arcade::Nibbler::Game::init(arcade::interface::ResourceAllocator *manager, const arcade::interface::graphic::WindowPtr &window)
{
	srand(time(NULL));
	_window = window;
	_manager = manager;
	_endMenu.init(_manager, _window);
	_pause.init(_manager, _window);
	_food = _manager->createSprite(_manager->createTexture("food.png"));
	createFood();
	_snake.initialize(_manager, _window);
	arcade::interface::graphic::TexturePtr wallsTexture = _manager->createTexture("wall.png");
	arcade::interface::graphic::TexturePtr wallsTextureVert = _manager->createTexture("wallVert1.png");
	arcade::interface::graphic::SpritePtr walls = _manager->createSprite(wallsTexture);
	walls->setPosition(0,0);
	_walls.push_back(walls);
	walls = _manager->createSprite(wallsTextureVert);
	walls->setPosition(0,0);
	_walls.push_back(walls);
	walls = _manager->createSprite(wallsTextureVert);
	walls->setPosition(_window->getSize()->getX() - 30, 0);
	_walls.push_back(walls);
	walls = _manager->createSprite(wallsTexture);
	walls->setPosition(0, _window->getSize()->getY() - 30);
	_walls.push_back(walls);
	arcade::interface::graphic::FontPtr font;
	arcade::interface::graphic::TextPtr text;
	font = _manager->createFont("neon2.ttf");	
	_scoreText = _manager->createText(font);
	_scoreText->setString(std::to_string(_score));
}

void arcade::Nibbler::Game::handleEvent()
{
	if (_end) {
		_endMenu.refresh();
		return;
	}
	arcade::interface::graphic::EventPtr event = _window->getCurrentEvent();
	if (event && event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyPressed) {
		if (_isPaused && _pause.handleEvent() == 1)
			_isPaused = false;
		else if (_pause.handleEvent() == 3) {
			_isPaused = false;
			init(_manager, _window);
		}
		else if (_isPaused && _pause.handleEvent() == 2)
			_isRunning = false;
		else if (event->getKey() == arcade::interface::graphic::Key::Left)
			_direction = 1;
		else if (event->getKey() == arcade::interface::graphic::Key::Right)
			_direction = 2;
		else if (event->getKey() == arcade::interface::graphic::Key::Up)
			_direction = 3;
		else if (event->getKey() == arcade::interface::graphic::Key::Down)
			_direction = 4;
		else if (event->getKey() == arcade::interface::graphic::Key::Escape)
			_isPaused = true;
	}
}

void arcade::Nibbler::Game::move()
{
	if (clock() - _lastLoop < 50000) {
		_window->draw(_food);
		_snake.draw();
		return;
	}
	_lastLoop = clock();
	_snake.move(_direction);
	if (checkFood()) {
		_score += 1;
		_snake.addTail();
		createFood();
	}
	if (checkHit()) {
		_end = true;
	}
}

void arcade::Nibbler::Game::pause()
{
	_pause.refresh();
	_window->draw(_food);
	_snake.draw();
}

void arcade::Nibbler::Game::end()
{
	_endMenu.refresh();
	if (_endMenu.isEnd()) {
		_isRunning = false;
		_scores.saveScore(_score, _endMenu.getName().c_str(), "scores/Nibbler.txt");
	}
	_window->draw(_food);
	_snake.draw();
}

void arcade::Nibbler::Game::refresh()
{
	for (auto i = 0; i < _walls.size() ; i++) {
		_window->draw(_walls[i]);
	} if (_isPaused) {
		pause();
		return;
	}
	if (_end) {
		end();
		return;
	}
	move();
	_window->draw(_food);
	_scoreText->setString("SCORE :");
	_scoreText->setPosition(60, 60);
	_window->draw(_scoreText);
	_scoreText->setString(std::to_string(_score));
	_scoreText->setPosition(220, 60);
	_window->draw(_scoreText);
	_snake.draw();
}

void arcade::Nibbler::Game::createFood()
{
	int x = rand() % ((_window->getSize()->getX() - 60) / 30);
	int y = rand() % ((_window->getSize()->getY() - 60) / 30);
	_food->setPosition((float)(x + 1) * 30, (float)(y + 1) * 30);
}

bool arcade::Nibbler::Game::checkFood()
{
	return detection(_snake.getHead(), _food);
}

bool arcade::Nibbler::Game::checkHit()
{
	return  detection(_snake.getHead(), _snake.getTail())/*)*/;
}

bool arcade::Nibbler::Game::detection(arcade::interface::graphic::SpritePtr first, arcade::interface::graphic::SpritePtr second) const
{
	if (	((first->getPosition()->getX() >= second->getPosition()->getX() && first->getPosition()->getX() <= second->getPosition()->getX() + 30) &&
		(first->getPosition()->getY() >= second->getPosition()->getY() && first->getPosition()->getY() <= second->getPosition()->getY() + 30)) &&
		((first->getPosition()->getX() + 30 >= second->getPosition()->getX() && first->getPosition()->getX() + 30 <= second->getPosition()->getX() + 30) &&
		(first->getPosition()->getY() >= second->getPosition()->getY() && first->getPosition()->getY() <= second->getPosition()->getY() + 30)) &&
		((first->getPosition()->getX() >= second->getPosition()->getX() && first->getPosition()->getX() <= second->getPosition()->getX() + 30) &&
		(first->getPosition()->getY() + 30 >= second->getPosition()->getY() && first->getPosition()->getY()  + 30 <= second->getPosition()->getY() + 30)) &&
		((first->getPosition()->getX() + 30 >= second->getPosition()->getX() && first->getPosition()->getX() + 30 <= second->getPosition()->getX() + 30) &&
		(first->getPosition()->getY() + 30 >= second->getPosition()->getY() && first->getPosition()->getY() + 30 <= second->getPosition()->getY() + 30)))
		return true;
	if (	first->getPosition()->getX() < 30 || first->getPosition()->getX() >= _window->getSize()->getX() - 30 ||
		first->getPosition()->getY() < 30 || first->getPosition()->getY() >= _window->getSize()->getY() - 30)
		return true;
	return false;
}

bool arcade::Nibbler::Game::detection(arcade::interface::graphic::SpritePtr first, std::vector<arcade::interface::graphic::SpritePtr> second) const
{
	for (auto i = 0; i < second.size(); i++)
		if (detection(first, second[i]))
			return true;
	return false;
}

arcade::interface::GamePtr getGameLibrary() {return arcade::interface::GamePtr(new arcade::Nibbler::Game());}
bool arcade::Nibbler::Game::isRunning() const {return _isRunning;}