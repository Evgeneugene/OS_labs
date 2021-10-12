#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>
/*
 *  With use of top command we can see that
 *  each second the use of memory was increasing
 */
int main() {
    int bytes = 1024*1024*10;
    for (int i = 0; i < 10; i++) {
        void* ptr = malloc(bytes);
        memset(ptr, 0, bytes);
        struct rusage usage;
        getrusage(RUSAGE_SELF, &usage);
        printf("The maximum resident set size used: %li KB\n", usage.ru_maxrss);
        sleep(1);
    }
    return 0;
}