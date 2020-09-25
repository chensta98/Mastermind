/*
Alex Negulescu Ethan Chen
Project 1a
Mastermind game
Code will ask user to enter information for code length (n) and range of
digits (m)
Codemaker creates code of random sequence of n digits within the range [0,m-1]
User then guesses n-digit sequence
Codemaker responds with number of correct digits in correct location along with
number of correct digits in incorrect location (exclusively)
i.e. a correct digit in correct location is counted separate from correct digit
User recieves 10 guesses, if solution found by then (win), if not (lose)
*/

#include "code.h"
#include <iostream>
#include <stdlib.h>
#include <vector>


using namespace std;

int main() {
	int n, m, guesses = 0, guessCodeDigit, totalCorrect, totalIncorrect;
	vector<int> codeToGuess;
	vector<int> guessCode;

	cout << "\nPlease enter the desired length of the secret code: ";
	cin >> n;
	cout << "\nPlease enter the range for each secret digit: ";
	cin >> m;

	Code secretCode = Code(n, m);
	codeToGuess = secretCode.create();

	cout << "Secret Code: ";

	for (int j = 0; j < n; j++)
		cout << codeToGuess[j] << " ";

	while (guesses < 10) 
	{
		
		cout << "\nPlease enter your guess code: " << endl;
		for (int i = 0; i < n; i++) 
		{
			cin >> guessCodeDigit;
			guessCode.push_back(guessCodeDigit);
		}

		totalCorrect = secretCode.checkCorrect(guessCode);
		totalIncorrect = secretCode.checkIncorrect(guessCode);

		cout << totalCorrect << ", " << totalIncorrect;

		guesses++;
		guessCode.clear();
	}

	return 0;
}