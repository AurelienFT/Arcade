/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** DLLoader
*/

#include "DLLoader.hpp"

DLLoader::DLLoader()
{
}

void *DLLoader::openGraphicLib(std::string name)
{
	_handle = dlopen(name.c_str(), RTLD_LAZY);

	if (!_handle) {
		std::cerr << dlerror() << std::endl;
		exit(84);
	}
	dlerror();
	void *getGraphicalLibrary = dlsym(_handle, "getGraphicalLibrary");
	char *error = dlerror();
	if (error != NULL) {
		std::cerr << error << std::endl;
	}
	return getGraphicalLibrary;
	 
}

void *DLLoader::openGameLib(std::string name)
{
	_handle2 = dlopen(name.c_str(), RTLD_LAZY);

	if (!_handle2) {
		std::cerr << dlerror() << std::endl;
		exit(84);
	}
	dlerror();
	void *getGameLibrary = dlsym(_handle2, "getGameLibrary");
	char *error2 = dlerror();
	if (error2 != NULL) {
		std::cerr << error2 << std::endl;
	}
	return getGameLibrary;
}

void DLLoader::closeGraphicalLib()
{
	dlclose(_handle);
}

void DLLoader::closeGameLib()
{
	dlclose(_handle2);
}

DLLoader::~DLLoader()
{
}
