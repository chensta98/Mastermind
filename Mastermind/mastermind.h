/*
Alex Negulescu    negulescu.a@northeastern.edu
Ethan Chen        chen.eth@northeastern.edu
Project 1b
Mastermind game
This file contains the mastermind class which contains the code for the game.
File creates code object and prints code using the code.h header file.
File also reads and creates the player guess code.
In addition, file includes response.h file in order to check this guess
against the secret code created in code.h.
isSolved() checks to see if player has all correct digits and returns true
to break the iteration in playGame(). 
playGame() utilizes the member functions of this class to run the entire game.
*/

#ifndef MASTERMIND_H
#define MASTERMIND_H

#include "code.h"
#include "response.h"
#include <iostream>
#include <vector>
using namespace std;

//class declaration
class mastermind 
{
private:
	vector<int> codeToGuess; //secretCode vector
	vector<int> guessCode; //humanGuess vector
	int guesses = 0, guessCodeDigit = 0, range, size;
	int totalCorrect = 0, totalIncorrect = 0;
	bool solved = false; //used in isSolved to declare if game won or not
	
public:
	//constructor that takes input n and m from main()
	mastermind(int n, int m)
	{
		size = n;
		range = m;
	}

	//constructor that takes no params and sets range and size to 10 and 5
	mastermind()
	{
		size = 5;
		range = 10;
	}

	//create code object
	Code secretCode;
	response codeResponse;
	void printCode();
	vector<int> humanGuess();
	response getResponse(vector<int> guessCode);
	bool isSolved(int correct);
	void playGame();

};

//function prints secret code
void mastermind::printCode()
{
	//calls create() function from code class
	Code secretCode(size, range);
	codeToGuess = secretCode.create();

	cout << "Secret Code: ";

	for (int j = 0; j < size; j++)
		cout << codeToGuess[j] << " ";

	cout << endl;
}

//function reads in the users guess and creates a guess code
vector<int> mastermind::humanGuess()
{
	cout << "\nPlease enter your guess code: " << endl;
	for (int i = 0; i < size; i++)
	{
		//pushes each input digit to back of guessCode vector
		cin >> guessCodeDigit;
		guessCode.push_back(guessCodeDigit);
	}

	return guessCode;
}

//function utilizes response class and code class to find number of 
//correct and incorrect digits
response mastermind::getResponse(vector<int> guessCode)
{
	//uses functions in code.h
	totalCorrect = secretCode.checkCorrect(guessCode);
	totalIncorrect = secretCode.checkIncorrect(guessCode);

	//uses functions in response.h
	response codeResponse(totalCorrect, totalIncorrect);

	//returns codeResponse to be used for isSolved and printout in playGame
	return codeResponse;
}

//bool function returns true or false depending on if # of correct is equal
//to the total number of digits in the code
bool mastermind::isSolved(int correct)
{
	if (correct == size)
	{
		cout << "\nCongratulations, you cracked the code!\n";
		return true; //true if so
	}
	else
		return false; //false if not
}

//function utilizes all member functions created above to run the game
void mastermind::playGame()
{
	//sets solved to false to begin
	solved = false;
	//prints code before game is run
	printCode();

	//if number of guesses is less than 10 and game not solved, iterate
	while (guesses < 10 && solved == false)
	{
		guessCode = humanGuess(); //get humanGuess

		getResponse(guessCode); //get response to humanGuess

		totalCorrect = codeResponse.getCorrect(); //set number of correct digits

		solved = isSolved(totalCorrect); //check if solved

		cout << codeResponse; //print response

		guesses++; //increment guesses
	}

	if (guesses == 10)
		cout << "\nBetter luck next time!\n";

}

#endif
