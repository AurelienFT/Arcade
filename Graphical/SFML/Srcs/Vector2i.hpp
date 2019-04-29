/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Vector2i
*/

#ifndef VECTOR2I_HPP_
#define VECTOR2I_HPP_

#include "arcade/interface/graphic/Graphic.hpp"

namespace arcade::SFML {
class Vector2i : public arcade::interface::graphic::IVector2i {
	public:
        Vector2i() {};
		Vector2i(int32_t x, int32_t y);
		~Vector2i();
        int32_t getX() const;
        int32_t getY() const;
        void setX(int32_t x);
        void setY(int32_t y);

	protected:
    private:
        int32_t _vector_x;
        int32_t _vector_y;
    };
}

#endif /* !VECTOR2I_HPP_ */

