#pragma once
class Calculator
{
private:
	Stack<double> valuesStack;
	Stack<char> operatorsStack;

	void performOperation(char);
public:
	~Calculator();
	double calculate(const string&);
};

