/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** ScoreNibbler
*/

#ifndef SCORENIBBLER_HPP_
    #define SCORENIBBLER_HPP_

    #include "../../Score.hpp"

class ScoreNibbler : Score {
	public:
		ScoreNibbler();
		~ScoreNibbler();

		void saveScore(int score, const char *name, char *file);

	protected:
	private:
		void newValue();
		std::string _name;
		int _score = 0;
};

#endif /* !SCORENIBBLER_HPP_ */
