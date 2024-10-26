#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <locale.h>

// TODO 
// 1) switch from long to unsigned long
// 2) add timer to show how long it took to reach each armstrong number

bool testNumber(const long num) {
    long originalNum, remainder, n = 0, result = 0;

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
    // comma separators for thousands
    setlocale(LC_NUMERIC, "");
    // don't buffer output
    setbuf(stdout, NULL); 
    printf("Computing armstrong from %d to %'ld\n",1,LONG_MAX);
    for (long num = 1; num < LONG_MAX; num++)
    {
        if (testNumber(num))
            printf("%'ld is an Armstrong number.\n", num);
    }

    return 0;
}

