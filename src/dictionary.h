#pragma once

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <vector>
#include <set>

using namespace std;

class WordList {

private:

	// test if word has only unique letters
	bool test_Secret_Word(string);

	set<string>words;
	vector<string>secret_words;
	char* filename;

public:
	
	WordList();
	WordList(char*);
	~WordList();
 
	//check if word is in Dictionary
	bool check_Word_Validity(string);

    //return a random word (without repeated letters)
    string get_Secret_Word();

	vector<string>temp;
};

#endif // !DICTIONARY_H

