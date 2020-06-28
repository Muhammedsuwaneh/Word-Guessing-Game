#include <iostream>
#include <cstdlib>
#include "words.h"
#include <algorithm>

Words::Words() {

	file = new char[15];
	num_of_Guesses = 0;
}

void Words::initializeGame(Words& W) {

	bool validity;
	int matched_Count, correctly_Placed;
	string hint_code = "xxxxx";

	cout << " -> Welcome to the guessing game" << endl;

	cout << endl << " To start the game enter the file name in the brackets (words.txt): ";
	cin >> W.file;

    WordList L(W.file);

	W.secret = L.get_Secret_Word();

	W.cheated == false;

	do {

		cout << endl << " -> Enter a guess ? : ";
		cin >> W.guess;

		transform(W.guess.begin(), W.guess.end(), W.guess.begin(), ::tolower);

		validity = L.check_Word_Validity(W.guess);

		if (validity == false && W.guess != ipucu_kodu) {

			cout << " -> Word not found in dictionary" << endl;
		}

		else {

			if (W.guess == hint_code) {

				cout << " -> Secret word: " << W.secret << endl;
				W.cheated = true;

				num_of_Guesses++;
			}

			else if (W.guess == W.secret && W.cheated == false) {

				cout << " -> Game concluded ! After" << num_of_Guesses << " guesses the guess became correct" << endl;
				break;
			}

			else if (W.guess == W.secret && W.cheated == true) {

				cout << " -> Game concluded ! After " << num_of_Guesses << " guesses the guess became correct by using the hint code" << endl;
				break;
			}

			else if (W.guess != hint_code) {

				matched_Count = count_Matched_Letters(W.secret);
				correctly_Placed = count_Correct_Placed_Letters(W.secret);
				cout << endl << " ----------------------------- " << endl;
				cout << endl << " -> Number of similar letters: " << matched_Count << endl;
				cout << endl << " -> Number of well placed similar letters: " << correctly_Placed << endl;
			}

			num_of_Guesses++;
		}

	} while (1);


	/* hint ends here */

}  // end initializeGame

int Words::count_Matched_Letters(std::string secret) {

	int i, j, count = 0;

	for (i = 0; i < secret.length(); i++) {

		for (j = 0; j < guess.length(); j++) {

			if (guess[j] == secret[i]) {

				count++;
			}
		}
	}

	return count;

} // end count_Matched_Letters

int Words::count_Correct_Placed_Letters(std::string secret) {

	int i, j, count = 0;

	for (i = 0; i < secret.length(); i++) {

		for (j = 0; j < guess.length(); j++) {

			if (guess[j] == secret[i]) {

				if (j == i) {

					count++;
				}
			}
		}
	}

	return count;

} // end count_Correct_Placed_Letters

Words::~Words() {

	delete[]file;
}
