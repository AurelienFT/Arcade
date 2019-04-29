/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Graphic
*/

#include "Window.hpp"
#include "Font.hpp"
#include "Text.hpp"
#include "Graphic.hpp"
#include "Texture.hpp"
#include "Sprite.hpp"
#include "Vector2f.hpp"
#include "Vector2i.hpp"

arcade::SDL2::GraphicalLibrary::GraphicalLibrary()
{
}

arcade::SDL2::GraphicalLibrary::~GraphicalLibrary()
{
}

arcade::interface::graphic::WindowPtr arcade::SDL2::GraphicalLibrary::createWindow()
{
    return (arcade::interface::graphic::WindowPtr(new arcade::SDL2::Window("arcade", 
    arcade::interface::graphic::Vector2iPtr(new arcade::SDL2::Vector2i(1500, 900)))));
}

arcade::interface::graphic::TexturePtr arcade::SDL2::GraphicalLibrary::createTexture()
{
    return (arcade::interface::graphic::TexturePtr(new arcade::SDL2::Texture()));
}

arcade::interface::graphic::TexturePtr arcade::SDL2::GraphicalLibrary::createTexture(const std::string &path)
{
    arcade::interface::graphic::TexturePtr texture = arcade::interface::graphic::TexturePtr(new arcade::SDL2::Texture());

    texture->loadFromFile(path);
    return (texture);
}

arcade::interface::graphic::SpritePtr arcade::SDL2::GraphicalLibrary::createSprite()
{
    return (arcade::interface::graphic::SpritePtr(new arcade::SDL2::Sprite()));
}

arcade::interface::graphic::SpritePtr arcade::SDL2::GraphicalLibrary::createSprite(arcade::interface::graphic::TexturePtr texture)
{
    return (arcade::interface::graphic::SpritePtr(new arcade::SDL2::Sprite(texture)));
}

arcade::interface::graphic::ColorPtr arcade::SDL2::GraphicalLibrary::createColor()
{

}

arcade::interface::graphic::ColorPtr arcade::SDL2::GraphicalLibrary::createColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{

}

arcade::interface::graphic::ColorPtr arcade::SDL2::GraphicalLibrary::createColor(uint32_t color)
{

}

arcade::interface::graphic::RectanglePtr arcade::SDL2::GraphicalLibrary::createRectangle()
{

}

arcade::interface::graphic::RectanglePtr arcade::SDL2::GraphicalLibrary::createRectangle(int top, int left, int width, int height)
{

}

arcade::interface::graphic::Vector2fPtr arcade::SDL2::GraphicalLibrary::createVector2f()
{
    return (arcade::interface::graphic::Vector2fPtr(new arcade::SDL2::Vector2f()));
}

arcade::interface::graphic::Vector2fPtr arcade::SDL2::GraphicalLibrary::createVector2f(float x, float y)
{
    return (arcade::interface::graphic::Vector2fPtr(new arcade::SDL2::Vector2f(x, y)));
}

arcade::interface::graphic::Vector2iPtr arcade::SDL2::GraphicalLibrary::createVector2i()
{
    return (arcade::interface::graphic::Vector2iPtr(new arcade::SDL2::Vector2i()));
}

arcade::interface::graphic::Vector2iPtr arcade::SDL2::GraphicalLibrary::createVector2i(int x, int y)
{
    return (arcade::interface::graphic::Vector2iPtr(new arcade::SDL2::Vector2i(x, y)));
}

arcade::interface::graphic::FontPtr arcade::SDL2::GraphicalLibrary::createFont(const std::string &path)
{
    arcade::interface::graphic::FontPtr font = arcade::interface::graphic::FontPtr(new arcade::SDL2::Font());
    font->loadFromFile(path);
    return (font);
}

arcade::interface::graphic::TextPtr arcade::SDL2::GraphicalLibrary::createText()
{
    return (arcade::interface::graphic::TextPtr(new arcade::SDL2::Text()));
}

arcade::interface::graphic::TextPtr arcade::SDL2::GraphicalLibrary::createText(arcade::interface::graphic::FontPtr font)
{
    arcade::interface::graphic::TextPtr text = arcade::interface::graphic::TextPtr(new arcade::SDL2::Text(font));
    return (text);
}

arcade::interface::graphic::GLibPtr getGraphicalLibrary()
{
    return arcade::interface::graphic::GLibPtr(new arcade::SDL2::GraphicalLibrary());
}