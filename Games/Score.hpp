/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Score
*/

#ifndef SCORE_HPP_
    #define SCORE_HPP_

    #include <vector>
    #include <string>

class Score {
	public:
		Score();
		~Score();

		void saveScore(int score, const char *name, char *file);

	protected:
		void writeInFile();
		void getFromFile();
		void setScores();
		std::vector<std::string> _scores;
		std::vector<std::string> _names;
		std::vector<int> _values;
		
		std::string _file;
	private:
		void getValues();
		void getNames();
		void readFile();
};

#endif /* !SCORE_HPP_ */
