/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_
#include <vector>
#include <string>
#include "arcade/interface/IGame.hpp"
#include "Player.hpp"
#include "Bonus.hpp"
#include "Enemy.hpp"
#include "../../EndMenu.hpp"
#include "../../Pause.hpp"
#include "ScoreSolarFox.hpp"

namespace arcade::SolarFox {
	class Game : public arcade::interface::IGame {
		public:
			Game();
			~Game();
			void init(arcade::interface::ResourceAllocator *manager, const arcade::interface::graphic::WindowPtr &window);
  			void refresh();
			void handleEvent();
			bool isRunning () const;
		protected:
		private:
			bool detection(arcade::interface::graphic::SpritePtr, arcade::interface::graphic::SpritePtr) const;
			bool detection(arcade::interface::graphic::SpritePtr, std::vector<arcade::interface::graphic::SpritePtr>);
			void move();
			void pause();
			void end();

			arcade::interface::graphic::WindowPtr _window;
			arcade::interface::ResourceAllocator *_manager;
			arcade::interface::graphic::TexturePtr _wallTexture;
			arcade::interface::graphic::TexturePtr _wallVertTexture;
			std::vector<arcade::interface::graphic::SpritePtr> _walls;
			Player _player;
			Bonus _bonus;
			Enemy _enemies;
			Pause _pause;
			EndMenu _endMenu;
			ScoreSolarFox _scores;
			int _score = 0;
			std::vector<Bonus> _bonuses;
			size_t _lastLoop = 0;
			int _direction = 1;
			int _listHit = -1;
			bool _isRunning = true;
			bool _isPaused = false;
			arcade::interface::graphic::TextPtr _score_text;
			bool _end = false;
	};
}


#endif /* !GAME_HPP_ */
