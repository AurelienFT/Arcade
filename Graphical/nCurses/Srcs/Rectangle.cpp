/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Rectangle
*/

#include "Rectangle.hpp"

arcade::nCurses::Rectangle::Rectangle()
{

}

bool arcade::nCurses::Rectangle::contains(int32_t x, int32_t y) const noexcept
{
	return (false);
}

bool arcade::nCurses::Rectangle::intersects(arcade::interface::graphic::RectanglePtr other)
{
	return (false);
}

int32_t arcade::nCurses::Rectangle::getLeft() const
{
	return (_left);
}

void arcade::nCurses::Rectangle::setLeft(int32_t leftCoord)
{
	_left = leftCoord;
}

int32_t arcade::nCurses::Rectangle::getTop() const
{
	return (_top);
}

void arcade::nCurses::Rectangle::setTop(int32_t topCoord)
{
	_top = topCoord;
}

int32_t arcade::nCurses::Rectangle::getWidth() const
{
	return (_width);
}

void arcade::nCurses::Rectangle::setWidth(int32_t width)
{
	_width = width;
}

int32_t arcade::nCurses::Rectangle::getHeight() const
{
	return (_height);
}

void arcade::nCurses::Rectangle::setHeight(int32_t height)
{
	_height = height;
}