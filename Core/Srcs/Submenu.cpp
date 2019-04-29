/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Submenu
*/

#include "Submenu.hpp"

Submenu::Submenu(arcade::interface::graphic::WindowPtr window, const std::string options, int32_t nb_option):
_option("Res/state_1.png", "Res/state_2.png", "Res/state_3.png", window),
_l_arrow("Res/arrow_left_1.png", "Res/arrow_left_2.png", "Res/arrow_left_2.png", window),
_r_arrow("Res/arrow_right_1.png", "Res/arrow_right_2.png", "Res/arrow_right_2.png", window)
{
    _index = nb_option;
    _left = false;
    _right = false;
    _end = false;
    _window = window;
    createBackground();
    createTitle("Res/ka1.ttf", options);
    _option.button_text("Res/ka1.ttf", std::to_string(_index), 700, 510);
    _l_arrow.button_text("Res/ka1.ttf", "", 700, 530);
    _r_arrow.button_text("Res/ka1.ttf", "", 700, 530);
}

bool Submenu::createBackground()
{
    arcade::interface::graphic::TexturePtr texture = arcade::interface::ResourceAllocator::instance()->createTexture();
    texture->loadFromFile("Res/fond.png");
    arcade::interface::graphic::SpritePtr sprite = arcade::interface::ResourceAllocator::instance()->createSprite(texture); 
    _background = sprite;
}

bool Submenu::createTitle(const std::string style, const std::string txt)
{
    arcade::interface::graphic::FontPtr font;
    arcade::interface::graphic::TextPtr text;
    font = arcade::interface::ResourceAllocator::instance()->createFont(style);
    text = arcade::interface::ResourceAllocator::instance()->createText(font);
    text->setString(txt);
    text->setCharacterSize(60);
    text->setPosition(650, 250);
    _title = text;
}

bool Submenu::submenuLoop()
{
    while (_window->isOpen()) {
		_window->clear();
		_event = _window->processEvent();
        if (_event != nullptr && _event->getType() == arcade::interface::graphic::IEvent::EventType::OnClosed)
			exit (0);
        if (_event != nullptr &&_event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyPressed
        && _event->getKey() == arcade::interface::graphic::Key::Enter)
            _validate = true;
        if (_event != nullptr &&_event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyReleased 
        && _event->getKey() == arcade::interface::graphic::Key::Enter) {
            _validate = false;
            break;
        }
        arrowsManager();
        optionsDisplay();
        _window->display();
    }
}

void Submenu::printButton()
{
    if(_validate == 1)
        _option.draw_state_2(400, 450, 700);
    else
        _option.draw_state_1(400, 450, 700);
}

void Submenu::eventRight()
{
    _index++;
    if (_index >= 100)
        _index = 0;
    _option.button_text("Res/ka1.ttf", std::to_string(_index) , 880, 510);
    _right == true;
}

void Submenu::eventLeft()
{
    _index--;
    if (_index < 0)
        _index = 100;
    _option.button_text("Res/ka1.ttf", std::to_string(_index), 880, 510);
    _left = true;

}

bool Submenu::arrowsManager()
{
    if (_event != nullptr &&_event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyPressed 
    && _event->getKey() == arcade::interface::graphic::Key::Right)
        eventRight();
    if (_event != nullptr &&_event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyPressed 
    && _event->getKey() == arcade::interface::graphic::Key::Left)
        eventLeft();
    if (_event != nullptr &&_event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyReleased 
    && _event->getKey() == arcade::interface::graphic::Key::Right)
        _right = false;
    if (_event != nullptr &&_event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyReleased 
    && _event->getKey() == arcade::interface::graphic::Key::Left)
        _left = false;
    }

void Submenu::printArrows()
{
    if (_right == true) {
        _r_arrow.draw_state_2(1200, 500, 700);
        _l_arrow.draw_state_1(250, 500, 700);
    }
    if (_left == true) {
        _r_arrow.draw_state_1(1200, 500, 700);
        _l_arrow.draw_state_2(250, 500, 700);
    }
    if (_left == false && _right == false) {
        _r_arrow.draw_state_1(1200, 500, 700);
        _l_arrow.draw_state_1(250, 500, 700);
    }
}

bool Submenu::optionsDisplay()
{
    _window->draw(_background);
    _window->draw(_title);
    printButton();
    printArrows();
}

int32_t Submenu::getValue()
{
    return (_index);
}