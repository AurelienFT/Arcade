/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Vector2f
*/

#include "Vector2f.hpp"

arcade::SDL2::Vector2f::Vector2f(float x, float y)
{
    _vector_x = x;
    _vector_y = y;
}

arcade::SDL2::Vector2f::Vector2f::~Vector2f()
{
}

float arcade::SDL2::Vector2f::getX()const {
    return(_vector_x);
}

float arcade::SDL2::Vector2f::getY() const  {
    return(_vector_y);
}

void arcade::SDL2::Vector2f::setX(float x) {
    _vector_x = x;
}

void arcade::SDL2::Vector2f::setY(float y) {
    _vector_y = y;
} 