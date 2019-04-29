/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Vector2i
*/

#include "Vector2i.hpp"

arcade::SDL2::Vector2i::Vector2i(int32_t x, int32_t y)
{
    _vector_x = x;
    _vector_y = y;
}

arcade::SDL2::Vector2i::Vector2i::~Vector2i()
{
}

int32_t arcade::SDL2::Vector2i::getX()const {
    return(_vector_x);
}

int32_t arcade::SDL2::Vector2i::getY() const  {
    return(_vector_y);
}

void arcade::SDL2::Vector2i::setX(int32_t x) {
    _vector_x = x;
}

void arcade::SDL2::Vector2i::setY(int32_t y) {
    _vector_y = y;
} 