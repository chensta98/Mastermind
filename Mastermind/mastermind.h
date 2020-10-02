#ifndef MASTERMIND_H
#define MASTERMIND_H

#include "code.h"
#include "response.h"
#include <iostream>
#include <vector>
using namespace std;

class mastermind 
{
private:
	vector<int> codeToGuess;
	vector<int> guessCode;
	int guesses = 0, guessCodeDigit, range, size, totalCorrect, totalIncorrect;
	bool solved;
	
public:
	mastermind(int m, int n)
	{
		range = m;
		size = n;
	}

	mastermind()
	{
		range = 10;
		size = 5;
	}

	Code secretCode = Code(size, range);
	response codeResponse;
	void printCode();
	vector<int> humanGuess();
	response getResponse(vector<int> guessCode);
	bool isSolved(int correct);
	void playGame();

};

void mastermind::printCode()
{
	codeToGuess = secretCode.create();

	cout << "Secret Code: ";

	for (int j = 0; j < size; j++)
		cout << codeToGuess[j] << " ";

	cout << endl;
}

vector<int> mastermind::humanGuess()
{
	cout << "\nPlease enter your guess code: " << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> guessCodeDigit;
		guessCode.push_back(guessCodeDigit);
	}

	return guessCode;
}

response mastermind::getResponse(vector<int> guessCode)
{
	totalCorrect = secretCode.checkCorrect(guessCode);
	totalIncorrect = secretCode.checkIncorrect(guessCode);
	codeResponse.setCorrect(totalCorrect);
	codeResponse.setIncorrect(totalIncorrect);
	return codeResponse;
}

bool mastermind::isSolved(int correct)
{
	if (correct == size)
		return true;
	else
		return false;
}

void mastermind::playGame()
{

	solved = false;
	printCode();

	while (guesses < 10 && solved == false)
	{
		guessCode = humanGuess();

		getResponse(guessCode);

		totalCorrect = codeResponse.getCorrect();

		solved = isSolved(totalCorrect);

		cout << codeResponse;

		guesses++;
	}



}

#endif
