#include <stdio.h>
void counter(int number, int digit, int *times) {
    *times = 0;
    while(number != 0) {
        if(digit == number%10) {
            (*times)++;
        }
        number /= 10;
    }
}
int main() {
    int number, digit, times;
    printf("Insert a number: ");
    scanf("%d", &number);
    printf("Insert a digit: ");
    scanf("%d", &digit);
    counter(number, digit, &times);
    printf("The digit %d appears %d times on number %d\n", digit, times, number);
}