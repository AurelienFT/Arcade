/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Font
*/

#ifndef FONT_HPP_
#define FONT_HPP_
#include "arcade/interface/graphic/Graphic.hpp"
#include <SDL2/SDL_ttf.h>
namespace arcade::SDL2 {
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
		TTF_Font *_font;
		std::string _filename;
};
}

#endif /* !FONT_HPP_ */
