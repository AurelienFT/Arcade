/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Button
*/

#pragma once
#include <iostream>
#include <dlfcn.h>
#include <string>
#include <arcade/interface/ResourceAllocator.hpp>
#include <arcade/interface/graphic/IWindow.hpp>

namespace arcade {
    class Button {
	    public:
          
		    explicit Button(const std::string filename, const std::string filename_2,
            const std::string filename_3, arcade::interface::graphic::WindowPtr window);
		    ~Button();
            bool button_text(std::string style, std::string txt, int64_t size_sprite, int64_t y_text);
            void draw_state_1(int64_t pos_x, int64_t pos_y, int64_t size_sprite);
            void draw_state_2(int64_t pos_x, int64_t pos_y, int64_t size_sprite);
            void draw_state_3(int64_t pos_x, int64_t pos_y, int64_t size_sprite);
            void set_activated(bool state);
            void create_button(const std::string filename, const std::string filename_2,
            const std::string filename_3, arcade::interface::graphic::WindowPtr window);
            bool _b_is_activated;

	    protected:
	    private:
            
            std::string _b_filename;
            std::string _b_filename_2;
            std::string _b_filename_3; 
            std::string _b_txt;
            std::string _b_style;
            arcade::interface::graphic::TextPtr _b_text;
            int64_t  _len_text;
            int64_t _y_text;
            int64_t _x_text;
            arcade::interface::graphic::TexturePtr _b_texture;
            arcade::interface::graphic::SpritePtr _b_state_1;
            arcade::interface::graphic::SpritePtr _b_state_2;
            arcade::interface::graphic::SpritePtr _b_state_3;
            arcade::interface::graphic::WindowPtr _window;
    };  
}