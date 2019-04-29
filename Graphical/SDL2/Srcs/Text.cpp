/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Text
*/

#include "Text.hpp"
#include <iostream>

arcade::SDL2::Text::Text()
{
}

arcade::SDL2::Text::Text(arcade::interface::graphic::FontPtr font)
{
	SDL_Color color = {255, 255, 255};
	//_text = TTF_RenderText_Solid((static_cast<TTF_Font *>(static_cast<arcade::SDL2::Font *>(font.get())->getLibObject())), "", color);
	_font = font;
	_pos = arcade::interface::graphic::Vector2iPtr(new arcade::SDL2::Vector2i(0, 0));
}

arcade::SDL2::Text::~Text()
{}


void arcade::SDL2::Text::setString(const std::string &string)
{
	SDL_Color color = {255, 255, 255};
	//SDL_FreeSurface(_text);
 	//_text = TTF_RenderText_Solid((static_cast<TTF_Font *>(
	//static_cast<arcade::SDL2::Font *>(_font.get())->getLibObject())), string.c_str(), color);
	_string = string;
}

const std::string &arcade::SDL2::Text::getString() const
{
	return (_string);
}

void arcade::SDL2::Text::setFont(arcade::interface::graphic::FontPtr font)
{
	SDL_Color color = {255, 255, 255};
	//SDL_FreeSurface(_text);
	_font = font;
	//_text = TTF_RenderText_Solid((static_cast<TTF_Font *>(
	//static_cast<arcade::SDL2::Font *>(font.get())->getLibObject())), _string.c_str(), color);
}

arcade::interface::graphic::FontPtr arcade::SDL2::Text::getFont()
{
	return (_font);
}

void arcade::SDL2::Text::setCharacterSize(unsigned int size)
{
	return;
}

unsigned int arcade::SDL2::Text::getCharacterSize() const
{
	return (25);
}

void *arcade::SDL2::Text::getDrawable()
{
	return (static_cast<void *>(const_cast<char*>(_string.c_str())));
}

void arcade::SDL2::Text::setPosition(const arcade::interface::graphic::Vector2fPtr vec)
{
	_pos->setX(vec->getX());
	_pos->setY(vec->getY());
}

void arcade::SDL2::Text::setPosition(float x, float y)
{
	_pos->setX(x);
	_pos->setY(y);
}

arcade::interface::graphic::Vector2fPtr arcade::SDL2::Text::getPosition() const
{
	return arcade::interface::graphic::Vector2fPtr(new arcade::SDL2::Vector2f(_pos->getX(), _pos->getY()));
}

void arcade::SDL2::Text::move(float xOff, float yOff)
{
	_pos->setX(xOff + _pos->getX());
	_pos->setY(yOff + _pos->getY());
}

void arcade::SDL2::Text::move(arcade::interface::graphic::Vector2fPtr vec)
{
	_pos->setX(vec->getX() + _pos->getX());
	_pos->setY(vec->getY() + _pos->getY());
}

void arcade::SDL2::Text::setRotation(float angle)
{
//	_text.setRotation(angle);
}

float arcade::SDL2::Text::getRotation() const
{
	return (0);
}

void arcade::SDL2::Text::setColor(arcade::interface::graphic::ColorPtr color)
{

}

arcade::interface::graphic::ColorPtr arcade::SDL2::Text::getColor() const
{

}
