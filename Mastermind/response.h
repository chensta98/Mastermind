/*
Alex Negulescu    negulescu.a@northeastern.edu
Ethan Chen        chen.eth@northeastern.edu
Project 1b
Mastermind game
This file contains the response class which holds the checkCorrect
and check incorrect data members and generates a response for the user.
*/

#ifndef RESPONSE_H
#define RESPONSE_H

#include <string>
#include <iostream>
using namespace std;

class response
{
private:
	int correct; // Number of correct values in the correct spot
	int incorrect; // Number of correct values in the incorrect spot

public:

	// Consturctor takes in the correct and incorrect values and stores them
	response(int c, int i)
	{
		correct = c;
		incorrect = i;
	}

	// Set and get functions for correct
	void setCorrect(int c)
	{
		correct = c;
	}
	int getCorrect()
	{
		return correct;
	}

	// Set and get functions for incorrect
	void setIncorrect(int i)
	{
		incorrect = i;
	}
	int getIncorrect()
	{
		return incorrect;
	}

	// Check if two response opjects are equal with operator overloading
	friend bool operator==(response& r1, response& r2);

	// Overload << operator to print response
	friend ostream& operator<<(ostream& os, const response& r);

};

bool operator==(response& r1, response& r2)
{
	if (r1.correct == r2.correct && r1.incorrect == r2.incorrect)
	{
		return true;
	}
	else
	{
		return false;
	}
}

ostream& operator<<(ostream& os, const response& r)
{
	os << "Correct values in correct position: " << r.correct << endl;
	os << "Correct values in incorrect position: " << r.incorrect << endl;

	return os;
}


#endif