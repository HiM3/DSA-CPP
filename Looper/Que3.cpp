#include <iostream>
using namespace std;
int main() {
    int num, first, last,sum;
    cout << "Enter a number: ";
    cin >> num;
    last = num % 10;
    while (num >= 10) {
        num /= 10;
    }
    first = num;
    sum = first + last;
    cout << "The sum of the first and last digits is: " << sum << endl;
}
