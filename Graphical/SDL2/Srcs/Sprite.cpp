/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Sprite
*/

#include "Sprite.hpp"
#include "Texture.hpp"
#include <iostream>

arcade::SDL2::Sprite::Sprite()
{
	_pos = arcade::interface::graphic::Vector2fPtr(new arcade::SDL2::Vector2f(0, 0));
}

arcade::SDL2::Sprite::Sprite(arcade::interface::graphic::TexturePtr &texture)
{
	SDL_Color color = {255, 255, 255};
	_pos = arcade::interface::graphic::Vector2fPtr(new arcade::SDL2::Vector2f(0, 0));
	_texture = texture;
}


void arcade::SDL2::Sprite::setColor(const arcade::interface::graphic::ColorPtr color)
{

}

arcade::interface::graphic::ColorPtr arcade::SDL2::Sprite::getColor() const
{

}

void arcade::SDL2::Sprite::setTexture(arcade::interface::graphic::TexturePtr texture)
{
	_texture = texture;
}

const arcade::interface::graphic::TexturePtr arcade::SDL2::Sprite::getTexture() const
{
	return (_texture);
}

void arcade::SDL2::Sprite::setTextureRect(arcade::interface::graphic::RectanglePtr rect)
{
}

void *arcade::SDL2::Sprite::getDrawable()
{
	return static_cast<char *>(static_cast<arcade::SDL2::Texture *>(_texture.get())->getLibObject());
}

void arcade::SDL2::Sprite::setPosition(arcade::interface::graphic::Vector2fPtr vec)
{
	float x = vec->getX();
	_pos->setX(x);
	_pos->setY(vec->getY());
}

void arcade::SDL2::Sprite::setPosition(float x, float y)
{
	_pos->setX(x);
	_pos->setY(y);
}

arcade::interface::graphic::Vector2fPtr arcade::SDL2::Sprite::getPosition() const
{
	return arcade::interface::graphic::Vector2fPtr(
	new arcade::SDL2::Vector2f(_pos->getX(), _pos->getY()));
}

void arcade::SDL2::Sprite::move(float xOff, float yOff)
{
	_pos->setX(xOff + _pos->getX());
	_pos->setY(yOff + _pos->getY());
}

void arcade::SDL2::Sprite::move(arcade::interface::graphic::Vector2fPtr vec)
{
	_pos->setX(vec->getX() + _pos->getX());
	_pos->setY(vec->getY() + _pos->getY());
}

void arcade::SDL2::Sprite::setRotation(float angle)
{
	//_sprite.setRotation(angle);
}

float arcade::SDL2::Sprite::getRotation() const
{
	//return (_sprite.getRotation());	
}

arcade::interface::graphic::RectanglePtr arcade::SDL2::Sprite::getTextureRect()
{
	return (_rect);	
}
