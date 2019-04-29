/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** MenuName
*/

#include "MenuName.hpp"

arcade::MenuName::MenuName(arcade::interface::graphic::WindowPtr window):
_button("Res/state_1.png", "Res/state_2.png", "Res/state_3.png", window)
{
    arcade::interface::graphic::EventPtr event;
    _event = event;
    _window = window;
    createBackground();
    _button.button_text("Res/ka1.ttf", _name, 700, 610);
    createTitle("neon2.ttf", "ENTER YOUR NAME ");
    _end = false;
    _is_writting = false;
    _name = "";
}

bool arcade::MenuName::createBackground()
{
    arcade::interface::graphic::TexturePtr texture = arcade::interface::ResourceAllocator::instance()->createTexture();
    texture->loadFromFile("Res/fond.png");
    arcade::interface::graphic::SpritePtr sprite = arcade::interface::ResourceAllocator::instance()->createSprite(texture); 
    _background = sprite;
}


bool arcade::MenuName::createTitle(const std::string style, const std::string txt)
{
    arcade::interface::graphic::FontPtr font;
    arcade::interface::graphic::TextPtr text;
    
    font = arcade::interface::ResourceAllocator::instance()->createFont(style);
    text = arcade::interface::ResourceAllocator::instance()->createText(font);
    text->setString(txt);
    text->setCharacterSize(60);
    text->setPosition(460, 250);
    _title = text;
}

bool arcade::MenuName::nameBuild()
{
    if (_event->getKey() >= 0 && _event->getKey() <= 22 && _name.size() < 8) {
        char c = static_cast<char>(_event->getKey() + 97);
        _name.append(1, c);
        _is_writting = true;
        _button.button_text("Res/ka1.ttf", _name, 700, 510);
    }
    if (_event->getKey() == arcade::interface::graphic::Key::Delete && _name.length() > 0) {
        _name.erase(_name.begin() + (_name.length() - 1) , _name.end());
        _is_writting = true;
        _button.button_text("Res/ka1.ttf", _name, 700, 510);
    }
}

void arcade::MenuName::display()
{
    _window->draw(_background);
    _window->draw(_title);
    if (_is_writting == true) {
        _button.draw_state_2(400, 450, 700);
    }
    else
        _button.draw_state_1(400, 450, 700);
}

std::string arcade::MenuName::getName()
{
    return (_name);
}

bool arcade::MenuName::loop()
{
    while (_window->isOpen()) {
		_window->clear();
		_event = _window->processEvent();
		if (_event != nullptr && _event->getType() == arcade::interface::graphic::IEvent::EventType::OnClosed)
			exit (0);
        if (_event != nullptr && _event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyPressed && 
        _event->getKey() != arcade::interface::graphic::Key::Enter)
            nameBuild();
        if (_event != nullptr && _event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyPressed && 
        _event->getKey() == arcade::interface::graphic::Key::Enter) {
            _is_writting = true;
            if (std::strcmp(_name.c_str(), "") != 0)
                break;
        }
        if (_event != nullptr && _event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyReleased)
            _is_writting = false;
        if (_end == true)
            break;         
        display();
		_window->display();
    }
}