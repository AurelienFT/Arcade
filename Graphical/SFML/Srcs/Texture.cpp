/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Texture
*/

#include "Texture.hpp"
#include "Vector2i.hpp"
#include <iostream>

arcade::SFML::Texture::Texture() 
{
    _texture = std::shared_ptr<sf::Texture>(new sf::Texture());
}

arcade::SFML::Texture::~Texture() 
{

}

bool arcade::SFML::Texture::createTexture(uint64_t width, uint64_t height) 
{
    return (_texture->create(width, height));
}

bool arcade::SFML::Texture::loadFromFile(const std::string &filename) 
{
    if (!_texture->loadFromFile(filename)) {
        throw std::exception();
    }
    _filename = filename;
    return (true);
}

bool arcade::SFML::Texture::loadFromMemory(const void *data, std::size_t size)
{
    return (_texture->loadFromMemory(data, size));
}

arcade::interface::graphic::Vector2iPtr arcade::SFML::Texture::getSize() const
{
    return (arcade::interface::graphic::Vector2iPtr(new arcade::SFML::Vector2i(_texture->getSize().x, _texture->getSize().y)));
}

void *arcade::SFML::Texture::getLibObject() const
{
	return (static_cast<void*>(_texture.get()));
}

arcade::interface::graphic::ITexture &arcade::SFML::Texture::operator=(const arcade::interface::graphic::ITexture &right) 
{
	_texture =  std::shared_ptr<sf::Texture>(static_cast<sf::Texture *>(dynamic_cast<const arcade::SFML::Texture *>(&right)->getLibObject()));
}

std::string arcade::SFML::Texture::getTexturePath() const
{
    return (_filename);
}