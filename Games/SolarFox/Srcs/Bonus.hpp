/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Bonus
*/

#ifndef BONUS_HPP_
    #define BONUS_HPP_

    #include "arcade/interface/IGame.hpp"

class Bonus {
	public:
		Bonus();
		~Bonus();

		std::vector<arcade::interface::graphic::SpritePtr> getBonus() const;

		void init(arcade::interface::ResourceAllocator *manager, const arcade::interface::graphic::WindowPtr &window, char *map);
		void draw();
		void hit(int i);

	protected:
	private:
		void getMap(std::string path);

		arcade::interface::graphic::WindowPtr _window;
		arcade::interface::ResourceAllocator *_manager;
		arcade::interface::graphic::TexturePtr _bonusTexture;
		std::vector<arcade::interface::graphic::SpritePtr> _bonus;
		std::vector<std::string> _map;

};

#endif /* !BONUS_HPP_ */