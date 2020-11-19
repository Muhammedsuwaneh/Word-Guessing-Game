# C++ Object Oriented Programming Word guessing game implementation

1.This is a word guessing game
2.A five lettered word is requested from the player as a guess
3. A random "secret word" (with no repeated letters) gets returned and compared with the player's input
4. If the words are equal the player wins else the number of similar letters gets counted and printed
5. If the word is also not found in the dictionary, the player gets a message
6. The user can enter a hint code "xxxxx" and the secret word gets displayed
7. If the player enters the same word it is counted as a cheat and the program in the end states that the player has cheated
8. In the end the program indicates how many times the user tried before getting the word
9. The program is object-oriented and reads a list of 2046 words from a words.txt file using a vector string and FILE/IO operations
