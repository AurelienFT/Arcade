/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Rectangle
*/

#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

#include "arcade/interface/graphic/Graphic.hpp"

namespace arcade::nCurses {
class Rectangle : public arcade::interface::graphic::IRectangle {
	public:
		Rectangle();
		bool contains(int32_t x, int32_t y) const noexcept;
		bool intersects(arcade::interface::graphic::RectanglePtr other);
		int32_t getLeft() const;
		void setLeft(int32_t leftCoord);
		int32_t getTop() const;
		void setTop(int32_t topCoord);
		int32_t getWidth() const;
		void setWidth(int32_t width);
		int32_t getHeight() const;
		void setHeight(int32_t height);
	protected:
	private:
		int32_t _left = 0;
		int32_t _top = 0;
		int32_t _width = 0;
		int32_t _height = 0;
};
}

#endif /* !RECTANGLE_HPP_ */
