/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Font
*/

#ifndef FONT_HPP_
#define FONT_HPP_
#include "arcade/interface/graphic/Graphic.hpp"
#include <SFML/Graphics/Text.hpp>

namespace arcade::SFML {
class Font : public arcade::interface::graphic::IFont  {
	public:
		Font();
		~Font();
		bool loadFromFile(const std::string &filename);
		bool loadFromMemory(const void *data, std::size_t size);
  		arcade::interface::graphic::IFont &operator=(const arcade::interface::graphic::IFont &right);
  		void *getLibObject() const;
		std::string getFontPath() const;
	protected:
	private:
		std::shared_ptr<sf::Font> _font;
		std::string _filename;
};
}

#endif /* !FONT_HPP_ */
