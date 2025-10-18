#include <stdio.h>
int main() {
    int num = 123, sum = 0;
    while(num > 0) {
        sum += num % 10;
        num /= 10;
    }
    printf("Sum: %d", sum); // Sum: 6
    return 0;
}
