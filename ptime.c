#include<stdio.h>
#include<time.h>

int main()
{
    time_t t;   // not a primitive datatype
    time(&t);

    printf("This program has been run at (date and time): %s", ctime(&t));
    return 0;
}
