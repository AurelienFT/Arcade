/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Texture
*/

#include "Texture.hpp"
#include <fstream>
#include <iostream>

arcade::nCurses::Texture::Texture() 
{

}

arcade::nCurses::Texture::~Texture() 
{
}

bool arcade::nCurses::Texture::createTexture(uint64_t width, uint64_t height) 
{
}

bool arcade::nCurses::Texture::loadFromFile(const std::string &filename) 
{
    std::ifstream file(filename + ".ascii");

    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            _texture.push_back(line);
        }
        file.close();
    } else {
        throw std::exception();
        return (false);
    }
    _filename = filename;
    return (true);
}

bool arcade::nCurses::Texture::loadFromMemory(const void *data, std::size_t size)
{
    char *string = static_cast<char *>(const_cast<void *>(data));
    std::string tmp = std::string();

    for (int i = 0; string[i]; i++) {
        if (string[i] == '\n') {
            _texture.push_back(tmp);
            tmp = std::string();
        } else {
            tmp = tmp + string[i];
        }
    }
    return (true);
}

arcade::interface::graphic::Vector2iPtr arcade::nCurses::Texture::getSize() const
{
    auto max = 0;

    for (auto it = _texture.begin(); it != _texture.end(); it++) {
        if ((*it).length() > max)
            max = (*it).length();
    }
    return(arcade::interface::graphic::Vector2iPtr(new arcade::nCurses::Vector2i(max, _texture.size())));
}

std::vector<std::string> arcade::nCurses::Texture::getLibObject() const
{
    return (_texture);
}

arcade::interface::graphic::ITexture &arcade::nCurses::Texture::operator=(const arcade::interface::graphic::ITexture &right) 
{
}

std::string arcade::nCurses::Texture::getTexturePath() const
{
    return (_filename);
}