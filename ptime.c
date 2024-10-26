#include<stdio.h>
#include<time.h>
#include<unistd.h>

struct timespec getQuadTIme() {
    struct timespec quadTime;
    clock_gettime(CLOCK_MONOTONIC, &quadTime);
    return quadTime;
}

int quadtimer() {
    // Get the starting time
    struct timespec start;
    clock_gettime(CLOCK_MONOTONIC, &start);
    

    // Call the function you want to measure
    sleep(1); // do_some_work();

    // Get the ending time
    struct timespec end;
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calculate elapsed time in seconds and nanoseconds
    // double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    // printf("Elapsed time: %.9f seconds\n", elapsed_time);

    printf("Elapsed time: %lu.%09lu seconds\n", end.tv_sec - start.tv_sec,end.tv_nsec - start.tv_nsec);
    return 0;
}

int main()
{
    time_t t;   // not a primitive datatype
    time(&t);

    printf("This program has been run at (date and time): %s", ctime(&t));

    quadtimer();

    return 0;
}
