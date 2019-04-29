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
#include "Snake.hpp"
#include "../../EndMenu.hpp"
#include "arcade/interface/IGame.hpp"
#include "arcade/interface/graphic/IText.hpp"
#include "ScoreNibbler.hpp"
#include "../../Pause.hpp"

namespace arcade::Nibbler {
	class Game : public arcade::interface::IGame {
		public:
			Game();
			~Game();
			void init(arcade::interface::ResourceAllocator *manager, const arcade::interface::graphic::WindowPtr &window);
  			void refresh();
			void handleEvent();
			bool isRunning() const;
		protected:
		private:
			bool checkFood();
			bool checkHit();
			void createFood();
			bool detection(arcade::interface::graphic::SpritePtr, arcade::interface::graphic::SpritePtr) const;
			bool detection(arcade::interface::graphic::SpritePtr, std::vector<arcade::interface::graphic::SpritePtr>) const;
			void move();
			void pause();
			void end();


			int _direction = 2;
			bool isAlive = true;
			arcade::interface::graphic::WindowPtr _window;
			arcade::interface::ResourceAllocator *_manager;
			arcade::interface::graphic::SpritePtr _food;
			Snake _snake;
			Pause _pause;
			EndMenu _endMenu;
			ScoreNibbler _scores;
			int _score = 0;
			std::vector<arcade::interface::graphic::SpritePtr> _walls;
			size_t _lastLoop = 0;
			bool _isRunning = true;
			bool _isPaused = false;
			arcade::interface::graphic::TextPtr _scoreText;
			bool _end = false;
	};
}


#endif /* !GAME_HPP_ */
