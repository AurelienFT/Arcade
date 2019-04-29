/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Vector2f
*/

#ifndef Vector2f_HPP_
#define Vector2f_HPP_

#include "arcade/interface/graphic/Graphic.hpp"
#include <curses.h>

namespace arcade::nCurses {
class Vector2f : public arcade::interface::graphic::IVector2f {
	public:
        Vector2f() {};
		Vector2f(float x, float y);
		~Vector2f();
        float getX() const;
        float getY() const;
        void setX(float x);
        void setY(float y);

	protected:
    private:
        float _vector_x = 0;
        float _vector_y = 0;
    };
}

#endif /* !Vector2f_HPP_ */