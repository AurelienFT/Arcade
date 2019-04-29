/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Texture
*/

#include "Texture.hpp"
#include "Vector2i.hpp"
#include <iostream>
#include <SDL2/SDL_image.h>

arcade::SDL2::Texture::Texture() 
{}

arcade::SDL2::Texture::~Texture() 
{}

bool arcade::SDL2::Texture::createTexture(uint64_t width, uint64_t height) 
{}

bool arcade::SDL2::Texture::loadFromFile(const std::string &filename) 
{
/*     _image = IMG_Load(filename.c_str());
    if (!_image) {
        throw std::exception();
    } */
    _filename = filename;
    return (true);
}

bool arcade::SDL2::Texture::loadFromMemory(const void *data, std::size_t size)
{
}

arcade::interface::graphic::Vector2iPtr arcade::SDL2::Texture::getSize() const
{
    return (arcade::interface::graphic::Vector2iPtr(new arcade::SDL2::Vector2i(0, 0)));
}

void *arcade::SDL2::Texture::getLibObject() const
{
	return (static_cast<void *>(const_cast<char*>(_filename.c_str())));
}

arcade::interface::graphic::ITexture &arcade::SDL2::Texture::operator=(const arcade::interface::graphic::ITexture &right) 
{
	_filename = static_cast<char *>(dynamic_cast<const arcade::SDL2::Texture *>(&right)->getLibObject());
}

std::string arcade::SDL2::Texture::getTexturePath() const
{
    return (_filename);
}
