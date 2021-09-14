#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
    int n = 5;
    pid_t child, parent;
    printf("Hello from parent [%d - %d]\n", getpid(), n);
    child = fork();
    if(child != 0)
        printf("Hello from child [%d - %d]\n", child, n);
    return 0;
}
