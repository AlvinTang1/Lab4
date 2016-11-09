/*
 * Game.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: Alvin
 */
#include "Game.hpp"
#include "BSTB.hpp"
#include "NodeTB.hpp"
#include <iostream>
#include <fstream>
#include <time.h>
#include <cstring>
#include <stdlib.h>
Game::Game() {
	wordlist = NULL;
	numright = 0;
	totalwords = 0;
	currletters = NULL;
	dict = NULL;
	numletters = 0;

}
void Game::readTreeFromFile(string dictfile){
	dict = new BSTB();
	ifstream file(dictfile.c_str()); // converts a string to a character array
	string word;
	while (!file.eof()){
		file>>word;
		if (!file.eof()){
			dict->insert(word);
		}
	}
	return;
}
Game::Game(string infile){
	 readTreeFromFile(infile);
}
char * Game::getLetters(int x){
srand(time(NULL));
char List[x];
for(int i=0; i<x; i++){
	int tmp = rand() %26;
	List[i] =  (char)(tmp+65);
   cout <<List[i]<<endl;
}
return List;
}
void Game::getWords(){
	int totalwords;
	BSTB *wordlist = new BSTB();
	cout << "How many words are you entering?" << endl;
	cin >> totalwords;

	for (int i=0; i<totalwords; i++){
		string userWord;
		cout << "Enter a word:" << endl;
		cin >> userWord;
		wordlist->insert(userWord);
	}

}
bool Game::checkWLetters(string s){
	Game *n = new Game();
	bool tmp=true;
 char *a = new char[s.size()+1];
 a[s.size()]=0;
 memcpy(a,s.c_str(),s.size());
for(int i=0; i<s.size();i++){
	for(int j=0; j<n->numletters;j++){
		if(a[i]!=n->currletters[j]){
			tmp = false;
		}
	}
}
return tmp;
}
void Game::checkWordsForScore(){
Game *n = new Game();
n->wordlist->getScore(dict);
}

