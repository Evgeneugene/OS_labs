#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>


int main(int argc, char *argv[]){
    DIR *dp;
    struct dirent *dir_p;
    char path[512];
    dp = opendir("/");
    while ((dir_p = readdir(dp)) != NULL) {
        printf("%s\n", dir_p->d_name);
    }
    closedir(dp);
    exit(EXIT_SUCCESS);
}
