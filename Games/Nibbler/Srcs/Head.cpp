/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Head
*/

#include <memory>
#include "Head.hpp"

Head::Head()
{
}

Head::~Head()
{
}

arcade::interface::graphic::Vector2fPtr Head::getLastHead() const {return _lastHead;}
arcade::interface::graphic::SpritePtr Head::getHead() const {return _head;}

void Head::initialize(arcade::interface::ResourceAllocator *manager, const arcade::interface::graphic::WindowPtr &window)
{
	_manager = manager;
	_window = window;
	_head = _manager->createSprite(_manager->createTexture("head.png"));
	_head->setPosition(_window->getSize()->getX() / 2, _window->getSize()->getY() / 2);
	draw();
}

void Head::draw() const
{
	_window->draw(_head);
}

void Head::move(int direction)
{
	_lastHead = _head->getPosition();
	if (direction == 1)
		_head->setPosition(_head->getPosition()->getX() - 30, _head->getPosition()->getY());
	if (direction == 2)
		_head->setPosition(_head->getPosition()->getX() + 30, _head->getPosition()->getY());
	if (direction == 3)
		_head->setPosition(_head->getPosition()->getX(), _head->getPosition()->getY() - 30);
	if (direction == 4)
		_head->setPosition(_head->getPosition()->getX(), _head->getPosition()->getY() + 30);
}