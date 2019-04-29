/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Bonus
*/

#include <vector>
#include <fstream>
#include <iostream>
#include "Bonus.hpp"

Bonus::Bonus()
{
}

Bonus::~Bonus()
{
}

void Bonus::getMap(std::string path)
{
	std::ifstream myFile;
	std::string line;
	
	myFile.open(path);
	while (myFile.is_open() && getline(myFile, line))
		_map.push_back(line);
	myFile.close();
}

void Bonus::init(arcade::interface::ResourceAllocator *manager, const arcade::interface::graphic::WindowPtr &window, char *map)
{
	_manager = manager;
	_window = window;

	_bonusTexture = _manager->createTexture("bonus.png");

	getMap(map);
	for (auto i = 0; i < _map.size(); i++) {
		for (auto j = 0; j < _map[i].size(); j++) {
			if (_map[i][j] != ' ') {
				arcade::interface::graphic::SpritePtr sprite = _manager->createSprite(_bonusTexture);
				sprite->setPosition(150 + (j * 61), 330 + (i * 61));
				_bonus.push_back(sprite);
			}
		}
	}
}

void Bonus::hit(int i)
{
	_bonus.erase(_bonus.begin() + i);
}

void Bonus::draw()
{
	for (auto i = 0; i < _bonus.size(); i++)
		_window->draw(_bonus[i]);
}

std::vector<arcade::interface::graphic::SpritePtr> Bonus::getBonus() const {return _bonus;}
