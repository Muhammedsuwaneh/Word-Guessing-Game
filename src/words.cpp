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
	string ipucu_kodu = "xxxxx";

	cout << " -> Birbakalim oyununa hos geldiniz" << endl;
	cout << " -> 5 harften olusan bir kelime tuttum" << endl;

	cout << endl << " Sozluk acmak icin dosyanin ismi yazininiz (words.txt): ";
	cin >> W.file;

    WordList L(W.file);

	W.secret = L.get_Secret_Word();

	W.cheated == false;

	do {

		cout << endl << " -> Tahminiz nedir ? : ";
		cin >> W.guess;

		transform(W.guess.begin(), W.guess.end(), W.guess.begin(), ::tolower);

		validity = L.check_Word_Validity(W.guess);

		if (validity == false && W.guess != ipucu_kodu) {

			cout << " -> Bu kelime sozlukte yok" << endl;
		}

		else {

			if (W.guess == ipucu_kodu) {

				cout << " -> Gizli kelime: " << W.secret << endl;
				W.cheated = true;

				num_of_Guesses++;
			}

			else if (W.guess == W.secret && W.cheated == false) {

				cout << " -> Bildiniz ! " << num_of_Guesses << " dogru sonucuna ulastiniz" << endl;
				break;
			}

			else if (W.guess == W.secret && W.cheated == true) {

				cout << " -> Bildiniz ! " << num_of_Guesses << " dogru sonucuna ipcucu kullanarak ulastiniz" << endl;
				break;
			}

			else if (W.guess != ipucu_kodu) {

				matched_Count = count_Matched_Letters(W.secret);
				correctly_Placed = count_Correct_Placed_Letters(W.secret);
				cout << endl << " ----------------------------- " << endl;
				cout << endl << " -> Eslesen harf sayisi: " << matched_Count << endl;
				cout << endl << " -> Eslesen harflerin dogru konumu: " << correctly_Placed << endl;
			}

			num_of_Guesses++;
		}

	} while (1);


	/* ipucu ends here */

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