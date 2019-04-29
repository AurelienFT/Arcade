/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Graphic
*/

#include "Graphic.hpp"
#include "Window.hpp"
#include "Font.hpp"
#include "Text.hpp"
#include "Sprite.hpp"
#include "Texture.hpp"
#include "Rectangle.hpp"

arcade::nCurses::GraphicalLibrary::GraphicalLibrary()
{
}

arcade::nCurses::GraphicalLibrary::~GraphicalLibrary()
{
}

arcade::interface::graphic::WindowPtr arcade::nCurses::GraphicalLibrary::createWindow()
{
    return (arcade::interface::graphic::WindowPtr(new arcade::nCurses::Window()));
}

arcade::interface::graphic::TexturePtr arcade::nCurses::GraphicalLibrary::createTexture()
{
    return (arcade::interface::graphic::TexturePtr(new arcade::nCurses::Texture()));
}

arcade::interface::graphic::TexturePtr arcade::nCurses::GraphicalLibrary::createTexture(const std::string &path)
{
    arcade::interface::graphic::TexturePtr texture = arcade::interface::graphic::TexturePtr(new arcade::nCurses::Texture());

    texture->loadFromFile(path);
    return (texture);
}

arcade::interface::graphic::SpritePtr arcade::nCurses::GraphicalLibrary::createSprite()
{
    return (arcade::interface::graphic::SpritePtr(new arcade::nCurses::Sprite()));
}

arcade::interface::graphic::SpritePtr arcade::nCurses::GraphicalLibrary::createSprite(arcade::interface::graphic::TexturePtr texture)
{
    return (arcade::interface::graphic::SpritePtr(new arcade::nCurses::Sprite(texture)));
}

arcade::interface::graphic::ColorPtr arcade::nCurses::GraphicalLibrary::createColor()
{

}

arcade::interface::graphic::ColorPtr arcade::nCurses::GraphicalLibrary::createColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{

}

arcade::interface::graphic::ColorPtr arcade::nCurses::GraphicalLibrary::createColor(uint32_t color)
{

}

arcade::interface::graphic::RectanglePtr arcade::nCurses::GraphicalLibrary::createRectangle()
{
    return (arcade::interface::graphic::RectanglePtr(new arcade::nCurses::Rectangle()));
}

arcade::interface::graphic::RectanglePtr arcade::nCurses::GraphicalLibrary::createRectangle(int top, int left, int width, int height)
{
    arcade::interface::graphic::RectanglePtr rect =  arcade::interface::graphic::RectanglePtr(new arcade::nCurses::Rectangle());

    rect->setTop(top);
    rect->setLeft(left);
    rect->setWidth(width);
    rect->setHeight(height);
    return (rect);
}

arcade::interface::graphic::Vector2fPtr arcade::nCurses::GraphicalLibrary::createVector2f()
{
    return (arcade::interface::graphic::Vector2fPtr(new arcade::nCurses::Vector2f()));
}

arcade::interface::graphic::Vector2fPtr arcade::nCurses::GraphicalLibrary::createVector2f(float x, float y)
{
    return (arcade::interface::graphic::Vector2fPtr(new arcade::nCurses::Vector2f(x, y)));
}

arcade::interface::graphic::Vector2iPtr arcade::nCurses::GraphicalLibrary::createVector2i()
{
    return (arcade::interface::graphic::Vector2iPtr(new arcade::nCurses::Vector2i()));
}

arcade::interface::graphic::Vector2iPtr arcade::nCurses::GraphicalLibrary::createVector2i(int x, int y)
{
    return (arcade::interface::graphic::Vector2iPtr(new arcade::nCurses::Vector2i(x, y)));
}

arcade::interface::graphic::FontPtr arcade::nCurses::GraphicalLibrary::createFont(const std::string &path)
{
    return (arcade::interface::graphic::FontPtr(new arcade::nCurses::Font()));
}

arcade::interface::graphic::TextPtr arcade::nCurses::GraphicalLibrary::createText()
{
    return (arcade::interface::graphic::TextPtr(new arcade::nCurses::Text()));
}

arcade::interface::graphic::TextPtr arcade::nCurses::GraphicalLibrary::createText(arcade::interface::graphic::FontPtr font)
{
    return (arcade::interface::graphic::TextPtr(new arcade::nCurses::Text()));
}

arcade::interface::graphic::GLibPtr getGraphicalLibrary()
{
    return arcade::interface::graphic::GLibPtr(new arcade::nCurses::GraphicalLibrary());
}