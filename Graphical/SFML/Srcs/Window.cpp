/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Window
*/

#include <SFML/Graphics/Color.hpp>
#include <iostream>
#include "Window.hpp"
#include "Event.hpp"
#include "Text.hpp"
#include "Sprite.hpp"

arcade::SFML::Window::Window(const std::string name, CursorState cursor, arcade::interface::graphic::Vector2iPtr size)
{
    _window.create(sf::VideoMode(size->getX(), size->getY()), name);
    _window.setFramerateLimit(60);
    _w_size = size;
}

arcade::SFML::Window::~Window()
{
    _window.close();
}

void arcade::SFML::Window::copy(const IWindow &_window)
{
}

bool arcade::SFML::Window::isOpen() const
{
    return (_window.isOpen());
}

void arcade::SFML::Window::display()
{
    _window.display();
}

void arcade::SFML::Window::clear()
{
    _window.clear();
}

void arcade::SFML::Window::setName(const std::string &name)
{
}

const std::string &arcade::SFML::Window::getName() const
{
    return(_w_name);
}

arcade::interface::graphic::Vector2iPtr arcade::SFML::Window::getSize() const
{
    return (_w_size);
}

void arcade::SFML::Window::setSize(const arcade::interface::graphic::Vector2iPtr size)
{
    _w_size->setX(size->getX());
    _w_size->setY(size->getY());
    _window.setSize(sf::Vector2u(_w_size->getX(), _w_size->getY()));
}

bool arcade::SFML::Window::hasFocus() const
{

}

arcade::interface::graphic::IWindow::CursorState arcade::SFML::Window::cursorIsVisible() const
{

}

void arcade::SFML::Window::setCursorState(arcade::interface::graphic::IWindow::CursorState state) 
{

}


void arcade::SFML::Window::draw(const arcade::interface::graphic::TextPtr text)
{
    _window.draw(*(static_cast<sf::Text*>(static_cast<arcade::SFML::Text *>(text.get())->getDrawable())));
}

void arcade::SFML::Window::draw(const arcade::interface::graphic::SpritePtr sprite)
{
    _window.draw(*(static_cast<sf::Sprite*>(static_cast<arcade::SFML::Sprite *>(sprite.get())->getDrawable())));
}

arcade::interface::graphic::EventPtr arcade::SFML::Window::processEvent()
{
    sf::Event evt;
    
    if (_window.pollEvent(evt)) {
        _currentEvent = arcade::interface::graphic::EventPtr(new arcade::SFML::Event(evt)); 
        return (_currentEvent);
    }
    else {
        _currentEvent = arcade::interface::graphic::EventPtr(nullptr); 
        return (_currentEvent);
    }
}

arcade::interface::graphic::EventPtr arcade::SFML::Window::getCurrentEvent() {return _currentEvent;}