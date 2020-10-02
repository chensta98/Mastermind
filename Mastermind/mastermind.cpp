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
#include "response.h"
#include "mastermind.h"
#include <iostream>
#include <stdlib.h>
#include <vector>


using namespace std;

int main() {
	//variable declarations
	int n, m;

	//user input for range and length of code
	cout << "\nPlease enter the desired length of the secret code: ";
	cin >> n;
	cout << "\nPlease enter the range for each secret digit: ";
	cin >> m;

	//creating object secretCode of Code class
	mastermind codeBreaker = mastermind(n, m);

	codeBreaker.playGame();
	
	return 0;
}
