/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Main
*/

#include "Core.hpp"

void displayHelp(void)
{
	std::cout << "Welcome to arcade !" << std::endl;
	std::cout << "You can use arrows to navigate in menu and enter to select." << std::endl;
	std::cout << "You can quit with the cross or alt+f4." << std::endl;
	std::cout << "In menu, you can press brackspace to back to previous menus." << std::endl;
	std::cout << "In game, you can change game by pressing n (for next) or p (for previous)." << std::endl;
	std::cout << "In game, you can change of libs by pressing m (for previous) or l (for next)." << std::endl;
	std::cout << "You can see your score in the main menu." << std::endl;
}

int main (int ac, char **av, char **env)
{
	try
	{
		if (env[0] == NULL)
			return (84);
		if (ac != 2) {
			std::cout << "Usage: ./arcade [graphic_library]" << std::endl;
			return (84);
		}
	std::string string = std::string(av[1]);
	if (string == "-h") {
		displayHelp();
		return (0);
	}
	arcade::Core core = arcade::Core(string);
	if (core.run() == 84)
		return (84);
	}
	catch (std::exception except) {
		std::cout << "Error" << std::endl;
	}
	return (0);
}