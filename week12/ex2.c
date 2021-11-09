#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
int main(int argc, char *argv[]){
    char name[264] = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    struct input_event inputEvent[64];
    size_t size;
    int file = open(name, O_RDONLY);
    if (file == -1) {
        perror("ERROR: Can not open the file\n");
        exit(EXIT_FAILURE);
    }
    while(1) { 
        size = read(file, inputEvent, sizeof(inputEvent));
        for(int i = 0; i < (size/sizeof(struct input_event)); i++) {
            if (inputEvent[i].code == 54){ //right shift exits
                return 0;
            }
            if (inputEvent[i].type == EV_KEY && inputEvent[i].value == 1){
                printf("PRESSED: 0x%x (%d)\n", inputEvent[i].code, inputEvent[i].code);
            }
            else if (inputEvent[i].type == EV_KEY && inputEvent[i].value == 0){
                printf("RELEASED: 0x%x (%d)\n", inputEvent[i].code, inputEvent[i].code);
            }
        }
    }
    close(file);
    return 0;
}
