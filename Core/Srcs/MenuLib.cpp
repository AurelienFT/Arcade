/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** MenuLib
*/

#include "MenuLib.hpp"
#define _POSIX_SOURCE
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#undef _POSIX_SOURCE
#include <stdio.h>
#include <cstring>
#include "MenuName.hpp"

MenuLib::MenuLib(arcade::interface::graphic::WindowPtr window) : MenuGame(window), 
_lib("Res/state_1.png", "Res/state_2.png", "Res/state_3.png", window),
_l_arrow("Res/arrow_left_1.png", "Res/arrow_left_2.png", "Res/arrow_left_2.png", window),
_r_arrow("Res/arrow_right_1.png", "Res/arrow_right_2.png", "Res/arrow_right_2.png", window)
{
    arcade::interface::graphic::EventPtr event;
    _event = event;
    _l_window = window;
    _index = 0;
    _a_index = 0;
    find_game();
    create_background();
    _lib.button_text("Res/ka1.ttf", _tab_lib[_index], 700, 510);
    _l_arrow.button_text("Res/ka1.ttf", "", 700, 530);
    _r_arrow.button_text("Res/ka1.ttf", "", 700, 530);
    create_title("neon2.ttf", "CHOOSE YOUR LIBRAIRY");
    _go_game = 0;
    _is_lib = "";
    _end = false;
}

bool MenuLib::create_background()
{
    arcade::interface::graphic::TexturePtr texture = arcade::interface::ResourceAllocator::instance()->createTexture();
    texture->loadFromFile("Res/fond.png");
    arcade::interface::graphic::SpritePtr sprite = arcade::interface::ResourceAllocator::instance()->createSprite(texture); 
    _l_background = sprite;
}

bool MenuLib::create_title(const std::string style, const std::string txt)
{
    arcade::interface::graphic::FontPtr font;
    arcade::interface::graphic::TextPtr text;
    
    font = arcade::interface::ResourceAllocator::instance()->createFont(style);
    text = arcade::interface::ResourceAllocator::instance()->createText(font);
    text->setString(txt);
    text->setCharacterSize(60);
    text->setPosition(360, 250);
    _l_title = text;
}

bool MenuLib::create_elemt()
{
    arcade::interface::graphic::EventPtr event;
    _event = event;
    _l_window = _l_window;
    _index = 0;
    _a_index = 0;
    _l_arrow.create_button("Res/state_1.png", "Res/state_2.png", "Res/state_1.png", _l_window);
    _l_arrow.create_button("Res/arrow_left_1.png", "Res/arrow_left_2.png", "Res/arrow_left_2.png", _l_window);
    _r_arrow.create_button("Res/arrow_right_1.png", "Res/arrow_right_2.png", "Res/arrow_right_2.png", _l_window);
    _lib.button_text("Res/ka1.ttf", _tab_lib[_index], 880, 510);
    _l_arrow.button_text("Res/ka1.ttf", "", 880, 530);
    _r_arrow.button_text("Res/ka1.ttf", "", 880, 530);
    create_background();
    find_game();
    create_title("neon2.ttf", "CHOOSE YOUR GAME");
    _go_game = 0;
    _is_lib = _tab_lib[_index];
    _end = false;
}

void MenuLib::event_right()
{
    _a_index = 2;
    if (_index >= _nb_lib - 1)
        _index = 0;
    else 
        _index++;
    _lib.button_text("Res/ka1.ttf", _tab_lib[_index], 880, 510);
}

void MenuLib::event_left()
{
    _a_index = 1;
    if (_index == 0)
        _index = _nb_lib - 1;
    else 
        _index--;
    _lib.button_text("Res/ka1.ttf", _tab_lib[_index], 880, 510);
}

std::string MenuLib::getLib()
{
    return (_is_lib);
}

std::string MenuLib::getPlayer()
{
    return (_player);
}

bool MenuLib::event_manager()
{
    if (_event != nullptr &&_event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyPressed 
    && _event->getKey() == arcade::interface::graphic::Key::Right)
        event_right();
    if (_event != nullptr &&_event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyPressed 
    && _event->getKey() == arcade::interface::graphic::Key::Left)
        event_left();
    if (_event != nullptr &&_event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyReleased 
    && _event->getKey() == arcade::interface::graphic::Key::Right)
        _a_index = 0;
    if (_event != nullptr &&_event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyReleased 
    && _event->getKey() == arcade::interface::graphic::Key::Left)
        _a_index = 0;
}

bool MenuLib::loop_menu()
{
    while (_l_window->isOpen()) {
        _l_window->clear();
        _event = _l_window->processEvent();
        if (_event != nullptr && _event->getType() == arcade::interface::graphic::IEvent::EventType::OnClosed)
            exit (0);
        if (_event != nullptr &&_event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyReleased 
        && _event->getKey() == arcade::interface::graphic::Key:: Backspace) {
            break;
        }
        if (_nb_lib > 1)
            event_manager();
        if (_nb_lib != 0) {
            if (_event != nullptr &&_event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyPressed 
            && _event->getKey() == arcade::interface::graphic::Key::Enter && !_enterPressed) {
                _go_game = 1;
                _enterPressed = true;
            } if (_event != nullptr &&_event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyPressed 
            && _event->getKey() == arcade::interface::graphic::Key::Enter && _enterPressed) {
                _go_game = 2;
                _is_lib = _tab_lib[_index];
                _enterPressed = false;
            }
            if (_end == true)
                break;
        }
        display_menu();
        _l_window->display();
    }
}

bool MenuLib::find_game()
{
    DIR *dir;
    struct dirent *entry;
    std::string name ;
    size_t tab_length;

    if ((dir = opendir("lib")) == NULL)
        throw std::exception();
    else {
        while ((entry = readdir(dir)) != NULL) {
            if (std::strcmp(entry->d_name, "..") != 0
            && std::strcmp(entry->d_name, ".") != 0) {
                name = parse_game(entry->d_name);
                _tab_lib.push_back(name);
            }
        }
        _nb_lib = _tab_lib.size();
        closedir(dir);
    }
}

void MenuLib::print_button()
{
    if(_go_game == 1)
        _lib.draw_state_2(400, 450, 700);
    else
        _lib.draw_state_1(400, 450, 700);
}

void MenuLib::print_arrows()
{
    if (_a_index == 2) {
        _r_arrow.draw_state_2(1200, 500, 700);
        _l_arrow.draw_state_1(250, 500, 700);
    }
    if (_a_index == 1) {
        _r_arrow.draw_state_1(1200, 500, 700);
        _l_arrow.draw_state_2(250, 500, 700);
    }
    if (_a_index == 0 ) {
        _r_arrow.draw_state_1(1200, 500, 700);
        _l_arrow.draw_state_1(250, 500, 700);
    }
}

bool MenuLib::diplay_name()
{
    arcade::MenuName name(_l_window);
    name.loop();
    if (strcmp(name.getName().c_str(), "")) {
        _player = name.getName();
    }
    _end = 2;
}

bool MenuLib::display_menu()
{
    _l_window->draw(_l_background);
    if (_nb_lib > 1) {
        print_button();
        print_arrows();
    }
    if (_go_game == 2)
        diplay_name();
    if (_nb_lib == 1)
        _lib.draw_state_1(400, 450, 700);
    if (_nb_lib == 0) {
     _lib.draw_state_1(400, 450, 700);
     _lib.button_text("Res/ka1.ttf", "No Lib", 880, 510);
    }
    _l_window->draw(_l_title);
}

std::vector<std::string> MenuLib::getLibs() const
{
    return (_tab_lib);
}