/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Rectangle
*/

#include "Rectangle.hpp"

arcade::SFML::Rectangle::Rectangle()
{

}

bool arcade::SFML::Rectangle::contains(int32_t x, int32_t y) const noexcept
{
	return (false);
}

bool arcade::SFML::Rectangle::intersects(arcade::interface::graphic::RectanglePtr other)
{
	return (false);
}

int32_t arcade::SFML::Rectangle::getLeft() const
{
	return (_left);
}

void arcade::SFML::Rectangle::setLeft(int32_t leftCoord)
{
	_left = leftCoord;
}

int32_t arcade::SFML::Rectangle::getTop() const
{
	return (_top);
}

void arcade::SFML::Rectangle::setTop(int32_t topCoord)
{
	_top = topCoord;
}

int32_t arcade::SFML::Rectangle::getWidth() const
{
	return (_width);
}

void arcade::SFML::Rectangle::setWidth(int32_t width)
{
	_width = width;
}

int32_t arcade::SFML::Rectangle::getHeight() const
{
	return (_height);
}

void arcade::SFML::Rectangle::setHeight(int32_t height)
{
	_height = height;
}