/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Score
*/

#include <fstream>
#include <iostream>
#include "Score.hpp"

Score::Score()
{
}

Score::~Score()
{
}

void Score::saveScore(int score, const char *name, char *file)
{
	;
}

void Score::getFromFile()
{
	std::ifstream myFile;
	std::string line;
	
	myFile.open(_file);
	while (myFile.is_open() && getline(myFile, line))
		_scores.push_back(line);
	myFile.close();
	getValues();
	getNames();
}

void Score::writeInFile()
{
	setScores();
	std::ofstream ofs;
	ofs.open(_file, std::ofstream::out | std::ofstream::trunc);
	ofs.close();
	
	ofs.open(_file);
	if (ofs.is_open() == false) {
		return;
	}
	for (auto i = 0; i < _scores.size(); i++)
		ofs << _scores[i] << std::endl;
	ofs.close();

}

void Score::getValues()
{
	for (auto i = 0; i < _scores.size(); i++) {
		std::string value;
		auto j = 0;
		for (; j < _scores[i].size() && _scores[i][j] != ' '; j++);
		j++;
		for (auto k = 0; j < _scores[i].size(); k++, j++)
			value.push_back(_scores[i][j]);
		int n = std::stoi(value);
		_values.push_back(n);
	}
}

void Score::getNames()
{
	for (auto i = 0; i < _scores.size(); i++) {
		std::string name;
		for (auto j = 0; j < _scores[i].size() && _scores[i][j] != ' '; j++)
			name.push_back(_scores[i][j]);
		_names.push_back(name);
	}
}

void Score::setScores()
{
	_scores.clear();
	for (auto i = 0; i < _values.size(); i++)
		_scores.push_back(_names[i] + " " + std::to_string(_values[i]));
}