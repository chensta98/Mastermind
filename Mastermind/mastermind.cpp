/*
Alex Negulescu    negulescu.a@northeastern.edu
Ethan Chen        chen.eth@northeastern.edu
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
	//variable declarations
	int n, m, guesses = 0, guessCodeDigit, totalCorrect, totalIncorrect;
	vector<int> codeToGuess;
	vector<int> guessCode;

	//user input for range and length of code
	cout << "\nPlease enter the desired length of the secret code: ";
	cin >> n;
	cout << "\nPlease enter the range for each secret digit: ";
	cin >> m;

	//creating object secretCode of Code class
	Code secretCode = Code(n, m);
	//creates the secret code
	codeToGuess = secretCode.create();

	//print out per 1a instructions
	cout << "Secret Code: ";

	for (int j = 0; j < n; j++)
		cout << codeToGuess[j] << " ";

	while (guesses < 10)
	{
		//user enters guess code, one digit at a time. .push_back each digit
		cout << "\nPlease enter your guess code: " << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> guessCodeDigit;
			guessCode.push_back(guessCodeDigit);
		}

		//calls checkCorrect and checkIncorrect functions in class Code
		totalCorrect = secretCode.checkCorrect(guessCode);
		totalIncorrect = secretCode.checkIncorrect(guessCode);

		//print out result of guess
		cout << totalCorrect << ", " << totalIncorrect;

		//check if there is user win, break if so
		if (totalCorrect == n) {
			cout << "\nCongratulations, you guessed the correct code!\n";
			break;
		}
		//increment guesses
		guesses++;
		//clear previous guess vector
		guessCode.clear();
	}

	return 0;
}
