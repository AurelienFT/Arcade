/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Menu
*/

#include "Menu.hpp"
#include "Options.hpp"
#include "MenuScore.hpp"
#include "MenuGame.hpp"

arcade::Menu::Menu(arcade::interface::graphic::WindowPtr window) : 
_play("Res/button_1.png","Res/button_2.png", "Res/button_2.png", window),
_option("Res/button_1.png" ,"Res/button_2.png", "Res/button_2.png",window),
_score("Res/button_1.png" ,"Res/button_2.png", "Res/button_2.png",window) {
    _window = window;
    arcade::interface::graphic::EventPtr event;
    _event = event;
    _index = 0;
    _menu = 0;
    create_background();
    create_title("neon2.ttf", "ARCADE");
    _is_game = "";
	_is_lib = "";
	_end = false;
}

arcade::Menu::~Menu() {}

bool arcade::Menu::create_background()
{
    arcade::interface::graphic::TexturePtr texture = arcade::interface::ResourceAllocator::instance()->createTexture();
    if (!texture->loadFromFile("Res/fond.png"))
        throw std::exception();
    arcade::interface::graphic::SpritePtr sprite = arcade::interface::ResourceAllocator::instance()->createSprite(texture);
    _background = sprite;
}

bool arcade::Menu::create_title(const std::string style, const std::string txt)
{
    arcade::interface::graphic::FontPtr font;
    arcade::interface::graphic::TextPtr text;
    font = arcade::interface::ResourceAllocator::instance()->createFont(style);
    text = arcade::interface::ResourceAllocator::instance()->createText(font);
    text->setString(txt);
    _title = text;
}

bool arcade::Menu::create_elemt()
{
    _play.create_button("Res/button_1.png","Res/button_2.png", "Res/button_3.png", _window);
    _play.button_text( "Res/ka1.ttf", "PLAY", 880, 330);
    _option.create_button("Res/button_1.png","Res/button_2.png", "Res/button_3.png", _window);
    _option.button_text( "Res/ka1.ttf", "OPTIONS",  835, 480);
    _score.create_button("Res/button_1.png","Res/button_2.png", "Res/button_3.png", _window);
    _score.button_text( "Res/ka1.ttf", "SCORES",  835, 630);
    arcade::interface::graphic::EventPtr event;
    _event = event;
    create_background();
    _index = 0;
    _menu = 0;
    create_title("neon2.ttf", "ARCADE");
    _is_game = "";
	_is_lib = "";
	_end = false;
}

bool arcade::Menu::loop_menu()
{
    create_elemt();
    while (_window->isOpen()) {
		_window->clear();
		_event = _window->processEvent();
		if (_event != nullptr && _event->getType() == arcade::interface::graphic::IEvent::EventType::OnClosed)
			_Exit(0);
        if (_event != nullptr &&_event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyPressed 
        && _event->getKey() == arcade::interface::graphic::Key::Down) {
            if (_index == 2)
                _index = 0;
            else 
                _index++;
        }
        if (_event != nullptr &&_event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyPressed 
        && _event->getKey() == arcade::interface::graphic::Key::Up) {
            if (_index == 0)
                _index = 2;
            else 
                _index--;
        }
        if (_event != nullptr && _event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyPressed
        && _event->getKey() == arcade::interface::graphic::Key::Enter && !_enterPressed) {
            if (_index == 0)
                _play.set_activated(true);
            if (_index == 1)
                _option.set_activated(true);
            if (_index == 2)
                _score.set_activated(true);
            _enterPressed = true;
        }

        if (_event != nullptr && _event->getType() == arcade::interface::graphic::IEvent::EventType::OnKeyPressed
        && _event->getKey() == arcade::interface::graphic::Key::Enter && _enterPressed) {
            if (_index == 0)
                _play.set_activated(false);
            if (_index == 1)
                _option.set_activated(false);
            if (_index == 2)
                _score.set_activated(false);
            _menu = 2;
            _enterPressed = false;
        }
        if (_end == true)
            break;         
        display_menu();
		_window->display();
    }
}

bool arcade::Menu::display_menu()
{
    _window->draw(_background);

    if (_index == 2) {
        _play.draw_state_1(530, 300, 450);
        _option.draw_state_1(530, 450, 450);
        if (_score._b_is_activated == true)        
            _score.draw_state_3(530, 600, 450);
        else
            _score.draw_state_2(530, 600, 450);
    }
    if (_index == 1) {
        _play.draw_state_1(530, 300, 450);
        if (_option._b_is_activated == true)        
            _option.draw_state_3(530, 450, 450);
        else
            _option.draw_state_2(530, 450, 450);
        _score.draw_state_1(530, 600, 450);
    }
    if (_index == 0 ) {
        if (_play._b_is_activated == true)
            _play.draw_state_3(530, 300, 450);
        else
            _play.draw_state_2(530, 300, 450);
        _option.draw_state_1(530, 450, 450);
        _score.draw_state_1(530, 600, 450);
    }
    _title->setCharacterSize(120);
    _title->setPosition(500, 100);
    _window->draw(_title);

    if (_menu == 2 && _index == 0)
        display_game();
    if (_menu == 2 && _index == 1)
        display_options();
    if (_menu == 2 && _index == 2)
        displayScore();
}

bool arcade::Menu::display_options()
{
    Options options(_window);
    options.optionsLoop();
    _menu = 0;
}

bool arcade::Menu::display_game()
{
    MenuGame MenuGame(_window);
    MenuGame.loop_menu();
    _is_game = MenuGame.getGame();
    _is_lib = MenuGame.getLib();
    _player = MenuGame.getPlayer();
    _tab = MenuGame.getGames();
    _libTab = MenuGame.getLibs();
    if (std::strcmp(_is_game.c_str() , "" ) != 0 
    && std::strcmp(_is_lib.c_str(), "" ) != 0)
        _end = true;
    _menu = 0;
}

bool arcade::Menu::displayScore()
{
    MenuScore MenuScore(_window);

    MenuScore.loopScore();
    _menu = 0;
}

std::string arcade::Menu::getPlayer() const
{
    return (_player);
}

std::string arcade::Menu::getGame() const
{
    return (_is_game);
}

std::string arcade::Menu::getGame(int i) const
{
    return (_tab[i % _tab.size()]);
}

std::string arcade::Menu::getLib() const
{
    return (_is_lib);
}

std::string arcade::Menu::getLib(int i) const
{
    return (_libTab[i % _tab.size()]);
}