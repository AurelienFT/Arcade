/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "arcade/interface/graphic/Graphic.hpp"
#include "arcade/interface/graphic/IWindow.hpp"
#include <curses.h>
#include <string>

namespace arcade::nCurses {
	class Window : public arcade::interface::graphic::IWindow {

	public:
		Window();
		~Window();
        void copy(const IWindow &_window);
        bool isOpen() const;
        void clear();
        void display();
        const std::string &getName() const;
        void setName(const std::string &name);
        arcade::interface::graphic::Vector2iPtr getSize() const;
        void setSize(const arcade::interface::graphic::Vector2iPtr size);
        bool hasFocus() const;
        arcade::interface::graphic::IWindow::CursorState cursorIsVisible() const;
        void setCursorState(arcade::interface::graphic::IWindow::CursorState state);
        void draw(const arcade::interface::graphic::TextPtr text);
        void draw(const arcade::interface::graphic::SpritePtr sprite); 
        arcade::interface::graphic::EventPtr processEvent();
        arcade::interface::graphic::EventPtr getCurrentEvent();

    protected:
	private:
        arcade::interface::graphic::EventPtr _currentEvent;
        arcade::interface::graphic::Vector2iPtr _size;
        WINDOW *_window;
    };
}

#endif /* !WINDOW_HPP_ */
