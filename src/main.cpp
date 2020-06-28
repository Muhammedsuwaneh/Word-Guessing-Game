#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <string>
#include <fstream>
#include "words.h"
#include <time.h>

using namespace std;

int main() {

	srand(time(NULL));
    
	Words W;

	W.initializeGame(W);

	cout << endl << endl;
	return 0;
	system("pause");
}

	
