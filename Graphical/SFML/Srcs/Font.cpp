/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Font
*/

#include "Font.hpp"
#include <iostream>

arcade::SFML::Font::Font()
{
	_font = std::shared_ptr<sf::Font>(new sf::Font());
}

arcade::SFML::Font::~Font()
{
}

bool arcade::SFML::Font::loadFromFile(const std::string &filename)
{
	if (!_font->loadFromFile(filename)) {
		std::cout << "Fail name" << std::endl;
		throw std::exception();
	}
	_filename = filename;
}

bool arcade::SFML::Font::loadFromMemory(const void *data, std::size_t size)
{
	_font->loadFromMemory(data, size);
}

arcade::interface::graphic::IFont &arcade::SFML::Font::operator=(const arcade::interface::graphic::IFont &right)
{
	_font =  std::shared_ptr<sf::Font>(static_cast<sf::Font *>(dynamic_cast<const arcade::SFML::Font *>(&right)->getLibObject()));
}

void *arcade::SFML::Font::getLibObject() const
{
	return (static_cast<void*>(_font.get()));
}

std::string arcade::SFML::Font::getFontPath() const
{
	return (_filename);
}
