/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Window
*/

#include <curses.h>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include "Window.hpp"
#include "Event.hpp"
#include "Text.hpp"
#include "Sprite.hpp"
#include "Vector2i.hpp"
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

arcade::nCurses::Window::Window()
{
    _window = initscr();
    timeout(0);
    attron(A_NORMAL);
    keypad(_window, TRUE);
    noecho();
    curs_set(0);
    int cols = 80;
    int lines = 24;

    #ifdef TIOCGSIZE
    struct ttysize ts;
    ioctl(STDIN_FILENO, TIOCGSIZE, &ts);
    cols = ts.ts_cols;
    lines = ts.ts_lines;
    #elif defined(TIOCGWINSZ)
    struct winsize ts;
    ioctl(STDIN_FILENO, TIOCGWINSZ, &ts);
    cols = ts.ws_col;
    lines = ts.ws_row;
    #endif /* TIOCGSIZE */

    _size = arcade::interface::graphic::Vector2iPtr(new arcade::nCurses::Vector2i(cols * 10, lines * 20));
}

arcade::nCurses::Window::~Window()
{
    attroff(A_NORMAL);
    endwin();
}

void arcade::nCurses::Window::copy(const IWindow &_window)
{
}

bool arcade::nCurses::Window::isOpen() const
{
    return (true);
}

void arcade::nCurses::Window::display()
{
    wrefresh(_window);
}

void arcade::nCurses::Window::clear()
{
    std::this_thread::sleep_for (std::chrono::milliseconds(10));
    wclear(_window);
}

void arcade::nCurses::Window::setName(const std::string &name)
{
}

const std::string &arcade::nCurses::Window::getName() const
{

}

arcade::interface::graphic::Vector2iPtr arcade::nCurses::Window::getSize() const
{
    return (_size);
}

void arcade::nCurses::Window::setSize(const arcade::interface::graphic::Vector2iPtr size)
{
}

bool arcade::nCurses::Window::hasFocus() const
{

}

arcade::interface::graphic::IWindow::CursorState arcade::nCurses::Window::cursorIsVisible() const
{

}

void arcade::nCurses::Window::setCursorState(arcade::interface::graphic::IWindow::CursorState state) 
{

}


void arcade::nCurses::Window::draw(const arcade::interface::graphic::TextPtr text)
{
   const char *to_display = (static_cast<std::string *>(static_cast<arcade::nCurses::Text *>(text.get())->getDrawable()))->c_str();
   mvprintw(text->getPosition()->getY() / 20, text->getPosition()->getX() / 10, to_display);
}

void arcade::nCurses::Window::draw(const arcade::interface::graphic::SpritePtr sprite)
{
    std::vector<std::string> asciiArt;
    int x = sprite->getPosition()->getX() / 10;
    int y = sprite->getPosition()->getY() / 20;

    asciiArt = *(static_cast<std::vector<std::string> *>(static_cast<arcade::nCurses::Sprite *>(sprite.get())->getDrawable()));
    for (auto it = asciiArt.begin(); it != asciiArt.end(); it++) {
        mvprintw(y, x, (*it).c_str());
        y++;
    }
}

arcade::interface::graphic::EventPtr arcade::nCurses::Window::processEvent()
{
    int keyCode = wgetch(_window);
    if (keyCode != -1) {
        _currentEvent = arcade::interface::graphic::EventPtr(new arcade::nCurses::Event(keyCode));
        return (_currentEvent);
    }
    else {
        _currentEvent = arcade::interface::graphic::EventPtr(nullptr);
        return (_currentEvent);
    }
}

arcade::interface::graphic::EventPtr arcade::nCurses::Window::getCurrentEvent() {return _currentEvent;}