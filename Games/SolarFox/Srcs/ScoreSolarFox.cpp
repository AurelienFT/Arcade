/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** ScoreSolarFox
*/

#include <iostream>
#include "ScoreSolarFox.hpp"

ScoreSolarFox::ScoreSolarFox()
{
}

ScoreSolarFox::~ScoreSolarFox()
{
}

void ScoreSolarFox::saveScore(int score, const char *name, char *file)
{
	_score = score;
	_name = name;
	_file = file;

	getFromFile();
	newValue();
	writeInFile();
}

void ScoreSolarFox::newValue()
{
	if (_names.size() == 0) {
		_names.push_back(_name);
		_values.push_back(_score);
		return;
	}

	auto i = 0;
	for (; i < _names.size(); i++) {
		if (_score > _values[i]) {
			_names.insert(_names.begin() + i, _name);
			if (_names.size() == 4)
				_names.pop_back();
			_values.insert(_values.begin() + i, _score);
			if (_values.size() == 4)
				_values.pop_back();
			return;
		}
	}
	
	if (i < 5) {
		_names.push_back(_name);
		_values.push_back(_score);
	}
}