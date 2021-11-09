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
    int pressed_buttons[1000] = {0};
    while(1) { 
        size = read(file, inputEvent, sizeof(inputEvent));
        for(int i = 0; i < (size/sizeof(struct input_event)); i++) {
            if (inputEvent[i].code == 54){ //right shift exits
                return 0;
            }
            if (inputEvent[i].type == EV_KEY && inputEvent[i].value == 1){
                pressed_buttons[inputEvent[i].code] = 1; //pressed
                printf("\nPRESSED: 0x%x (%d)\n", inputEvent[i].code, inputEvent[i].code);
            }
            else if (inputEvent[i].type == EV_KEY && inputEvent[i].value == 0){
                if ( pressed_buttons[25] == 1 && pressed_buttons[18] == 1 ){
                    printf("\nI passed the Exam!\n");
                }
                else if ( pressed_buttons[46] == 1 && pressed_buttons[30] == 1 && pressed_buttons[25] == 1){
                    printf("\nGet some cappuccino!\n");
                }           
                else if ( pressed_buttons[32] == 1 && pressed_buttons[25] == 1 ){
                    printf("\nDropped...\n");
                }
                pressed_buttons[inputEvent[i].code] = 0; //released
                printf("\nRELEASED: 0x%x (%d)\n", inputEvent[i].code, inputEvent[i].code);
            }
        }
        
    }
    close(file);
    return 0;
}
