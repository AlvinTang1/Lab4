

#ifndef GAME_HPP_
#define GAME_HPP_
#include <string>
#include "BSTB.hpp"
#include "NodeTB.hpp"
using namespace std;
class Game {
	BSTB *dict; // the AVL tree
	int numletters; // the number of letters the user wants
	char *currletters; //the random set of letters
	int totalwords; // the count of the total number of words generated
	BSTB *wordlist; //The Binary Search tree for the word list – used because you
//want to make sure there are no duplicates in the word list typed in
	int numright; // the count of the number of words in the dict tree
public:
	Game();
	Game(string infile);
	void startGame();
	void readTreeFromFile(string dictfile); /* see below for this method*/
	char * getLetters(int x);
	void getWords();
	bool checkWLetters(string s);
	void checkWordsForScore();
};

#endif /* GAME_HPP_ */
