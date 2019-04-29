/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
    #define SNAKE_HPP_
    #include <vector>
    #include "Head.hpp"

class Snake {
	public:
		Snake();
		~Snake();

		void move(int direction);
		void addTail();
		arcade::interface::graphic::SpritePtr getHead() const;
		std::vector<arcade::interface::graphic::SpritePtr> getTail() const;
		void initialize(arcade::interface::ResourceAllocator *manager, const arcade::interface::graphic::WindowPtr &window);
		void draw() const;

	protected:
	private:
		arcade::interface::graphic::Vector2fPtr _lastTail;
		arcade::interface::ResourceAllocator *_manager;
		arcade::interface::graphic::TexturePtr _texture;
		std::vector<arcade::interface::graphic::SpritePtr> _tails;
		arcade::interface::graphic::WindowPtr _window;
		Head _head;
};

#endif /* !SNAKE_HPP_ */