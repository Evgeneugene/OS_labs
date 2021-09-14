#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    char str[257];
    fgets(str, 257, stdin);
    sscanf(str, "%s", str);
    printf("%s\n", str);
    system(str);
}