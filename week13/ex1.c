#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void read_line(size_t len, FILE *file, int *array, int m) {
    char *line = NULL;
    getline(&line, &len, file);
    char *ptr = line;
    for (int i = 0; i < m; i++){
        array[i] = strtol(ptr, &ptr, 10);
    }
}

int main() {
    FILE *input;
    input = fopen("input.txt", "r");

    const int n = 5, m = 3; //number of processes and number of resource classes
    int E[n] = {0};
    int A[n] = {0};
    int C[n][m] = {0};
    int R[n][m] = {0};
    char *line = NULL;
    size_t length = 0;

    read_line(length, input, E, m);
    getline(&line, &length, input); //skip empty line

    read_line(length, input, A, m);
    getline(&line, &length, input); //skip empty line

    for (int i = 0; i < n; i++) {
        read_line(length, input, C[i], m);
    }
    getline(&line, &length, input); //skip empty line

    for (int i = 0; i < n; i++) {
        read_line(length, input, R[i], m);
    }

    int freed[n] = {0};
    int nDeadlocked = n; //number of deadlocked processes
    while (1) {
        int met_fine_processes = 0;
        for (int i = 0; i < n; i++) {
            if (!freed[i]) { // if the process haven't already been done
                int fine = 1;

                for (int j = 0; j < m; j++) { // if requires too much resources
                    if (R[i][j] > A[j]) {
                        fine = 0;
                    }
                }

                if (fine) { // if can be done and terminated
                    met_fine_processes = 1;
                    freed[i] = 1;
                    nDeadlocked--;
                    for (int j = 0; j < m; j++) {
                        A[j] += C[i][j];
                        C[i][j] = 0;
                        R[i][j] = 0;
                    }
                }
            }
        }
        if (!met_fine_processes) break;
    }
    if (nDeadlocked == 0) {
        printf("No deadlock detected");
    } else {
        printf("Deadlock: %d processes", nDeadlocked);
    }

    fclose(input);
    return 0;
}

