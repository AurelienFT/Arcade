/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Pause
*/

#include <iostream>
#include "Pause.hpp"

Pause::Pause()
{
}

Pause::~Pause()
{
}

int Pause::handleEvent()
{
	arcade::interface::graphic::EventPtr event = _window->getCurrentEvent();

	if (event) {
		if (event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyPressed) {
			arcade::interface::graphic::Key key = event->getKey(); 
			if (key == arcade::interface::graphic::Key::Enter)
				return 1;
			else if (key == arcade::interface::graphic::Key::Q)
				return 2;
			else if (key == arcade::interface::graphic::Key::R)
				return 3;
			else
				return 0;
		}
	}
}

void Pause::init(arcade::interface::ResourceAllocator *manager, const arcade::interface::graphic::WindowPtr &window)
{
	_window = window;
	_manager = manager;

	_fontText = manager->createFont("neon2.ttf");
	_pauseText = manager->createText(_fontText);
	_pauseText->setString("PAUSE");
	_pauseText->setPosition(_window->getSize()->getX() / 2, 200);

	_quitText = manager->createText(_fontText);
	_quitText->setString("Q - Quit");
	_quitText->setPosition(_window->getSize()->getX() / 4, 600);

	_resetText = manager->createText(_fontText);
	_resetText->setString("R - Reset");
	_resetText->setPosition(_window->getSize()->getX() / 2, 600);

	_continueText = manager->createText(_fontText);
	_continueText->setString("Enter - Continue");
	_continueText->setPosition((_window->getSize()->getX() / 4) * 3, 600);
}

void Pause::refresh()
{
	_window->draw(_pauseText);
	_window->draw(_quitText);
	_window->draw(_continueText);
	_window->draw(_resetText);
}