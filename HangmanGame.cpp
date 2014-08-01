/*
 * HangmanGame.cpp
 *
 *  Created on: Jul 30, 2014
 *      Author: eswens13
 */

#include "HangmanGame.h"

// -------------------------------- CONSTRUCTOR AND DESTRUCTOR ------------------------------------

HangmanGame::HangmanGame() {
	this->initializeDictionary("bigDictionary.txt");
	this->setChosenWord("");
	this->setGuessesLeft(10);
	this->setGameWon(false);
}

HangmanGame::~HangmanGame() {}

// ------------------------------------- MEMBER FUNCTIONS -----------------------------------------

void HangmanGame::initializeDictionary(string infileName) {
	ifstream infile;
	infile.open(infileName);

	string word("");
	while(infile >> word) {
		this->dictionary.push_back(word);
		word.clear();
	}

	infile.close();
	this->setDictionarySize(this->getDictionary().size());
}

string HangmanGame::chooseRandomWord() {
	int r = rand() % this->getDictionarySize();
	return this->getDictionary()[r];
}

void HangmanGame::playGame() {
	this->startGame();

	while(this->getGuessesLeft() > 0) {
		this->takeTurn();
		if(this->getGameWon()) {
			this->displayWinningMessage();
			break;
		}
	}

	if(!this->getGameWon()) {
		this->displayLosingMessage();
	}
	return;
}

void HangmanGame::startGame() {
	this->setChosenWord(this->chooseRandomWord());
	//cout << "The word is: " << this->getChosenWord() << endl << endl;
	this->setDashWord();
	this->setGuessesLeft(10);

	cout << endl;
	cout << "****************************** WELCOME TO HANGMAN! ******************************" << endl;
	cout << endl;
	cout << "\t- You have 10 guesses. Only 10!!" << endl;
	cout << endl;
	cout << "\t- Good Luck!" << endl;
	cout << endl;
}

void HangmanGame::takeTurn() {
	cout << "You have " << this->getGuessesLeft() << " guesses left." << endl << endl;
	cout << "\t\t" << this->getDashWord() << endl << endl;

	this->makeGuess();

	this->setGuessesLeft(this->getGuessesLeft() - 1);

	this->checkForWin();
}

void HangmanGame::makeGuess() {
	// Still need to bulletproof this.  Change each char to lowercase and only allow alpha chars.
	cout << "Your guess:\t";
	string charIn = "";
	cin >> charIn;

	cout << "You guessed: " << charIn << endl;
	this->setGuessChar(charIn);

	this->updateDashWord();
	cout << endl;

}

void HangmanGame::updateDashWord() {
	stringstream ss;
	ss.clear();

	for(int i = 0; i < this->getDashWord().length(); i++) {
		if(this->getChosenWord().substr(i, 1) == this->getGuessChar()) {
			ss << this->getGuessChar();
		}
		else {
			ss << this->getDashWord().substr(i, 1);
		}
	}

	this->dashWord = ss.str();
}

void HangmanGame::checkForWin() {
	for(int i = 0; i < this->getDashWord().length(); i++) {
		if(i < this->getDashWord().length()) {
			if(this->getDashWord().substr(i, 1) == "-") {
				this->setGameWon(false);
				return;
			}
		}
	}

	this->setGameWon(true);
	return;
}

void HangmanGame::displayWinningMessage() {
	cout << "******************** Congratulations!  You won! ********************" << endl << endl;;
	cout << "\tThe word was \'" << this->getChosenWord() << "\'" << endl << endl;
}

void HangmanGame::displayLosingMessage() {
	cout << endl << "~~~~~~~~~~~~~~~ Sorry, you lost ~~~~~~~~~~~~~~" << endl << endl;
	cout << "\tThe word was \'" << this->getChosenWord() << "\'" << endl << endl;
}

/*bool HangmanGame::equals(string str, string ch) {
	if(str.length() > 1) {
		return false;
	}

	stringstream ss;
	ss.clear();
	ss << ch;

	string newString = ss.str();

	if(newString == str) {
		return true;
	}
	else {
		return false;
	}
}*/

// ------------------------------------- GETTERS & SETTERS ----------------------------------------

vector<string> HangmanGame::getDictionary() {
	return this->dictionary;
}

void HangmanGame::setDictionarySize(int newSize) {
	this->dictionarySize = newSize;
}

int HangmanGame::getDictionarySize() {
	return this->dictionarySize;
}

void HangmanGame::setChosenWord(string newWord) {
	this->chosenWord = newWord;
}

string HangmanGame::getChosenWord() {
	return this->chosenWord;
}

void HangmanGame::setDashWord() {

	stringstream ss;
	ss.clear();

	for(int i = 0; i < this->getChosenWord().length(); i++) {
		ss << '-';
	}

	this->dashWord = ss.str();
}

string HangmanGame::getDashWord() {
	return this->dashWord;
}

void HangmanGame::setGuessesLeft(int newNum) {
	this->guessesLeft = newNum;
}

int HangmanGame::getGuessesLeft() {
	return this->guessesLeft;
}

void HangmanGame::setGuessChar(string newChar) {
	this->guessChar = newChar;
}

string HangmanGame::getGuessChar() {
	return this->guessChar;
}

void HangmanGame::setGameWon(bool newGameWon) {
	this->gameWon = newGameWon;
}

bool HangmanGame::getGameWon() {
	return this->gameWon;
}

// ------------------------------------------- MAIN -----------------------------------------------

int main() {
	srand(time(0));

	HangmanGame hg = HangmanGame();
	hg.playGame();

	return 0;
}









