#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <locale.h>

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
    printf("Computing armstrong from %d to %'lu\n",1,ULONG_MAX);

    // initialize start and last output time
    struct timespec startTime, lastTime;
    clock_gettime(CLOCK_MONOTONIC, &startTime);
    lastTime = startTime;

    for (long  num = 1; num < ULONG_MAX; num++)
    {
        if (testNumber(num)) {
            struct timespec foundTime;
            clock_gettime(CLOCK_MONOTONIC, &foundTime);

            printf("%'ld is an Armstrong number. Elapsed Time %'lu.%09lu, DeltaTime %'lu.%09lu\n", num,
                foundTime.tv_sec - startTime.tv_sec, foundTime.tv_nsec - startTime.tv_nsec,
                foundTime.tv_sec - lastTime.tv_sec, foundTime.tv_nsec - lastTime.tv_nsec);

            lastTime = foundTime;
        }
    }

    return 0;
}

