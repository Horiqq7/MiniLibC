#include <stdio.h>
#include <errno.h>
#include "time.h"

unsigned int sleep(unsigned int seconds)
{
    struct timespec time_to_wait;
    struct timespec remaining_time;

    time_to_wait.tv_sec = seconds;
    time_to_wait.tv_nsec = 0;

    while (nanosleep(&time_to_wait, &remaining_time) == -1) {
        if (errno != EINTR) {
            return seconds - remaining_time.tv_sec;
        }
        time_to_wait = remaining_time;
    }
    return 0;
}
