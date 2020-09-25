/*
Alex Negulescu    negulescu.a@northeastern.edu
Ethan Chen        chen.eth@northeastern.edu
Project 1a
Mastermind game
This file contains the class Code, which is used to create the secretCode,
check totally correct digits, and check partially correct digits.
The file utilizes copy vectors to make already checked values "inaccessible".
File is passed the user guess, size of desired code, and range of digits.
Returns the secretCode and number of correct and incorrect digits to main file.
*/

#ifndef CODE_H
#define CODE_H

#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

// Declaration

class Code
{
private:
	int size, range;
	vector<int> secretCode, secretCopy;
	vector<int> guessCopy;

public:
	// Constructor
	Code(int n, int m)
	{
		size = n;
		range = m;
	}

	// Public Member Functions
	vector<int> create();
	int checkCorrect(vector<int> guess);
	int checkIncorrect(vector<int> guess);

};

// Implementation
//Returns randomCode of size = n with digits within the range m. 
//No params as it can access all through class private members
vector<int> Code::create()
{
	srand(time(NULL));
	int randomDigit;
	for (int i = 0; i < size; i++)
	{
		randomDigit = rand() % range;
		secretCode.push_back(randomDigit);
	}
	return secretCode;
}

//Returns number of totally correct digits (same number, same location)
//Also creates the secretCode and guessCode copies used in both check functions
int Code::checkCorrect(vector<int> guess)
{
	//create copy codes and set number of correct digits to 0 every time called
	secretCopy = secretCode;
	guessCopy = guess;
	int correct = 0;

	//loop through the size of the vectors and check if any location matches
	for (int x = 0; x < guessCopy.size(); x++)
	{
		if (guessCopy[x] == secretCopy[x])
		{
			correct++;
			//in order to not count twice, digit correct in guessCopy is
			//altered to range + 1 and secretCopy digit altered to 
			//range + 2. Makes it impossible to count more than once.
			guessCopy[x] = range + 1;
			secretCopy[x] = range + 2;
		}
	}
	return correct;
}

//returns the number of correct digits in incorrect location
//uses guessCopy and secretCopy created in previous function
//these vectors will contain the altered digits (if any were totally correct)
int Code::checkIncorrect(vector<int> guess)
{
	//set correct back to 0
	int correct = 0;

	//loops iterate through entire guessCopy, testing against one secretCopy
	//digit at a time
	for (int x = 0; x < guessCopy.size(); x++)
	{
		for (int y = 0; y < secretCopy.size(); y++)
		{
			//this would be a totallyCorrect case
			if (guessCopy[x] == secretCopy[y] && x == y)
			{
				break;
			}
			//Ensures location is not the same and checks if the values match
			else if (guessCopy[x] == secretCopy[y] && x != y)
			{
				//increment correct
				correct++;
				//as stated in previous function, this makes the counted digits
				//inaccessible
				guessCopy[x] = range + 1;
				secretCopy[y] = range + 2;
				break;
			}
		}
	}
	return correct;
}

#endif
