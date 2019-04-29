/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Player
*/

#ifndef PLAYER_HPP_
    #define PLAYER_HPP_

    #include <vector>
    #include "arcade/interface/graphic/IWindow.hpp"
    #include "arcade/interface/IGame.hpp"
    #include "Shoot.hpp"
    
class Player {
	public:
		Player();
		~Player();

		void init(arcade::interface::ResourceAllocator *manager, arcade::interface::graphic::WindowPtr window);

		Shoot getShoot() const;
		arcade::interface::graphic::SpritePtr getPlayer() const;

		void move(int direction);
		void shoot();
		void draw();
		void hit();

	protected:
	private:
		arcade::interface::ResourceAllocator *_manager;
		arcade::interface::graphic::WindowPtr _window;
		arcade::interface::graphic::SpritePtr _player;
		std::vector<arcade::interface::graphic::TexturePtr> _playerTexture;
		Shoot _shoot;
		int _lastDirection = 1;
		
};

#endif /* !PLAYER_HPP_ */