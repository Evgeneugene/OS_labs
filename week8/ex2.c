#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/*
 * Since the size of RAM is much bigger than 10MB,
 * it is not necessary to perform swap,
 * therefore si and so fields are 0.
 */
int main() {
    int bytes = 1024*1024*10;
    for (int i = 0; i < 10; i++) {
        void* ptr = malloc(bytes);
        memset(ptr, 0, bytes);
        sleep(1);
    }
    return 0;
}
