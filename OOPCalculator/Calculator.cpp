#include "pch.h"
#include "Calculator.h"

void Calculator::performOperation(char operation)
{
	double operand2 = valuesStack.pop();
	double operand1 = valuesStack.pop();

	switch (operation)
	{
	case '+':
		valuesStack.push(operand1 + operand2);
		break;
	case '-':
		valuesStack.push(operand1 - operand2);
		break;
	case '*':
		valuesStack.push(operand1 * operand2);
		break;
	case '/':
		if (operand2 == 0)
			throw new exception("Division by zero");
		valuesStack.push(operand1 / operand2);
		break;
	default:
		throw new exception("Invalid operation");
	}
}

Calculator::~Calculator() { }

double Calculator::calculate(const string& expression)
{
	istringstream iss(expression);
	char token;
	double value;

	// Using istringstream to read expression and put symbol into corresponding stack
	while (iss >> token)
	{
		if (isdigit(token))
		{
			iss.putback(token);
			iss >> value;
			valuesStack.push(value);
		}
		else if (token == '+' || token == '-')
		{
			while (!operatorsStack.isEmpty() && (operatorsStack.peek() == '+' || operatorsStack.peek() == '-'))
				performOperation(operatorsStack.pop());
			operatorsStack.push(token);
		}
		else if (token == '*' || token == '/')
		{
			while (!operatorsStack.isEmpty() && (operatorsStack.peek() == '*' || operatorsStack.peek() == '/'))
				performOperation(operatorsStack.pop());
			operatorsStack.push(token);
		}
		else if (token == '(')
			operatorsStack.push(token);
		else if (token == ')')
		{
			while (!operatorsStack.isEmpty() && operatorsStack.peek() != '(')
				performOperation(operatorsStack.pop());
			operatorsStack.pop();
		}
	}

	// Performing leftover operations in priority queue
	while (!operatorsStack.isEmpty())
	{
		if (valuesStack.isEmpty())
			throw new exception("Invalid expression");
		performOperation(operatorsStack.pop());
	}

	// Result must remain on top of values stack
	if (valuesStack.isEmpty() || !operatorsStack.isEmpty())
		throw new exception("Invalid expression");

	return valuesStack.pop();
}
