/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_
#include "arcade/interface/graphic/Graphic.hpp"
#include <SFML/Graphics/Text.hpp>
#include <string>
namespace arcade::SFML {
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
	void setColor(arcade::interface::graphic::ColorPtr color);
        arcade::interface::graphic::ColorPtr getColor() const;

  	void *getDrawable();
  	void setPosition(const arcade::interface::graphic::Vector2fPtr vec);
	void setPosition(float x, float y);
	arcade::interface::graphic::Vector2fPtr getPosition() const;
  	void move(float xOff, float yOff);
	void move(arcade::interface::graphic::Vector2fPtr vec);
	void setRotation(float angle);
  	float getRotation() const;
	
    protected:
    private:
	sf::Text _text;
	arcade::interface::graphic::FontPtr _font;
	std::string _string;
};
}

#endif /* !TEXT_HPP_ */