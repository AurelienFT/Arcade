/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Shoot
*/

#ifndef SHOOT_HPP_
    #define SHOOT_HPP_
    #include "arcade/interface/graphic/IWindow.hpp"
    #include "arcade/interface/IGame.hpp"

class Shoot {
	public:
		Shoot();
		~Shoot();

		void init(arcade::interface::ResourceAllocator *manager, std::string path);

		void move();
		void setDirection(arcade::interface::graphic::Vector2fPtr direction);
		void reset();

		arcade::interface::graphic::SpritePtr getShoot() const;

	protected:
	private:
		bool _isAvailable = true;
		arcade::interface::graphic::SpritePtr _shoot;
		arcade::interface::graphic::TexturePtr _shootTexture;
		arcade::interface::graphic::Vector2fPtr _direction;
		int _time = 0;
};

#endif /* !SHOOT_HPP_ */