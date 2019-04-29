/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** EndMenu
*/

#include <iostream>
#include "EndMenu.hpp"

EndMenu::EndMenu()
{
}

EndMenu::~EndMenu()
{
}

void EndMenu::init(arcade::interface::ResourceAllocator *manager, const arcade::interface::graphic::WindowPtr &window)
{
	_window = window;
	_manager = manager;
	createTitle("neon2.ttf", "ENTER YOUR NAME ");
	_name = "";
}

void EndMenu::createTitle(const std::string style, const std::string txt)
{
    arcade::interface::graphic::FontPtr font;
    
    font = _manager->createFont(style);
    _title = _manager->createText(font);
    _title->setString(txt);
    _title->setCharacterSize(60);
    _title->setPosition(460, 250);
    _nameText = _manager->createText(font);
    _nameText->setString(_name);
    _nameText->setCharacterSize(60);
    _nameText->setPosition(460, 450);
}

void EndMenu::refresh()
{
    arcade::interface::graphic::EventPtr event = _window->getCurrentEvent();

    _window->draw(_title);
    _window->draw(_nameText);
    if (event == nullptr)
        return;
    if (event->getType() != arcade::interface::graphic::IEvent::EventType::OnKeyPressed)
        return;
    if (event->getKey() != arcade::interface::graphic::Key::Enter)
        nameBuild(event);
    else
        if (std::strcmp(_name.c_str(), "") != 0)
            _end = true;
    while (_window->processEvent() != nullptr);
}

bool EndMenu::nameBuild(arcade::interface::graphic::EventPtr event)
{
    if (event->getKey() >= 0 && event->getKey() <= 22 && _name.size() < 8) {
        char c = static_cast<char>(event->getKey() + 97);
        _name.append(1, c);
    }
    if (event->getKey() == arcade::interface::graphic::Key::Delete && _name.length() > 0)
        _name.erase(_name.begin() + (_name.length() - 1) , _name.end());
    _nameText->setString(_name);
}

bool EndMenu::isEnd() const {return _end;}
std::string EndMenu::getName() const {return _name;}