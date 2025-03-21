#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include "time.h"

int nanosleep(const struct timespec *time_to_wait, struct timespec *remaining_time)
{
    long res = syscall(__NR_nanosleep, time_to_wait, remaining_time);
    if (res < 0) {
        errno = -res;
        return -1;
    }
    return 0;
}
