/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Rectangle
*/

#include "Rectangle.hpp"

arcade::SDL2::Rectangle::Rectangle()
{

}

bool arcade::SDL2::Rectangle::contains(int32_t x, int32_t y) const noexcept
{
	return (false);
}

bool arcade::SDL2::Rectangle::intersects(arcade::interface::graphic::RectanglePtr other)
{
	return (false);
}

int32_t arcade::SDL2::Rectangle::getLeft() const
{
	return (_left);
}

void arcade::SDL2::Rectangle::setLeft(int32_t leftCoord)
{
	_left = leftCoord;
}

int32_t arcade::SDL2::Rectangle::getTop() const
{
	return (_top);
}

void arcade::SDL2::Rectangle::setTop(int32_t topCoord)
{
	_top = topCoord;
}

int32_t arcade::SDL2::Rectangle::getWidth() const
{
	return (_width);
}

void arcade::SDL2::Rectangle::setWidth(int32_t width)
{
	_width = width;
}

int32_t arcade::SDL2::Rectangle::getHeight() const
{
	return (_height);
}

void arcade::SDL2::Rectangle::setHeight(int32_t height)
{
	_height = height;
}