/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "arcade/interface/graphic/Graphic.hpp"
#include "Vector2i.hpp"
#include "Vector2f.hpp"
#include <SFML/Graphics.hpp>
#include <string>

namespace arcade::SFML {
	class Window : public arcade::interface::graphic::IWindow {

	public:
		Window(const std::string name, CursorState cursor, arcade::interface::graphic::Vector2iPtr size);
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
        sf::RenderWindow _window;
        const std::string _w_name;
        CursorState _w_cursor;
        arcade::interface::graphic::Vector2iPtr _w_size;
        arcade::interface::graphic::EventPtr _currentEvent;
    };
}

#endif /* !WINDOW_HPP_ */
