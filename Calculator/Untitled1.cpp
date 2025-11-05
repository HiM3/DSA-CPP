#include <iostream>
using namespace std;
int main() {
	int num1, num2, result;
	char choice;
	do {

		cout << "\nPress 1 for Addition (+)" << endl;
		cout << "Press 2 for Subtraction (-)" << endl;
		cout << "Press 3 for Multiplication (*)" << endl;
		cout << "Press 4 for Division (/)" << endl;
		cout << "Press 5 for Modulus (%)" << endl;
		cout << "Press 0 for the exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case '1':
				cout << "Enter the first number: ";
				cin >> num1;
				cout << "Enter the second number: ";
				cin >> num2;
				result = num1 + num2;
				cout << "Addition of " << num1 << " and " << num2 << " is " << result << endl;
				break;
			case '2':
				cout << "Enter the first number: ";
				cin >> num1;
				cout << "Enter the second number: ";
				cin >> num2;
				result = num1 - num2;
				cout << "Subtraction of " << num1 << " and " << num2 << " is " << result << endl;
				break;
			case '3':
				cout << "Enter the first number: ";
				cin >> num1;
				cout << "Enter the second number: ";
				cin >> num2;
				result = num1 * num2;
				cout << "Multiplication of " << num1 << " and " << num2 << " is " << result << endl;
				break;
			case '4':
				cout << "Enter the first number: ";
				cin >> num1;
				cout << "Enter the second number: ";
				cin >> num2;
				if (num2 != 0)
					result = num1 / num2;
				else
					cout << "Error! Division by zero." << endl;
				cout << "Division of " << num1 << " and " << num2 << " is " << result << endl;
				break;
			case '5':
				cout << "Enter the first number: ";
				cin >> num1;
				cout << "Enter the second number: ";
				cin >> num2;
				if (num2 != 0)
					result = num1 % num2;
				else
					cout << "Error! Modulus by zero." << endl;
				cout << "Modulus of " << num1 << " and " << num2 << " is " << result << endl;
				break;
			case '0':
				cout << "Exiting the program..." << endl;
				break;
			default:
				cout << "Invalid choice! Please enter a valid option." << endl;
				break;
		}

	} while (choice != '0');


}
