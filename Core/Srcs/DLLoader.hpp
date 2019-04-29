/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_
#include "arcade/interface/graphic/Graphic.hpp"
#include "arcade/interface/IGame.hpp"
#include <iostream>
#include <dlfcn.h>

class DLLoader {
	public:
		DLLoader();
		void *openGraphicLib(std::string name);
		void *openGameLib(std::string name);
		void closeGraphicalLib();
		void closeGameLib();
		~DLLoader();
	protected:
	private:
		void *_handle;
		void *_handle2;
};

#endif /* !DLLOADER_HPP_ */
