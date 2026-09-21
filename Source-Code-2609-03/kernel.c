#include "kernel/tty.h"
#include "kernel/io.h"
#include "kernel/kbd.h"
#include "libc/include/string.h"

void kernel_early(void) {
    terminal_initialize();
}

int main(void) {
    char *buff;
    strcpy(&buff[strlen(buff)], "");
    printprompt();
    while (1) {
        uint8_t byte;
        while (byte = scan()) {
            if (byte == 0x1c) {
                if (strlen(buff) > 0 && strcmp(buff, "exit") == 0) {
                    printf("\n-Shutting Down...-");
                    printf("\n-It is now safe to turn off our computer-");
                    outb(0x604, 0x2000);
                    break;
                } else if (strlen(buff) > 0 && strcmp(buff, "about") == 0) {
                    printf("\n--About WarblerOS--");
                    printf("\n-WarblerOS Pre-Alpha Build 2609.03-");
                    printf("\n-Created by Gavin Elias-");
                } else if (strlen(buff) > 0 && strcmp(buff, "help") == 0) {
                    printf("\n--Commands--");
                    printf("\n-exit: Exit WarblerOS-");
                    printf("\n-about: View info about WarblerOS-");
                    printf("\n-devlog: View the WarblerOS devlog-");
                    printf("\n-bugs: View the known bugs of this build-");
                    printf("\n-settings: Coming Soon-");
                    printf("\n-color: Change the WarblerOS text color-");
                } else if (strlen(buff) > 0 && strcmp(buff, "devlog") == 0) {
                    printf("\n--Devlog--");
                    printf("\n-Current Build: 2609.03-");
                    printf("\n-Added green, orange, purple, cyan, brown, light grey, and dark grey as colors-");
                    printf("\n-Added a bit more to settings-");
                } else if (strlen(buff) > 0 && strcmp(buff, "bugs") == 0) {
                    printf("\n--Known Bugs For Build 2609.03--");
                    printf("\n-Arrow keys count as number keys-");
                    printf("\n-Backspace counts as a character and can mess up commands");
                } else if (strlen(buff) > 0 && strcmp(buff, "clear") == 0) {
                    terminal_initialize();
                } else if (strlen(buff) > 0 && strcmp(buff, "settings") == 0) {
                    terminal_initialize();
                    printf("\n-Settings-");
                    printf("\n-Error 2: Not Implemented-");
                } else if (strlen(buff) > 0 && strcmp(buff, "mention") == 0) {
                    printf("\nThis is the first mention of Battle For Dream Island in an operating system.");
                } else if (strlen(buff) > 0 && strcmp(buff, "color") == 0) {
                    terminal_initialize();
                    printf("\n--Choose a color by typing: 'color' and then the color of choice--");
                    printf("\n-blue-");
                    printf("\n-green-");
                    printf("\n-red-");
                    printf("\n-yellow-");
                    printf("\n-dark red-");
                    printf("\n-purple-");
                    printf("\n-cyan-");
                    printf("\n-brown-");
                    printf("\n-light grey-");
                    printf("\n-dark grey-");
                } else if (strlen(buff) > 0 && strcmp(buff, "color blue") == 0) {
                    terminal_set_color(COLOR_LIGHT_BLUE, COLOR_BLACK);
                } else if (strlen(buff) > 0 && strcmp(buff, "color green") == 0) {
                    terminal_set_color(COLOR_GREEN, COLOR_BLACK);
                } else if (strlen(buff) > 0 && strcmp(buff, "color red") == 0) {
                    terminal_set_color(COLOR_LIGHT_RED, COLOR_BLACK);
                } else if (strlen(buff) > 0 && strcmp(buff, "color yellow") == 0) {
                    terminal_set_color(COLOR_LIGHT_BROWN, COLOR_BLACK);
                } else if (strlen(buff) > 0 && strcmp(buff, "color dark red") == 0) {
                    terminal_set_color(COLOR_RED, COLOR_BLACK);
                } else if (strlen(buff) > 0 && strcmp(buff, "color purple") == 0) {
                    terminal_set_color(COLOR_LIGHT_MAGENTA, COLOR_BLACK);    
                } else if (strlen(buff) > 0 && strcmp(buff, "color cyan") == 0) {
                    terminal_set_color(COLOR_CYAN, COLOR_BLACK);
                } else if (strlen(buff) > 0 && strcmp(buff, "color brown") == 0) {
                    terminal_set_color(COLOR_BROWN, COLOR_BLACK);
                } else if (strlen(buff) > 0 && strcmp(buff, "color light grey") == 0) {
                    terminal_set_color(COLOR_LIGHT_GREY, COLOR_BLACK);        
                } else if (strlen(buff) > 0 && strcmp(buff, "color dark grey") == 0) {
                    terminal_set_color(COLOR_DARK_GREY, COLOR_BLACK);             
                } else {
                    printf("\nError 1: Not a valid command. Type 'help' for commands.");
                }
                
                printprompt();
                memset(&buff[0], 0, sizeof(buff));
                break;
            } else {
                char c = normalmap[byte];
                char *s;
                s = ctos(s, c);
                printf("%s", s);
                strcpy(&buff[strlen(buff)], s);
            }
            move_cursor(get_terminal_row(), get_terminal_col());
        }
    }
    return 0;
}
