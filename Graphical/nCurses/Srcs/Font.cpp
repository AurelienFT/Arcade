/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Font
*/

#include "Font.hpp"
#include <iostream>

arcade::nCurses::Font::Font()
{
}

arcade::nCurses::Font::~Font()
{
}

bool arcade::nCurses::Font::loadFromFile(const std::string &filename)
{
	return (true);
}

bool arcade::nCurses::Font::loadFromMemory(const void *data, std::size_t size)
{
}

arcade::interface::graphic::IFont &arcade::nCurses::Font::operator=(const arcade::interface::graphic::IFont &right)
{
}

void *arcade::nCurses::Font::getLibObject() const
{
	return (nullptr);
}

std::string arcade::nCurses::Font::getFontPath() const
{
	return (_filename);
}