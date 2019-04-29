/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Player
*/

#include <iostream>
#include "Player.hpp"

Player::Player()
{
}

Player::~Player()
{
}

void Player::init(arcade::interface::ResourceAllocator *manager, arcade::interface::graphic::WindowPtr window)
{
	_manager = manager;
	_window = window;
	_playerTexture.push_back(_manager->createTexture("playerLeft.png"));
	_playerTexture.push_back(_manager->createTexture("playerRight.png"));
	_playerTexture.push_back(_manager->createTexture("playerUp.png"));
	_playerTexture.push_back(_manager->createTexture("playerDown.png"));
	_player = _manager->createSprite(_playerTexture[1]);
	_player->setPosition(_window->getSize()->getX() / 2, _window->getSize()->getY() / 2);
	_shoot.init(_manager, "playerShoot.png");
}

void Player::move(int direction)
{
	if ((direction == 1 && _lastDirection != 2) || (direction == 2 && _lastDirection == 1)) {
		_player->setPosition(_player->getPosition()->getX() - 1, _player->getPosition()->getY());
		_player->setTexture(_playerTexture[0]);
		if (direction == 1 && _lastDirection != 2)
			_lastDirection = direction;
	} else if ((direction == 2 && _lastDirection != 1) || (direction == 1 && _lastDirection == 2)) {
		_player->setPosition(_player->getPosition()->getX() + 1, _player->getPosition()->getY());
		_player->setTexture(_playerTexture[1]);
		if (direction == 2 && _lastDirection != 1)
			_lastDirection = direction;

	} else if ((direction == 3 && _lastDirection != 4) || (direction == 4 && _lastDirection == 3)) {
		_player->setPosition(_player->getPosition()->getX(), _player->getPosition()->getY() - 1);
		_player->setTexture(_playerTexture[2]);
		if (direction == 3 && _lastDirection != 4)
			_lastDirection = direction;
	} else if ((direction == 4 && _lastDirection != 3) || (direction == 3 && _lastDirection == 4)) {
		_player->setPosition(_player->getPosition()->getX(), _player->getPosition()->getY() + 1);
		_player->setTexture(_playerTexture[3]);
		if (direction == 4 && _lastDirection != 3)
			_lastDirection = direction;
	}
	_shoot.move();
}

void Player::shoot() 
{
	if (_lastDirection == 1) {
		_shoot.getShoot()->setPosition(_player->getPosition());
		_shoot.setDirection(_manager->createVector2f(-3, 0));
	} else if (_lastDirection == 2) {
		_shoot.getShoot()->setPosition(_player->getPosition());
		_shoot.setDirection(_manager->createVector2f(3, 0));
	} else if (_lastDirection == 3) {
		_shoot.getShoot()->setPosition(_player->getPosition());
		_shoot.setDirection(_manager->createVector2f(0, -3));
	}else if (_lastDirection == 4) {
		_shoot.getShoot()->setPosition(_player->getPosition());
		_shoot.setDirection(_manager->createVector2f(0, 3));
	}
}

void Player::hit()
{
	_shoot.reset();
}

void Player::draw()
{
	_window->draw(_player);
	_window->draw(_shoot.getShoot());
}

Shoot Player::getShoot() const {return _shoot;}
arcade::interface::graphic::SpritePtr Player::getPlayer() const {return _player;}
