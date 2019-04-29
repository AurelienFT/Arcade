/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Button 
*/

#include "Button.hpp"
#include <cstring>

arcade::Button::Button(const std::string filename, const std::string filename_2, const std::string filename_3, arcade::interface::graphic::WindowPtr window):
 _b_filename(filename), _b_filename_2(filename_2), _b_filename_3(filename_3), _window(window) {

    _b_filename = filename;
    _b_filename_2 = filename_2;
    _b_filename_3 = filename_3;
    _window = window;

    _b_texture = arcade::interface::ResourceAllocator::instance()->createTexture();
    _b_texture->loadFromFile(_b_filename);
    _b_state_1 = arcade::interface::ResourceAllocator::instance()->createSprite(_b_texture);
    
    _b_texture = arcade::interface::ResourceAllocator::instance()->createTexture();
    _b_texture->loadFromFile(_b_filename_2);
    _b_state_2 = arcade::interface::ResourceAllocator::instance()->createSprite(_b_texture);

    _b_texture = arcade::interface::ResourceAllocator::instance()->createTexture();
    _b_texture->loadFromFile(_b_filename_3);
    _b_state_3 = arcade::interface::ResourceAllocator::instance()->createSprite(_b_texture);
    _b_is_activated = false;
}

arcade::Button::~Button () {}

void arcade::Button::create_button(std::string filename, const std::string filename_2,
const std::string filename_3, arcade::interface::graphic::WindowPtr window)
{
    _b_filename = filename;
    _b_filename_2 = filename_2;
    _b_filename_3 = filename_3;
    _window = window;

    _b_texture = arcade::interface::ResourceAllocator::instance()->createTexture();
    _b_texture->loadFromFile(_b_filename);
    _b_state_1 = arcade::interface::ResourceAllocator::instance()->createSprite(_b_texture);
    _b_texture = arcade::interface::ResourceAllocator::instance()->createTexture();
    _b_texture->loadFromFile(_b_filename_2);
    _b_state_2 = arcade::interface::ResourceAllocator::instance()->createSprite(_b_texture);

    _b_texture = arcade::interface::ResourceAllocator::instance()->createTexture();
    _b_texture->loadFromFile(_b_filename_3);
    _b_state_3 = arcade::interface::ResourceAllocator::instance()->createSprite(_b_texture);
    _b_is_activated = false;
}

bool arcade::Button::button_text(std::string style, std::string txt, int64_t pos_x, int64_t pos_y) {
    
    arcade::interface::graphic::FontPtr font;
    arcade::interface::graphic::TextPtr text;
    _y_text = pos_y;
    _len_text = strlen(txt.c_str());
    font = arcade::interface::ResourceAllocator::instance()->createFont(style);
    text = arcade::interface::ResourceAllocator::instance()->createText(font);
    text->setString(txt);
    text->setCharacterSize(50);
    _b_text = text;
}

void arcade::Button::set_activated(bool state)
{
    _b_is_activated = state;
}

void arcade::Button::draw_state_1(int64_t pos_x, int64_t pos_y, int64_t size_sprite)
{
    size_t center = size_sprite / 2;
    size_t size = _len_text * 37;
    
    _b_state_1->setPosition(pos_x, pos_y);
    _b_text->setPosition(pos_x + center - size / 2 - 15, _y_text);
    _window->draw(_b_state_1);
    _window->draw(_b_text);
}

void arcade::Button::draw_state_2(int64_t pos_x, int64_t pos_y, int64_t size_sprite)
{
    size_t center = size_sprite / 2;
    size_t size = _len_text * 37;

    _b_state_2->setPosition(pos_x , pos_y + 1);
    _b_text->setPosition(pos_x + center - size / 2 - 15, _y_text);
    _window->draw(_b_state_2);
    _window->draw(_b_text);
}

void arcade::Button::draw_state_3(int64_t pos_x, int64_t pos_y, int64_t size_sprite)
{
    size_t center = size_sprite / 2;
    size_t size = _len_text * 37;

    _b_state_3->setPosition(pos_x, pos_y + 1);
    _b_text->setPosition(pos_x + center - size/2 - 15, _y_text);
    _window->draw(_b_state_3);
    _window->draw(_b_text);
}