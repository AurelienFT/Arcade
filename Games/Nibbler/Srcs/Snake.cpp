/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Snake
*/

#include "../../../Core/Srcs/Core.hpp"
#include "Snake.hpp"

Snake::Snake()
{
}

Snake::~Snake()
{
}

void Snake::initialize(arcade::interface::ResourceAllocator *manager, const arcade::interface::graphic::WindowPtr &window)
{
	_manager = manager;
	_window = window;
	_head.initialize(_manager, _window);
	_texture = _manager->createTexture("tail.png");
	_tails.clear();
	for (auto i = 0; _tails.size() < 3; i++)
		_tails.push_back(_manager->createSprite(_texture));
	for (auto i = 0; _tails.size() < 3; i++)
		_tails[i]->setPosition(_head.getHead()->getPosition());
	draw();
}

void Snake::addTail()
{
	_tails.push_back(_manager->createSprite(_texture));
	_tails[_tails.size() - 1]->setPosition(_lastTail);
}

void Snake::draw() const
{
	for (auto i = 0; i < _tails.size(); i++)
		_window->draw(_tails[i]);
	_head.draw();
}

arcade::interface::graphic::SpritePtr Snake::getHead() const
{
	return _head.getHead();
}

std::vector<arcade::interface::graphic::SpritePtr> Snake::getTail() const
{
	return _tails;
}

void Snake::move(int direction)
{
	_head.move(direction);
	_lastTail = _tails[_tails.size() - 1]->getPosition();
	for (auto i = _tails.size() - 1; i > 0; i--)
	{
		_tails[i]->setPosition(_tails[i - 1]->getPosition());
	}
	_tails[0]->setPosition(_head.getLastHead());
}