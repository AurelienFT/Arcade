/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** EndMenu
*/

#ifndef ENDMENU_HPP_
    #define ENDMENU_HPP_

    #include <cstring>
    #include <string>
    #include "arcade/interface/IGame.hpp"

class EndMenu {
	public:
		EndMenu();
		~EndMenu();

		void init(arcade::interface::ResourceAllocator *manager, const arcade::interface::graphic::WindowPtr &window);
		void createTitle(const std::string style, const std::string txt);
		void refresh();
		bool isEnd() const;
		std::string getName() const;

	protected:
	private:
		bool nameBuild(arcade::interface::graphic::EventPtr event);
		
		arcade::interface::graphic::WindowPtr _window;
		arcade::interface::ResourceAllocator *_manager;
		arcade::interface::graphic::TextPtr _title;
		arcade::interface::graphic::TextPtr _nameText;
		std::string _name;
		bool _end;
	        bool _is_writting;
};

#endif /* !ENDMENU_HPP_ */