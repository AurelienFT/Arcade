/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Sprite
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include "arcade/interface/graphic/Graphic.hpp"
#include "Vector2i.hpp"
#include "Vector2f.hpp"

namespace arcade::SDL2 {
    class Sprite : public arcade::interface::graphic::ISprite {
    public:
        Sprite();
	    Sprite(arcade::interface::graphic::TexturePtr &texture);
        void setColor(const arcade::interface::graphic::ColorPtr color);
        arcade::interface::graphic::ColorPtr getColor() const;
        void setTexture(arcade::interface::graphic::TexturePtr texture);
        const arcade::interface::graphic::TexturePtr getTexture() const;
        void setTextureRect(arcade::interface::graphic::RectanglePtr rect);
        arcade::interface::graphic::Vector2fPtr getPosition() const;
        void setRotation(float angle);
        float getRotation() const;

        void *getDrawable();
        void setPosition(arcade::interface::graphic::Vector2fPtr vec);
        void setPosition(float x, float y);
        void move(float xOff, float yOff);
        void move(arcade::interface::graphic::Vector2fPtr vec);
        arcade::interface::graphic::RectanglePtr getTextureRect();
    private:
	    arcade::interface::graphic::TexturePtr _texture;
        arcade::interface::graphic::Vector2fPtr _pos;
        arcade::interface::graphic::RectanglePtr _rect;
    };
}


#endif /* !SPRITE_HPP_ */
