/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Enemy
*/

#ifndef ENEMY_HPP_
    #define ENEMY_HPP_

    #include <vector>
    #include "arcade/interface/graphic/IWindow.hpp"
    #include "arcade/interface/IGame.hpp"

class Enemy {
	public:
		Enemy(int isRight = -1);
		~Enemy();

		void init(arcade::interface::ResourceAllocator *manager, arcade::interface::graphic::WindowPtr window);

		void move();
		void shoot();
		void draw();
		void hit(int i);
		void hitDown(int i);

		arcade::interface::graphic::SpritePtr getEnemy() const;
		std::vector<arcade::interface::graphic::SpritePtr> getShoots() const;
		std::vector<arcade::interface::graphic::SpritePtr> getShootsDown() const;

	protected:
	private:
		arcade::interface::graphic::TexturePtr _shootTexture;
		arcade::interface::graphic::TexturePtr _shootDownTexture;
		arcade::interface::graphic::SpritePtr _enemy;
		arcade::interface::graphic::SpritePtr _enemyDown;
		arcade::interface::graphic::TexturePtr _enemyTexture;
		arcade::interface::graphic::TexturePtr _enemyDownTexture;
		arcade::interface::graphic::WindowPtr _window;
		arcade::interface::ResourceAllocator *_manager;
		std::vector<arcade::interface::graphic::SpritePtr> _shoots;
		std::vector<arcade::interface::graphic::SpritePtr> _shootsDown;
		int _isRight;
		bool isNextShottUp = true;
		size_t _time = 0;
};

#endif /* !ENEMY_HPP_ */
