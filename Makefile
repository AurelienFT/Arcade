##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##

all:
	mkdir -p build && cd build && cmake .. && make

core:
	mkdir -p build && cd build && cmake .. && make core

graphicals:
	mkdir -p build && cd build && cmake .. && make graphicals

games:
	mkdir -p build && cd build && cmake .. && make games

clean:
	mkdir -p build && cd build && rm -f CMakeCache.txt

fclean: clean
	rm -rf build
	rm -rf arcade
	rm -rf games
	rm -rf lib

re: fclean all

.PHONY: clean fclean re all games graphicals core
