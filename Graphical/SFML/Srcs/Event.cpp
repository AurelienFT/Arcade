/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Event
*/

#include "Event.hpp"

arcade::SFML::Event::Event(sf::Event &event)
{
	_event = event;
}

arcade::SFML::Event::~Event()
{
}

arcade::interface::graphic::IEvent::EventType arcade::SFML::Event::getType()
{
	switch (_event.type) {
		case sf::Event::KeyPressed:
			return (arcade::interface::graphic::IEvent::EventType::OnKeyPressed);
		case sf::Event::KeyReleased:
			return (arcade::interface::graphic::IEvent::EventType::OnKeyReleased);
		case sf::Event::MouseButtonPressed:
			return (arcade::interface::graphic::IEvent::EventType::OnMousePressed);
		case sf::Event::MouseButtonReleased:
			return (arcade::interface::graphic::IEvent::EventType::OnMouseReleased);
		case sf::Event::MouseMoved:
			return (arcade::interface::graphic::IEvent::EventType::OnMouseMotion);
		case sf::Event::Closed:
			return (arcade::interface::graphic::IEvent::EventType::OnClosed);
		case sf::Event::Resized:
			return (arcade::interface::graphic::IEvent::EventType::OnResize);
		default:
			return (arcade::interface::graphic::IEvent::EventType::None);
	}
}

arcade::interface::graphic::Key arcade::SFML::Event::getKey()
{
	return (static_cast<arcade::interface::graphic::Key>(_event.key.code));
}
