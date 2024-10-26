#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

bool testNumber(const int num) {
    int originalNum, remainder, n = 0, result = 0;

    originalNum = num;
    // Count the number of digits
    while (originalNum != 0) {
        originalNum /= 10;
        ++n;
    }

    originalNum = num;

    // Calculate the sum of digits raised to the power of the number of digits
    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += pow(remainder, n);
        originalNum /= 10;
    }
    return result == num;
}

int main() {
    printf("Computing armstrong from %d to %d\n",1,INT_MAX);
    for (int num = 1; num < INT_MAX; num++)
    {
        if (testNumber(num))
            printf("%d is an Armstrong number.\n", num);
        //else
         //   printf("%d is not an Armstrong number.\n", num);
    }

    return 0;
}

