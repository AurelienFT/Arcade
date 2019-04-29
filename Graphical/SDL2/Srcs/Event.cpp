/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Event
*/

#include "Event.hpp"
#include <algorithm>
#include <iostream>

arcade::SDL2::Event::Event(SDL_Event &event)
{
	_event = event;
}

arcade::SDL2::Event::~Event()
{
}

arcade::interface::graphic::IEvent::EventType arcade::SDL2::Event::getType()
{
	switch (_event.type) {
		case SDL_KEYDOWN:
			return (arcade::interface::graphic::IEvent::EventType::OnKeyPressed);
		case SDL_KEYUP:
			return (arcade::interface::graphic::IEvent::EventType::OnKeyReleased);
		case SDL_MOUSEBUTTONDOWN:
			return (arcade::interface::graphic::IEvent::EventType::OnMousePressed);
		case SDL_MOUSEBUTTONUP:
			return (arcade::interface::graphic::IEvent::EventType::OnMouseReleased);
		case SDL_MOUSEMOTION:
			return (arcade::interface::graphic::IEvent::EventType::OnMouseMotion);
		case SDL_QUIT:
			return (arcade::interface::graphic::IEvent::EventType::OnClosed);
		case SDL_WINDOWEVENT_CLOSE:
			return (arcade::interface::graphic::IEvent::EventType::OnClosed);
		case SDL_WINDOWEVENT_RESIZED:
			return (arcade::interface::graphic::IEvent::EventType::OnResize);
		default:
			return (arcade::interface::graphic::IEvent::EventType::None);
	}
}

arcade::interface::graphic::Key arcade::SDL2::Event::getKey()
{
	if (_event.type != SDL_KEYDOWN && _event.type != SDL_KEYUP)
		return arcade::interface::graphic::Key::Unknown;
	std::vector<SDL_Keycode>::iterator it = std::find(_key.begin(), _key.end(), _event.key.keysym.sym);
	return static_cast<arcade::interface::graphic::Key>(std::distance(_key.begin(), it));
}

