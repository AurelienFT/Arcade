/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Pause
*/

#ifndef PAUSE_HPP_
    #define PAUSE_HPP_

    #include "arcade/interface/IGame.hpp"

class Pause {
	public:
		Pause();
		~Pause();

		void init(arcade::interface::ResourceAllocator *manager, const arcade::interface::graphic::WindowPtr &window);
		void refresh();
		int handleEvent();

	protected:
	private:
		arcade::interface::graphic::WindowPtr _window;
		arcade::interface::ResourceAllocator *_manager;
		arcade::interface::graphic::FontPtr _fontText;
		arcade::interface::graphic::TextPtr _pauseText;
		arcade::interface::graphic::TextPtr _continueText;
		arcade::interface::graphic::TextPtr _quitText;
		arcade::interface::graphic::TextPtr _resetText;
};

#endif /* !PAUSE_HPP_ */
