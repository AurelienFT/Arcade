/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** ScoreSolarFox
*/

#ifndef SCORESOLARFOX_HPP_
    #define SCORESOLARFOX_HPP_

    #include "../../Score.hpp"

class ScoreSolarFox : public Score {
	public:
		ScoreSolarFox();
		~ScoreSolarFox();

		void saveScore(int score, const char *name, char *file);

	protected:
	private:
		void newValue();

		std::string _name;
		int _score = 0;
};

#endif /* !SCORESOLARFOX_HPP_ */
