/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Window
*/

#include "Window.hpp"
#include "Event.hpp"
#include "Text.hpp"
#include "Sprite.hpp"
#include <iostream>
#include <SDL2/SDL_image.h>

arcade::SDL2::Window::Window(const std::string name, arcade::interface::graphic::Vector2iPtr size)
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
        throw std::exception();
    _window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, size->getX(), size->getY(), SDL_WINDOW_SHOWN);
    _renderer = SDL_CreateRenderer(_window, -1, 0);
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    _w_size = size;
    _w_name = name;
}

arcade::SDL2::Window::~Window()
{
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void arcade::SDL2::Window::copy(const IWindow &_window)
{
}

bool arcade::SDL2::Window::isOpen() const
{
    return (true);
}

void arcade::SDL2::Window::display()
{
    SDL_Delay(10);
    SDL_RenderPresent(_renderer);
}

void arcade::SDL2::Window::clear()
{
    SDL_RenderClear(_renderer);
}

void arcade::SDL2::Window::setName(const std::string &name)
{
}

const std::string &arcade::SDL2::Window::getName() const
{
    return(_w_name);
}

arcade::interface::graphic::Vector2iPtr arcade::SDL2::Window::getSize() const
{
    return (_w_size);
}

void arcade::SDL2::Window::setSize(const arcade::interface::graphic::Vector2iPtr size)
{
    _w_size->setX(size->getX());
    _w_size->setY(size->getY());
}

bool arcade::SDL2::Window::hasFocus() const
{

}

arcade::interface::graphic::IWindow::CursorState arcade::SDL2::Window::cursorIsVisible() const
{

}

void arcade::SDL2::Window::setCursorState(arcade::interface::graphic::IWindow::CursorState state) 
{

}


void arcade::SDL2::Window::draw(const arcade::interface::graphic::TextPtr text)
{
    int texW = 0;
    int texH = 0;
    
    SDL_Surface *text2 = TTF_RenderText_Solid((static_cast<TTF_Font *> (static_cast<arcade::SDL2::Font *>(text->getFont().get())->getLibObject())), text->getString().c_str(), {255, 255, 255});
    SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, text2);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = {static_cast<int>(text->getPosition()->getX()), static_cast<int>(text->getPosition()->getY()), texW, texH};
    SDL_RenderCopy(_renderer, texture, NULL, &dstrect);
    SDL_FreeSurface (text2);
    SDL_DestroyTexture (texture);
}

void arcade::SDL2::Window::draw(const arcade::interface::graphic::SpritePtr sprite)
{
    int texW = 0;
    int texH = 0;


    SDL_Surface *image = IMG_Load(static_cast<char *>(static_cast<arcade::SDL2::Sprite *>(sprite.get())->getDrawable()));
    if (!image) {
        throw std::exception();
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, image);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = {static_cast<int>(sprite->getPosition()->getX()), static_cast<int>(sprite->getPosition()->getY()), texW, texH};
    SDL_RenderCopy(_renderer, texture, NULL, &dstrect);
    SDL_FreeSurface (image);
    SDL_DestroyTexture (texture);
}

arcade::interface::graphic::EventPtr arcade::SDL2::Window::processEvent()
{
    SDL_Event e;

    if (SDL_PollEvent(&e) != 0) {
        _currentEvent = arcade::interface::graphic::EventPtr(new arcade::SDL2::Event(e)); 
        return (_currentEvent);
    } else {
        _currentEvent = arcade::interface::graphic::EventPtr(nullptr); 
        return (_currentEvent);
    }
}

arcade::interface::graphic::EventPtr arcade::SDL2::Window::getCurrentEvent() {return _currentEvent;}