/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Texture
*/

#ifndef TEXTURE_HPP_
#define TEXTURE_HPP_

#include "arcade/interface/graphic/Graphic.hpp"
#include "Vector2i.hpp"
#include <SFML/Graphics.hpp>

namespace arcade::SFML {
    class Texture : public arcade::interface::graphic::ITexture {
	public:
        Texture();
        ~Texture();
        bool createTexture(uint64_t width, uint64_t height);
        bool loadFromFile(const std::string &filename);
        bool loadFromMemory(const void *data, std::size_t size);
        arcade::interface::graphic::Vector2iPtr getSize() const;
        void *getLibObject() const;
        arcade::interface::graphic::ITexture &operator=(const arcade::interface::graphic::ITexture &right);
        std::string getTexturePath() const;
	private:
        std::shared_ptr<sf::Texture> _texture;
        std::string _filename;
    };
}

#endif /* !TEXTURE_HPP_ */
