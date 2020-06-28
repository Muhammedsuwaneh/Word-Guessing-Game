#pragma once

#ifndef WORDS_H
#define WORDS_H

#include "dictionary.h"

class Words {

private:

	// counts matched letters in any order
	int count_Matched_Letters(std::string);
	int count_Correct_Placed_Letters(std::string);
	int num_of_Guesses;
	bool cheated;
	string secret;
	char* file;
	string guess;

public:

	Words();
	~Words();

	void initializeGame(Words&);
};

#endif // !DICTIONARY_H;
