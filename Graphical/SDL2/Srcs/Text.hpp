/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_
#include "arcade/interface/graphic/Graphic.hpp"
#include <string>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <memory>
#include "Vector2i.hpp"
#include "Vector2f.hpp"
#include "Font.hpp"

namespace arcade::SDL2 {
class Text : public arcade::interface::graphic::IText {
    public:
        Text();
	Text(arcade::interface::graphic::FontPtr);
        ~Text();
	void setString(const std::string &string);
 	const std::string &getString() const;
  	void setFont(arcade::interface::graphic::FontPtr font);
	arcade::interface::graphic::FontPtr getFont();
  	void setCharacterSize(unsigned int size);
  	unsigned int getCharacterSize() const;

  	void *getDrawable();
  	void setPosition(const arcade::interface::graphic::Vector2fPtr vec);
	void setPosition(float x, float y);
	arcade::interface::graphic::Vector2fPtr getPosition() const;
  	void move(float xOff, float yOff);
	void move(arcade::interface::graphic::Vector2fPtr vec);
	void setRotation(float angle);
  	float getRotation() const;
	void setColor(arcade::interface::graphic::ColorPtr color);
        arcade::interface::graphic::ColorPtr getColor() const;
    protected:
    private:
	arcade::interface::graphic::Vector2iPtr _pos;
	arcade::interface::graphic::FontPtr _font;
	std::string _string;
};
}

#endif /* !TEXT_HPP_ */
