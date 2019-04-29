/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Sprite
*/

#include "Sprite.hpp"
#include "Texture.hpp"
#include "Vector2f.hpp"
#include "Rectangle.hpp"

arcade::nCurses::Sprite::Sprite()
{
}

arcade::nCurses::Sprite::Sprite(arcade::interface::graphic::TexturePtr &texture)
{
	_sprite = static_cast<arcade::nCurses::Texture *>(texture.get())->getLibObject();
	_texture = texture;
}


void arcade::nCurses::Sprite::setColor(arcade::interface::graphic::ColorPtr color)
{

}

arcade::interface::graphic::ColorPtr arcade::nCurses::Sprite::getColor() const
{

}

void arcade::nCurses::Sprite::setTexture(arcade::interface::graphic::TexturePtr texture)
{
	_sprite = static_cast<arcade::nCurses::Texture *>(texture.get())->getLibObject();
	_texture = texture;
}

const arcade::interface::graphic::TexturePtr arcade::nCurses::Sprite::getTexture() const
{
	return (_texture);
}

void arcade::nCurses::Sprite::setTextureRect(arcade::interface::graphic::RectanglePtr rect)
{
	//_sprite.setTextureRect()
}

void *arcade::nCurses::Sprite::getDrawable()
{
	return (&_sprite);
}

void arcade::nCurses::Sprite::setPosition(arcade::interface::graphic::Vector2fPtr vec)
{
	_pos.setX(vec->getX());
	_pos.setY(vec->getY());
}

void arcade::nCurses::Sprite::setPosition(float x, float y)
{
	_pos.setX(x);
	_pos.setY(y);
}

arcade::interface::graphic::Vector2fPtr arcade::nCurses::Sprite::getPosition() const
{
	return (arcade::interface::graphic::Vector2fPtr(new arcade::nCurses::Vector2f(_pos.getX(), _pos.getY())));
}

void arcade::nCurses::Sprite::move(float xOff, float yOff)
{
	_pos.setX(_pos.getX() + xOff);
	_pos.setY(_pos.getY() + yOff);
}

void arcade::nCurses::Sprite::move(arcade::interface::graphic::Vector2fPtr vec)
{
	_pos.setX(_pos.getX() + vec->getX());
	_pos.setY(_pos.getY() + vec->getY());
}

void arcade::nCurses::Sprite::setRotation(float angle)
{
}

float arcade::nCurses::Sprite::getRotation() const
{
}

arcade::interface::graphic::RectanglePtr arcade::nCurses::Sprite::getTextureRect()
{
	return arcade::interface::graphic::RectanglePtr(new arcade::nCurses::Rectangle());
}