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
#include<stdio.h>
#include<ctype.h>
#include<algorithm>

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
		void addToLettersGuessed(char newLetter);
		bool isAlreadyGuessed(char charIn);
		void displayLettersGuessed();
		bool equals(string str, char ch);

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
		void setGuessChar(char newChar);
		char getGuessChar();
		void setGameWon(bool newGameWon);
		bool getGameWon();
		vector<char> getLettersGuessed();
		void setGuessedCorrectly(bool correct);
		bool getGuessedCorrectly();

	private:
		vector<string> dictionary;
		int dictionarySize;
		string chosenWord;
		string dashWord;
		int guessesLeft;
		char guessChar;
		bool gameWon;
		vector<char> lettersGuessed;
		bool guessedCorrectly;
};

#endif /* HANGMANGAME_H_ */
