// OOPCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

int main()
{
	//
	Calculator calculator;
	string expression("");

	//
	cout << "Calculator\n"
		<< "______________________________\n\n"
		<< "Available operations: addition \"+\", subtraction \"-\", multiplication \"*\", division \"/\", brackets \"()\"\n\n"
		<< "Write your expression: (Ctrl + Z to exit)\n";

	while (getline(cin, expression))
	{
		try
		{
			cout << "\nResult: " << calculator.calculate(expression) << "\n\n"
				<< "Write your expression:\n";
		}
		catch (const exception& e)
		{
			cerr << "Error: " << e.what() << "\n\n";
			cout << "Write your expression:\n";
		}
	}

	return 0;
}
