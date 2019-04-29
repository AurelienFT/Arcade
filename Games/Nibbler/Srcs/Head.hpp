/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Head
*/

#ifndef HEAD_HPP_
    #define HEAD_HPP_
    #include "arcade/interface/IGame.hpp"
    #include "arcade/interface/graphic/IWindow.hpp"
class Head {
	public:
		Head();
		~Head();

		arcade::interface::graphic::Vector2fPtr getLastHead() const;
		arcade::interface::graphic::SpritePtr getHead() const;

		void move(int direction);
		void initialize(arcade::interface::ResourceAllocator *manager, const arcade::interface::graphic::WindowPtr &window);
		void draw() const;

	protected:
	private:
		arcade::interface::ResourceAllocator *_manager;
		arcade::interface::graphic::Vector2fPtr _lastHead;
		arcade::interface::graphic::SpritePtr _head;
		arcade::interface::graphic::WindowPtr _window;
};

#endif /* !HEAD_HPP_ */