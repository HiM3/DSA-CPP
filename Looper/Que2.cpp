#include <iostream>
using namespace std;
int main() {
	int number, count = 0;
	cout << "Enter a number: ";
	cin >> number;
	do {
		count++;
		number /= 10;
	} while (number != 0);
	cout << "Total number of digits: " << count << endl;
}
