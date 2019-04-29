/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Event
*/

#ifndef EVENT_HPP_
    #define EVENT_HPP_
#include "arcade/interface/graphic/IEvent.hpp"
#include <SFML/Window/Event.hpp>
#include "arcade/interface/graphic/IWindow.hpp"

namespace arcade::SFML {
	class Event : public arcade::interface::graphic::IEvent {
		public:
			Event(sf::Event &event);
			~Event();
			arcade::interface::graphic::IEvent::EventType getType();
			arcade::interface::graphic::Key getKey();
		protected:
		private:
			sf::Event _event;
	};
}

#endif /* !EVENT_HPP_ */
