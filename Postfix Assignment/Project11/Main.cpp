#include "LinkedStack.h"
#include <string>
#include <iostream>
using namespace std;
void main() {
	string examinePostfix;
	char ch;
	float value, result, operand1, operand2;
	LinkedStack <float> operandStack;

	cout << "Please enter a postfix expression to be evaluated: ";
	cin >> examinePostfix;

	for (int i = 0; i < examinePostfix.length(); i++) {
		ch = examinePostfix[i];
		if (ch >= '0' && ch <= '9') { // checks for a digit
			value = ch - '0';   // convert the char to an int
			operandStack.push(value); //pushes the value onto the stack
		}
		else { // evaluates and pushes the result
			operand2 = operandStack.peek();
			operandStack.pop();
			operand1 = operandStack.peek();
			operandStack.pop();

			if (ch == '*')
				result = operand1 * operand2;
			else if (ch == '/')
				result = operand1 / operand2;
			else if (ch == '+')
				result = operand1 + operand2;
			else if (ch == '-')
				result = operand1 - operand2;

			operandStack.push(result);
		}
	}

	while (!operandStack.isEmpty()) { // displays result
		cout << "Result: " << operandStack.peek() << endl;
		operandStack.pop();
	}

	system("PAUSE");
}