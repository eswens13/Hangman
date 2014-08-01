/*
 * HangmanGame.h
 *
 *  Created on: Jul 30, 2014
 *      Author: eswens13
 */

#ifndef HANGMANGAME_H_
#define HANGMANGAME_H_

#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<sstream>

using namespace std;

class HangmanGame {

	public:
		HangmanGame();
		virtual ~HangmanGame();

		void initializeDictionary(string infileName);
		string chooseRandomWord();
		void playGame();
		void startGame();
		void takeTurn();
		void makeGuess();
		void updateDashWord();
		void checkForWin();
		void displayWinningMessage();
		void displayLosingMessage();
		//bool equals(string str, char ch);

		// -------------------------- GETTERS & SETTERS ---------------------------

		vector<string> getDictionary();
		void setDictionarySize(int newSize);
		int getDictionarySize();
		void setChosenWord(string newWord);
		string getChosenWord();
		void setDashWord();
		string getDashWord();
		void setGuessesLeft(int newNum);
		int getGuessesLeft();
		void setGuessChar(string newChar);
		string getGuessChar();
		void setGameWon(bool newGameWon);
		bool getGameWon();

	private:
		vector<string> dictionary;
		int dictionarySize;
		string chosenWord;
		string dashWord;
		int guessesLeft;
		string guessChar;
		bool gameWon;

};

#endif /* HANGMANGAME_H_ */
