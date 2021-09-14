#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

void Sys(const char* program, const char* arg) {
    pid_t pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error fork\n");
    } else if (pid > 0) {
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            printf("Exit code = %d\n", WEXITSTATUS(status));
        }
        printf("\n");
    } else {
        if (execlp(program, program, arg, NULL) == -1) {
            fprintf(stderr, "Error exec\n");
            _exit(42);
        }
    }
}

int main() {
    char str[257];
    while(1) {
        fgets(str, 257, stdin);
        char command[257];
        char args[257];
        sscanf(str, "%s %s", command, args);
        Sys(command, args);
    }
    return 0;
}