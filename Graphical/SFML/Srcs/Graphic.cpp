/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Graphic
*/

#include "Graphic.hpp"
#include "Window.hpp"
#include "Text.hpp"
#include "Font.hpp"
#include "Texture.hpp"
#include "Sprite.hpp"
#include "Rectangle.hpp"
#include "Vector2f.hpp"

arcade::SFML::GraphicalLibrary::GraphicalLibrary()
{
}

arcade::SFML::GraphicalLibrary::~GraphicalLibrary()
{
}

arcade::interface::graphic::WindowPtr arcade::SFML::GraphicalLibrary::createWindow()
{
    return (arcade::interface::graphic::WindowPtr(new arcade::SFML::Window("arcade", arcade::interface::graphic::IWindow::UNKNOWN, 
    arcade::interface::graphic::Vector2iPtr(new arcade::SFML::Vector2i(1500, 900)))));
}

arcade::interface::graphic::TexturePtr arcade::SFML::GraphicalLibrary::createTexture()
{
    return (arcade::interface::graphic::TexturePtr(new arcade::SFML::Texture()));
}

arcade::interface::graphic::TexturePtr arcade::SFML::GraphicalLibrary::createTexture(const std::string &path)
{
    arcade::interface::graphic::TexturePtr texture = arcade::interface::graphic::TexturePtr(new arcade::SFML::Texture());

    texture->loadFromFile(path);
    return (texture);
}

arcade::interface::graphic::SpritePtr arcade::SFML::GraphicalLibrary::createSprite()
{
    return (arcade::interface::graphic::SpritePtr(new arcade::SFML::Sprite()));
}

arcade::interface::graphic::SpritePtr arcade::SFML::GraphicalLibrary::createSprite(arcade::interface::graphic::TexturePtr texture)
{
    return (arcade::interface::graphic::SpritePtr(new arcade::SFML::Sprite(texture)));
}

arcade::interface::graphic::ColorPtr arcade::SFML::GraphicalLibrary::createColor()
{

}

arcade::interface::graphic::ColorPtr arcade::SFML::GraphicalLibrary::createColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{

}

arcade::interface::graphic::ColorPtr arcade::SFML::GraphicalLibrary::createColor(uint32_t color)
{

}

arcade::interface::graphic::RectanglePtr arcade::SFML::GraphicalLibrary::createRectangle()
{
    return (arcade::interface::graphic::RectanglePtr(new arcade::SFML::Rectangle()));
}

arcade::interface::graphic::RectanglePtr arcade::SFML::GraphicalLibrary::createRectangle(int top, int left, int width, int height)
{
    arcade::interface::graphic::RectanglePtr rect = arcade::interface::graphic::RectanglePtr(new arcade::SFML::Rectangle());

    rect->setTop(top);
    rect->setLeft(left);
    rect->setWidth(width);
    rect->setHeight(height);
    return (rect);
}

arcade::interface::graphic::Vector2fPtr arcade::SFML::GraphicalLibrary::createVector2f()
{
    return (arcade::interface::graphic::Vector2fPtr(new arcade::SFML::Vector2f()));
}

arcade::interface::graphic::Vector2fPtr arcade::SFML::GraphicalLibrary::createVector2f(float x, float y)
{
    return (arcade::interface::graphic::Vector2fPtr(new arcade::SFML::Vector2f(x, y)));
}

arcade::interface::graphic::Vector2iPtr arcade::SFML::GraphicalLibrary::createVector2i()
{
    return (arcade::interface::graphic::Vector2iPtr(new arcade::SFML::Vector2i()));
}

arcade::interface::graphic::Vector2iPtr arcade::SFML::GraphicalLibrary::createVector2i(int x, int y)
{
    return (arcade::interface::graphic::Vector2iPtr(new arcade::SFML::Vector2i(x, y)));
}

arcade::interface::graphic::FontPtr arcade::SFML::GraphicalLibrary::createFont(const std::string &path)
{
    arcade::interface::graphic::FontPtr font = arcade::interface::graphic::FontPtr(new arcade::SFML::Font());
    font->loadFromFile(path);
    return (font);
}

arcade::interface::graphic::TextPtr arcade::SFML::GraphicalLibrary::createText()
{
    return (arcade::interface::graphic::TextPtr(new arcade::SFML::Text()));
}

arcade::interface::graphic::TextPtr arcade::SFML::GraphicalLibrary::createText(arcade::interface::graphic::FontPtr font)
{
    arcade::interface::graphic::TextPtr text = arcade::interface::graphic::TextPtr(new arcade::SFML::Text(font));
    return (text);
}

arcade::interface::graphic::GLibPtr getGraphicalLibrary()
{
    return arcade::interface::graphic::GLibPtr(new arcade::SFML::GraphicalLibrary());
}