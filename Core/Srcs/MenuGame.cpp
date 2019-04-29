/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** MenuGame
*/

#include "MenuGame.hpp"
#include "MenuLib.hpp"
#define _POSIX_SOURCE
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#undef _POSIX_SOURCE
#include <stdio.h>
#include <cstring>

MenuGame::MenuGame(arcade::interface::graphic::WindowPtr window) : Menu(window), 
_game("Res/state_1.png", "Res/state_2.png", "Res/state_3.png", window),
_l_arrow("Res/arrow_left_1.png", "Res/arrow_left_2.png", "Res/arrow_left_2.png", window),
_r_arrow("Res/arrow_right_1.png", "Res/arrow_right_2.png", "Res/arrow_right_2.png", window)
{
    arcade::interface::graphic::EventPtr event;
    _event = event;
    _g_window = window;
    _index = 0;
    _a_index = 0;
    find_game();
    create_background();
    _game.button_text("Res/ka1.ttf", _tab_game[_index], 700, 510);
    _l_arrow.button_text("Res/ka1.ttf", "", 700, 530);
    _r_arrow.button_text("Res/ka1.ttf", "", 700, 530);
    create_title("neon2.ttf", "CHOOSE YOUR GAME");
    _go_lib = 0;
    _is_game = _tab_game[_index];
    _is_lib = "";
    _end = false;
}

bool MenuGame::create_background()
{
    arcade::interface::graphic::TexturePtr texture = arcade::interface::ResourceAllocator::instance()->createTexture();
    texture->loadFromFile("Res/fond.png");
    arcade::interface::graphic::SpritePtr sprite = arcade::interface::ResourceAllocator::instance()->createSprite(texture); 
    _g_background = sprite;
}

bool MenuGame::create_title(const std::string style, const std::string txt)
{
    arcade::interface::graphic::FontPtr font;
    arcade::interface::graphic::TextPtr text;
    font = arcade::interface::ResourceAllocator::instance()->createFont(style);
    text = arcade::interface::ResourceAllocator::instance()->createText(font);
    text->setString(txt);
    text->setCharacterSize(60);
    text->setPosition(400, 250);
    _g_title = text;
}

bool MenuGame::create_elemt()
{
    arcade::interface::graphic::EventPtr event;
    _event = event;
    _g_window = _g_window;
    _index = 0;
    _a_index = 0;
    _game.create_button("Res/state_1.png", "Res/state_2.png", "Res/state_1.png", _g_window);
    _l_arrow.create_button("Res/arrow_left_1.png", "Res/arrow_left_2.png", "Res/arrow_left_2.png", _g_window);
    _r_arrow.create_button("Res/arrow_right_1.png", "Res/arrow_right_2.png", "Res/arrow_right_2.png", _g_window);
    _game.button_text("Res/ka1.ttf", _tab_game[_index], 880, 510);
    _l_arrow.button_text("Res/ka1.ttf", "", 880, 530);
    _r_arrow.button_text("Res/ka1.ttf", "", 880, 530);
    create_background();
    find_game();
    create_title("neon2.ttf", "CHOOSE YOUR GAME");
    _go_lib = 0;
    _is_game = _tab_game[_index];
    _is_lib = "";
    _end = false;
}

void MenuGame::event_right()
{
    _a_index = 2;
    if (_index >= _nb_game - 1)
        _index = 0;
    else 
        _index++;
    _game.button_text("Res/ka1.ttf", _tab_game[_index], 880, 510);
}

void MenuGame::event_left()
{
    _a_index = 1;
    if (_index == 0)
        _index = _nb_game - 1;
    else 
        _index--;
    _game.button_text("Res/ka1.ttf", _tab_game[_index], 880, 510);
}

bool MenuGame::event_manager()
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

bool MenuGame::loop_menu()
{
    while (_g_window->isOpen()) {
		_g_window->clear();
		_event = _g_window->processEvent();
        if (_event != nullptr && _event->getType() == arcade::interface::graphic::IEvent::EventType::OnClosed)
			exit (0);
        if (_event != nullptr &&_event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyReleased 
            && _event->getKey() == arcade::interface::graphic::Key::Escape)
            break;   
        if (_nb_game > 1)
            event_manager();
        if (_nb_game != 0) {
            if (_event != nullptr &&_event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyPressed 
            && _event->getKey() == arcade::interface::graphic::Key::Enter && !_enterPressed) {
                _go_lib = 1;
                _enterPressed = true;
            }
            if (_event != nullptr &&_event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyPressed 
            && _event->getKey() == arcade::interface::graphic::Key::Enter && _enterPressed) {
                _go_lib = 2;
                _is_game = _tab_game[_index];
                _enterPressed = false;
            }
        }
        if (_end == true)
            break;
        display_menu();
        _g_window->display();
    }
}

std::string MenuGame::parse_game(std::string name)
{
    std::string str = name.substr(11);
    std::size_t pos = str.find(".so");
    str.erase(str.begin() + pos, str.end());
    return (str);
}

bool MenuGame::find_game()
{
    DIR *dir;
    struct dirent *entry;
    std::string name ;
    size_t tab_length;

    if ((dir = opendir("games")) == NULL)
        throw std::exception();
    else {
        while ((entry = readdir(dir)) != NULL) {
            if (std::strcmp(entry->d_name, "..") != 0
            && std::strcmp(entry->d_name, ".") != 0) {
                name = parse_game(entry->d_name);
                _tab_game.push_back(name);
            }
        }
        _nb_game = _tab_game.size();
        closedir(dir);
    }
}

void MenuGame::print_button()
{
    if(_go_lib == 1)
        _game.draw_state_2(400, 450, 700);
    else
        _game.draw_state_1(400, 450, 700);
}

void MenuGame::print_arrows()
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

std::string MenuGame::getPlayer() const
{
    return (_player);
}

bool MenuGame::goLib()
{
    MenuLib MenuLib(_g_window);
    MenuLib.loop_menu();
    _is_lib = MenuLib.getLib();
    _tabLib = MenuLib.getLibs();
    _end = true;
    _go_lib = 0;
}

bool MenuGame::display_menu()
{
    _g_window->draw(_g_background);

    if (_nb_game > 1) {
        print_button();
        print_arrows();
    }
    if (_nb_game == 1)
        _game.draw_state_1(400, 450, 700);
    if (_nb_game == 0) {
        _game.draw_state_1(400, 450, 700);
        _game.button_text("Res/ka1.ttf", "No Game", 880, 510);
    }
    if (_go_lib == 2)
        goLib();
    _g_window->draw(_g_title);
}

std::string MenuGame::getGame() const
{
    return (_is_game);
}

std::vector<std::string> MenuGame::getGames() const
{
    return (_tab_game);
}

std::string MenuGame::getLib()
{
    return (_is_lib);
}


std::vector<std::string> MenuGame::getLibs() const
{
    return (_tabLib);
}