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
		vector<int> secretCode;

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

int Code::checkCorrect(vector<int> guess)
{
	int correct = 0;
	for (int x = 0; x < guess.size(); x++)
	{
		if (guess[x] == secretCode[x])
		{
			correct++;
		}
	}
	return correct;
}


int Code::checkIncorrect(vector<int> guess) 
{
	int correct = 0;

	for (int x = 0; x < guess.size(); x++)
	{
		for (int y = 0; y < secretCode.size(); y++)
		{
			if (guess[x] == secretCode[y] && x == y)
			{
				break;
			}
			else if (guess[x] == secretCode[y] && x != y)
			{
				correct++;
				break;
			}
		}
	}

	return correct;
}

#endif
