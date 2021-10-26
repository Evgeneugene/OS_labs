#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>


struct inode{
    int inode;
    char file[256];
};

int main(int argc, char *argv[]){
    DIR *tmp;
    struct inode inodes[1024];
    inodes[0].inode = 0;
    struct dirent *dirp;
    struct stat fstat;
    char fpaths[512];
    tmp = opendir("tmp");
    int N = 0;
    while ((dirp = readdir(tmp)) != NULL) {
        if (dirp->d_type != 8){
            continue;
        }
        int res = snprintf(fpaths, sizeof(fpaths), "tmp/%s", dirp->d_name);
        if ( res >= 512 || res < 0 ){
            printf("ERROR: failed to write");
            return(-1);
        }
        stat(fpaths, &fstat);
        if ( fstat.st_nlink >= 2) {
            inodes[N].inode = fstat.st_ino;
            strcpy( inodes[N].file, dirp->d_name);
            inodes[N + 1].inode = 0;
            N++;
        }
    }

    int i = 0;
    while ( inodes[i].inode != 0 ){
        printf("%s ——— ", inodes[i].file);
        int inode = inodes[i].inode;
        int i_temp = 0;
        int checked = 0;
        while ( inodes[i_temp].inode != 0 ){
            if (inodes[i_temp].inode == inode){
                if (checked != 0){
                    printf(", ");
                }
                checked++;
                printf("%s", inodes[i_temp].file);
            }
            i_temp++;
        }
        i++;
        printf("\n");
    }
    closedir(tmp);
    exit(0);
}