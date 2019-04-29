/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Font
*/

#include "Font.hpp"
#include <iostream>

arcade::SDL2::Font::Font()
{
	TTF_Init();
}

arcade::SDL2::Font::~Font()
{
	TTF_CloseFont(_font);
}

bool arcade::SDL2::Font::loadFromFile(const std::string &filename)
{
	_font = TTF_OpenFont(filename.c_str(), 20);
	const char *error = TTF_GetError();

	if (!_font) {
		std::cout << "Fail name" << std::endl;
		throw std::exception();
	}
	_filename = filename;
	return (true);
}

bool arcade::SDL2::Font::loadFromMemory(const void *data, std::size_t size)
{
	return (false);
}

arcade::interface::graphic::IFont &arcade::SDL2::Font::operator=(const arcade::interface::graphic::IFont &right)
{
	_font = static_cast<TTF_Font *>(dynamic_cast<const arcade::SDL2::Font *>(&right)->getLibObject());
}

void *arcade::SDL2::Font::getLibObject() const
{
	return (static_cast<void *>(_font));
}

std::string arcade::SDL2::Font::getFontPath() const
{
	return (_filename);
}