/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Text
*/

#include "Text.hpp"
#include "Vector2f.hpp"
#include "Font.hpp"
#include <iostream>

arcade::SFML::Text::Text()
{
}

arcade::SFML::Text::Text(arcade::interface::graphic::FontPtr font)
{
	_text = sf::Text("", *(static_cast<sf::Font *>(static_cast<arcade::SFML::Font *>(font.get())->getLibObject())));
	_font = font;
}

arcade::SFML::Text::~Text()
{}


void arcade::SFML::Text::setString(const std::string &string)
{
 	_text.setString(string);
	_string = string;
}

const std::string &arcade::SFML::Text::getString() const
{
	return (_string);
}

void arcade::SFML::Text::setFont(arcade::interface::graphic::FontPtr font)
{
	_font = font;
	_text.setFont(*(static_cast<sf::Font *>(static_cast<arcade::SFML::Font *>(font.get())->getLibObject())));
}

arcade::interface::graphic::FontPtr arcade::SFML::Text::getFont()
{
	return (_font);
}

void arcade::SFML::Text::setCharacterSize(unsigned int size)
{
	_text.setCharacterSize(size);
}

unsigned int arcade::SFML::Text::getCharacterSize() const
{
	return (_text.getCharacterSize());
}

void arcade::SFML::Text::setColor(arcade::interface::graphic::ColorPtr color)
{

}

arcade::interface::graphic::ColorPtr arcade::SFML::Text::getColor() const
{

}

void *arcade::SFML::Text::getDrawable()
{
	return (&_text);
}

void arcade::SFML::Text::setPosition(const arcade::interface::graphic::Vector2fPtr vec)
{
	_text.setPosition(vec->getX(), vec->getY());
}

void arcade::SFML::Text::setPosition(float x, float y)
{
	_text.setPosition(x, y);
}

arcade::interface::graphic::Vector2fPtr arcade::SFML::Text::getPosition() const
{
	return (arcade::interface::graphic::Vector2fPtr(
	new arcade::SFML::Vector2f(_text.getPosition().x, _text.getPosition().y)));
}

void arcade::SFML::Text::move(float xOff, float yOff)
{
	_text.move(sf::Vector2f(xOff, yOff));
}

void arcade::SFML::Text::move(arcade::interface::graphic::Vector2fPtr vec)
{
	_text.move(sf::Vector2f(vec->getX(), vec->getY()));
}

void arcade::SFML::Text::setRotation(float angle)
{
	_text.setRotation(angle);
}

float arcade::SFML::Text::getRotation() const
{
	return (_text.getRotation());
}
