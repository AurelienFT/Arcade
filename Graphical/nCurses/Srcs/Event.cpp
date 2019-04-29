/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Event
*/

#include <algorithm>
#include <iostream>
#include "Event.hpp"

arcade::nCurses::Event::Event(int keyCode)
{
	_keyCode = keyCode;
}

arcade::nCurses::Event::~Event()
{
}

arcade::interface::graphic::IEvent::EventType arcade::nCurses::Event::getType()
{
	return (arcade::interface::graphic::IEvent::OnKeyPressed);
}

arcade::interface::graphic::Key arcade::nCurses::Event::getKey()
{
	std::vector<int>::iterator it = std::find(_key.begin(), _key.end(), _keyCode);
	return static_cast<arcade::interface::graphic::Key>(std::distance(_key.begin(), it));
}

