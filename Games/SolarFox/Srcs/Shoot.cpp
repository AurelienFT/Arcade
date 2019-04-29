/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Shoot
*/

#include <iostream>
#include "Shoot.hpp"

Shoot::Shoot()
{
}

Shoot::~Shoot()
{
}

void Shoot::init(arcade::interface::ResourceAllocator *manager, std::string path)
{
	std::string text = path;
	_shootTexture = manager->createTexture(text);
	_shoot = manager->createSprite(_shootTexture);
	_shoot->setPosition(10000, 10000);
}

void Shoot::move()
{
	if (!_isAvailable) {
		if (_time > 60) {
			_time = 0;
			_isAvailable = true;
			_shoot->setPosition(10000, 10000);
			return;
		}
		_shoot->setPosition(_shoot->getPosition()->getX() + _direction->getX(), _shoot->getPosition()->getY() + _direction->getY());
		_time += 1;
	}
}

void Shoot::setDirection(arcade::interface::graphic::Vector2fPtr direction)
{
	if (_isAvailable) {
		_direction = direction;
		_isAvailable = false;
	}
}

void Shoot::reset()
{
	_time = 0;
	_isAvailable = true;
	_shoot->setPosition(10000, 10000);
}

arcade::interface::graphic::SpritePtr Shoot::getShoot() const {return _shoot;}