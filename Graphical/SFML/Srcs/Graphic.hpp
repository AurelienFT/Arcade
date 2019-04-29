/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Graphic
*/

#ifndef GRAPHIC_HPP_
#define GRAPHIC_HPP_
#include "arcade/interface/graphic/Graphic.hpp"
#include <SFML/Graphics.hpp>
#include "Window.hpp"
#include <iostream>
#include <string>
namespace arcade::SFML {
	class GraphicalLibrary : public arcade::interface::graphic::IGraphicalLibrary {
		public:
			GraphicalLibrary();
			~GraphicalLibrary();
			arcade::interface::graphic::WindowPtr createWindow();
			arcade::interface::graphic::TexturePtr createTexture();
  			arcade::interface::graphic::TexturePtr createTexture(const std::string &path);
			arcade::interface::graphic::SpritePtr createSprite();
  			arcade::interface::graphic::SpritePtr createSprite(arcade::interface::graphic::TexturePtr texture);
			arcade::interface::graphic::ColorPtr createColor();
			arcade::interface::graphic::ColorPtr createColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
			arcade::interface::graphic::ColorPtr createColor(uint32_t color);
			arcade::interface::graphic::RectanglePtr createRectangle();
			arcade::interface::graphic::RectanglePtr createRectangle(int top, int left, int width, int height);
			arcade::interface::graphic::FontPtr createFont(const std::string &path);
			arcade::interface::graphic::TextPtr createText();
  			arcade::interface::graphic::TextPtr createText(arcade::interface::graphic::FontPtr font);
			arcade::interface::graphic::Vector2fPtr createVector2f();
			arcade::interface::graphic::Vector2fPtr createVector2f(float x, float y);
			arcade::interface::graphic::Vector2iPtr createVector2i();
			arcade::interface::graphic::Vector2iPtr createVector2i(int x, int y);
		protected:
		private:
	};
}

#endif /* !GRAPHIC_HPP_ */
