#include <unistd.h>
#include <stdio.h>

struct timespec {
    long int tv_sec;
    long int tv_nsec;
};

unsigned int sleep(unsigned int seconds);
int nanosleep(const struct timespec *requested_time, struct timespec *remaining_time);
