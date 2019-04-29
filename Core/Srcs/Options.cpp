/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Options
*/

#include "Options.hpp"
#include "Submenu.hpp"
#include "MenuLib.hpp"

Options::Options(arcade::interface::graphic::WindowPtr window):
_options("Res/state_1.png", "Res/state_2.png", "Res/state_3.png", window),
_l_arrow("Res/arrow_left_1.png", "Res/arrow_left_2.png", "Res/arrow_left_2.png", window),
_r_arrow("Res/arrow_right_1.png", "Res/arrow_right_2.png", "Res/arrow_right_2.png", window)
{
    std::vector<std::string> _tab {"SOUND", "FPS", "LIBRAIRY"};
    _tab_options = _tab;
    arcade::interface::graphic::EventPtr event;
    _event = event;
    _o_window = window;
    _sound = 20;
    _fps = 20;
    _index = 0;
    _nb_option = 3;
    _left = false;
    _right = false;
    _validate = 0;
    createBackground();
    createTitle("neon2.ttf", "OPTIONS");
    _options.button_text("Res/ka1.ttf", _tab_options[_index], 700, 510);
    _l_arrow.button_text("Res/ka1.ttf", "", 700, 530);
    _r_arrow.button_text("Res/ka1.ttf", "", 700, 530);
    _end = false;
}

bool Options::createBackground()
{
    arcade::interface::graphic::TexturePtr texture = arcade::interface::ResourceAllocator::instance()->createTexture();
    texture->loadFromFile("Res/fond.png");
    arcade::interface::graphic::SpritePtr sprite = arcade::interface::ResourceAllocator::instance()->createSprite(texture); 
    _o_background = sprite;
}

bool Options::createTitle(const std::string style, const std::string txt)
{
    arcade::interface::graphic::FontPtr font;
    arcade::interface::graphic::TextPtr text;
    font = arcade::interface::ResourceAllocator::instance()->createFont(style);
    text = arcade::interface::ResourceAllocator::instance()->createText(font);
    text->setString(txt);
    text->setCharacterSize(60);
    text->setPosition(550, 250);
    _o_title = text;
}

bool Options::optionsLoop()
{
    while (_o_window->isOpen()) {
		_o_window->clear();
		_event = _o_window->processEvent();
        if (_event != nullptr && _event->getType() == arcade::interface::graphic::IEvent::EventType::OnClosed)
			exit (0);
        if (_event != nullptr &&_event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyReleased 
        && _event->getKey() == arcade::interface::graphic::Key::Backspace)
            _end = true;
        if (_end == true)
            break;
        if (_event != nullptr &&_event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyPressed 
        && _event->getKey() == arcade::interface::graphic::Key::Enter)
            _validate = 1;
        if (_event != nullptr &&_event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyReleased 
        && _event->getKey() == arcade::interface::graphic::Key::Enter) {
            _validate = 2;
        }
        arrowsManager();
        optionsDisplay();
        _o_window->display();
    }
}

void Options::printButton()
{
    if(_validate == 1)
        _options.draw_state_2(400, 450, 700);
    else
        _options.draw_state_1(400, 450, 700);
}

void Options::eventRight()
{
    _index++;
    if (_index >= _nb_option )
        _index = 0;
    _options.button_text("Res/ka1.ttf", _tab_options[_index], 880, 510);
    _right == true;
}

void Options::eventLeft()
{
    _index--;
    if (_index < 0)
        _index = _nb_option - 1;
    _options.button_text("Res/ka1.ttf", _tab_options[_index], 880, 510);
    _left = true;

}
bool Options::arrowsManager()
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

void Options::printArrows()
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

void Options::soundManage()
{
    Submenu sound(_o_window, "SOUND", _sound);
    sound.submenuLoop();
    _validate = 0;
    _sound = sound.getValue();
}

void Options::fpsManage()
{
    Submenu fps(_o_window, "FPS", _fps);
    fps.submenuLoop();
    _validate = 0;
    _fps = fps.getValue();
}

void Options::libManage()
{
    MenuLib lib(_o_window);
    lib.loop_menu();
    _validate = 0;
}

void Options::submenu()
{
    if (_index == 0)
        soundManage();
    if (_index == 1)
        fpsManage();
    if (_index == 2)
        libManage();
}


bool Options::optionsDisplay()
{
    _o_window->draw(_o_background);
    _o_window->draw(_o_title);
    if(_validate == 2) {
        submenu();
    }
    printButton();
    printArrows();
}