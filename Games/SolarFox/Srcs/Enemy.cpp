/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Enemy
*/

#include "Enemy.hpp"

Enemy::Enemy(int isRight)
	: _isRight(isRight)
{
}

Enemy::~Enemy()
{
}

std::vector<arcade::interface::graphic::SpritePtr> Enemy::getShoots() const {return _shoots;}
std::vector<arcade::interface::graphic::SpritePtr> Enemy::getShootsDown() const {return _shootsDown;}
arcade::interface::graphic::SpritePtr Enemy::getEnemy() const {return _enemy;}

void Enemy::init(arcade::interface::ResourceAllocator *manager, arcade::interface::graphic::WindowPtr window)
{
	_manager = manager;
	_window = window;
	_shootTexture = _manager->createTexture("enemyShoot.png");
	_shootDownTexture = _manager->createTexture("enemyShootDown.png");
	_enemyTexture = _manager->createTexture("enemy.png");
	_enemyDownTexture = _manager->createTexture("enemyDown.png");
	_enemy = _manager->createSprite(_enemyTexture);
	_enemyDown = _manager->createSprite(_enemyDownTexture);
	_enemy->setPosition(_window->getSize()->getX(), 0);
	_enemyDown->setPosition(0, _window->getSize()->getY() - 30);
}

void Enemy::shoot()
{
	if (clock() - _time >= 250000) {
		if (isNextShottUp) {
			_shoots.push_back(_manager->createSprite(_shootTexture));
			_shoots[_shoots.size() - 1]->setPosition(_enemy->getPosition());
			isNextShottUp = false;
		} else {
			_shootsDown.push_back(_manager->createSprite(_shootDownTexture));
			_shootsDown[_shootsDown.size() - 1]->setPosition(_enemyDown->getPosition());
			isNextShottUp = true;
		}
		_time = clock();
	}
}

void Enemy::hit(int i)
{
	_shoots.erase(_shoots.begin() + i);
}

void Enemy::hitDown(int i)
{
	_shootsDown.erase(_shootsDown.begin() + i);
}

void Enemy::draw()
{
	_window->draw(_enemy);
	_window->draw(_enemyDown);
	for (auto i = 0; i < _shoots.size(); i++)
		_window->draw(_shoots[i]);
	for (auto i = 0; i < _shootsDown.size(); i++)
		_window->draw(_shootsDown[i]);
}

void Enemy::move()
{
	shoot();
	_enemy->move(_isRight, 0);
	_enemyDown->move(((_isRight == 1) ? -1 : 1), 0);
	if (_isRight == 1 && _enemy->getPosition()->getX() >= _window->getSize()->getX())
		_isRight = -1;
	if (_isRight == -1 && _enemy->getPosition()->getX() <= 0)
		_isRight = 1;

	for (auto i = 0; i < _shoots.size(); i++) {
		_shoots[i]->setPosition(_shoots[i]->getPosition()->getX(), _shoots[i]->getPosition()->getY() + 1);
		if (_shoots[i]->getPosition()->getY() > _window->getSize()->getY())
			_shoots.erase(_shoots.begin() + i);
	}
	for (auto i = 0; i < _shootsDown.size(); i++) {
		_shootsDown[i]->setPosition(_shootsDown[i]->getPosition()->getX(), _shootsDown[i]->getPosition()->getY() - 1);
		if (_shootsDown[i]->getPosition()->getY() < 0)
			_shootsDown.erase(_shootsDown.begin() + i);
	}
}