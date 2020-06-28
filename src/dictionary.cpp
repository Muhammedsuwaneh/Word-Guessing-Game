#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "dictionary.h"
#include <fstream>
#include <set>
#include <time.h>

using namespace std;

WordList::WordList() {

	filename = new char[15];

} // end constructor


WordList::WordList(char* file) {

	filename = new char[strlen(file) + 1];
	strcpy_s(filename, strlen(file) + 1, file);

	std::fstream dictionary;

	dictionary.open(file, ios::in);

	if (!dictionary) {

		cout << endl << " -> Error ! -> File did not opened" << endl;
		exit(0);
	}

	cout << endl << " -> File opened ....................." << endl;
	cout << endl << " -> Now reading from file....................." << endl;

	std::string buffer;
	bool decision;

	dictionary >> buffer;

	while (!dictionary.eof()) {

		decision = test_Secret_Word(buffer);

		if (decision == true) {

			secret_words.push_back(buffer);
		}

		words.insert(buffer);

		dictionary >> buffer;
	}
	
	cout << endl << "Reading was successfull" << endl;

	temp.assign(words.begin(), words.end());


} // end constructor



bool WordList::test_Secret_Word(string buffer) {

	int i, j, count = 0;

	for (i = 0; i < buffer.size(); i++) {

		for (j = 0; j < i; j++) {

			if (buffer[i] == buffer[j]) {

				count++;
			}
		}
	}

	if (count != 0) {

		return false;
	}

	else {

		return true;
	}
}


WordList::~WordList() {

	delete[]filename;

} // end destructor

bool WordList::check_Word_Validity(string buffer) {

	int i, len_1 = buffer.length(), flag = 0;

	for (i = 0; i < temp.size(); i++) {

		if (len_1 == temp[i].length()) {

			transform(buffer.begin(), buffer.end(), buffer.begin(), ::tolower);

			if (buffer == temp[i]) {

				flag = 1;
				break;
			}
		}
	}

	if (flag != 0) {

		return true;
	}

	else {

		return false;
	}

} // end check_word_validity

string WordList::get_Secret_Word() {

	int index;
	string secret;
	int upper = secret_words.size(), lower = 0;

	index = (rand() % (upper - lower + 1)) + lower;

	return secret_words[index];

} // end get_Secret_Word



