/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Sprite
*/

#include "Sprite.hpp"
#include "Texture.hpp"
#include "Vector2f.hpp"

arcade::SFML::Sprite::Sprite()
{
}

arcade::SFML::Sprite::Sprite(arcade::interface::graphic::TexturePtr &texture)
{
	_sprite.setTexture(*(static_cast<sf::Texture *>(static_cast<arcade::SFML::Texture *>(texture.get())->getLibObject())));
	_rect = arcade::interface::graphic::RectanglePtr(new arcade::SFML::Rectangle());
	_texture = texture;
}

void arcade::SFML::Sprite::setColor(arcade::interface::graphic::ColorPtr color)
{

}

arcade::interface::graphic::ColorPtr arcade::SFML::Sprite::getColor() const
{

}

void arcade::SFML::Sprite::setTexture(arcade::interface::graphic::TexturePtr texture)
{
	_sprite.setTexture(*(static_cast<sf::Texture *>(static_cast<arcade::SFML::Texture *>(texture.get())->getLibObject())));
	_texture = texture;
}

const arcade::interface::graphic::TexturePtr arcade::SFML::Sprite::getTexture() const
{
	return (_texture);
}

void arcade::SFML::Sprite::setTextureRect(arcade::interface::graphic::RectanglePtr rect)
{
	_sprite.setTextureRect(sf::IntRect(rect->getLeft(), rect->getTop(), rect->getWidth(), rect->getHeight()));
	_rect = rect;
}

arcade::interface::graphic::RectanglePtr arcade::SFML::Sprite::getTextureRect()
{
	return (_rect);
}

void *arcade::SFML::Sprite::getDrawable()
{
	return (&_sprite);
}

void arcade::SFML::Sprite::setPosition(arcade::interface::graphic::Vector2fPtr vec)
{
	_sprite.setPosition(vec->getX(), vec->getY());
}

void arcade::SFML::Sprite::setPosition(float x, float y)
{
	_sprite.setPosition(x, y);
}

arcade::interface::graphic::Vector2fPtr arcade::SFML::Sprite::getPosition() const
{
	return (arcade::interface::graphic::Vector2fPtr(
	new arcade::SFML::Vector2f(_sprite.getPosition().x, _sprite.getPosition().y)));
}

void arcade::SFML::Sprite::move(float xOff, float yOff)
{
	_sprite.move(xOff, yOff);
}

void arcade::SFML::Sprite::move(arcade::interface::graphic::Vector2fPtr vec)
{
	_sprite.move(sf::Vector2f(vec->getX(), vec->getY()));
}

void arcade::SFML::Sprite::setRotation(float angle)
{
	_sprite.setRotation(angle);
}

float arcade::SFML::Sprite::getRotation() const
{
	return (_sprite.getRotation());	
}

arcade::SFML::Sprite::~Sprite()
{
}
