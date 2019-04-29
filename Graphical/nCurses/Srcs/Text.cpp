/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Text
*/

#include "Text.hpp"
#include "Vector2f.hpp"
#include <iostream>

arcade::nCurses::Text::Text()
{
}

arcade::nCurses::Text::Text(arcade::interface::graphic::FontPtr font)
{}

arcade::nCurses::Text::~Text()
{}


void arcade::nCurses::Text::setString(const std::string &string)
{
	_string = string;
}

const std::string &arcade::nCurses::Text::getString() const
{
	return (_string);
}

void arcade::nCurses::Text::setFont(arcade::interface::graphic::FontPtr font)
{
}

arcade::interface::graphic::FontPtr arcade::nCurses::Text::getFont()
{
}

void arcade::nCurses::Text::setCharacterSize(unsigned int size)
{
}

unsigned int arcade::nCurses::Text::getCharacterSize() const
{
	return (-1);
}

void arcade::nCurses::Text::setColor(arcade::interface::graphic::ColorPtr color)
{

}

arcade::interface::graphic::ColorPtr arcade::nCurses::Text::getColor() const
{

}

void *arcade::nCurses::Text::getDrawable()
{
	return (&_string);
}

void arcade::nCurses::Text::setPosition(const arcade::interface::graphic::Vector2fPtr vec)
{
	_pos.setX(vec->getX());
	_pos.setY(vec->getY());
}

void arcade::nCurses::Text::setPosition(float x, float y)
{
	_pos.setX(x);
	_pos.setY(y);
}

arcade::interface::graphic::Vector2fPtr arcade::nCurses::Text::getPosition() const
{
	return (arcade::interface::graphic::Vector2fPtr(new arcade::nCurses::Vector2f(_pos.getX(), _pos.getY())));
}

void arcade::nCurses::Text::move(float xOff, float yOff)
{
	_pos.setX(_pos.getX() + xOff);
	_pos.setY(_pos.getY() + yOff);
}

void arcade::nCurses::Text::move(arcade::interface::graphic::Vector2fPtr vec)
{
	_pos.setX(_pos.getX() + vec->getX());
	_pos.setY(_pos.getY() + vec->getY());
}


void arcade::nCurses::Text::setRotation(float angle)
{
}

float arcade::nCurses::Text::getRotation() const
{
}
