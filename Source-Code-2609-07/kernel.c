#include "kernel/tty.h"
#include "kernel/io.h"
#include "kernel/kbd.h"
#include "libc/include/string.h"

void kernel_early(void) {
    terminal_initialize();
    terminal_set_color(COLOR_LIGHT_BROWN, COLOR_BLACK);
    printf("---Welcome To WarblerOS!---");
    terminal_set_color(COLOR_LIGHT_GREY, COLOR_BLACK);
}

int main(void) {
    char buff [128];
    memset(buff, 0, sizeof(buff));
    printprompt();
    while (1) {
        uint8_t byte;
        while (byte = scan()) {
            if (byte == 0x1c) {
                if (strlen(buff) > 0 && strcmp(buff, "exit") == 0) {
                    printf("\n-Shutting Down...-");
                    outw(0x604, 0x2000);
                    outw(0x4004, 0x3400);
                    outw(0x600, 0x34);
                    printf("\n-Error 4: WarblerOS failed to shut down. WarblerOS can currently only shut down on Virtual Machines. \nTurn off your computer manually-");
                } else if (strlen(buff) > 0 && strcmp(buff, "about") == 0) {
                    printf("\n--About WarblerOS--");
                    printf("\n-WarblerOS Pre-Alpha Build 2609.07-");
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
                    printf("\n-Fixed a few newline misformats-");
                    printf("\n-Fixed incorrect color names and added light variants to them-");
                    printf("\n-Re added the start message-");
                } else if (strlen(buff) > 0 && strcmp(buff, "bugs") == 0) {
                    printf("\n--Known Bugs For Build 2609.07--");
                    printf("\n-Arrow keys count as number keys-");
                    printf("\n-WarblerOS will not shut down on real hardwarre or unsupported hypervisors such as vmware-");
                } else if (strlen(buff) > 0 && strcmp(buff, "clear") == 0) {
                    terminal_initialize();
                } else if (strlen(buff) > 0 && strcmp(buff, "settings") == 0) {
                    terminal_initialize();
                    printf("\n-Settings-");
                    printf("\n-Error 2: Not Implemented-");
                } else if (strlen(buff) > 0 && strcmp(buff, "mention") == 0) {
                    printf("\nThis is the first mention of Battle For Dream Island in an operating system.");
                } else if (strlen(buff) > 0 && strcmp(buff, "color") == 0) {
                    printf("\n-Error 3: Missing arguements 'text' or 'bg', so try 'color text' or 'color bg'-");

                } else if (strlen(buff) > 0 && strcmp(buff, "color text") == 0) {
                    terminal_initialize();
                    printf("\n--Choose a text color by typing: 'color text' and then the color of choice--");
                    printf("\n-blue-");
                    printf("\n-light blue-");
                    printf("\n-green-");
                    printf("\n-light green-");
                    printf("\n-red-");
                    printf("\n-light red-");
                    printf("\n-yellow-");
                    printf("\n-magenta-");
                    printf("\n-light magenta-");
                    printf("\n-cyan-");
                    printf("\n-light cyan-");
                    printf("\n-brown-");
                    printf("\n-light grey-");
                    printf("\n-dark grey-");
                    printf("\n-white-");
                    
                } else if (strlen(buff) > 0 && strcmp(buff, "color text blue") == 0) {
                    terminal_set_color(COLOR_BLUE, COLOR_BLACK);
                } else if (strlen(buff) > 0 && strcmp(buff, "color text light blue") == 0) {
                    terminal_set_color(COLOR_LIGHT_BLUE, COLOR_BLACK);
                } else if (strlen(buff) > 0 && strcmp(buff, "color text green") == 0) {
                    terminal_set_color(COLOR_GREEN, COLOR_BLACK);
                } else if (strlen(buff) > 0 && strcmp(buff, "color text light green") == 0) {
                    terminal_set_color(COLOR_LIGHT_GREEN, COLOR_BLACK);    
                } else if (strlen(buff) > 0 && strcmp(buff, "color text red") == 0) {
                    terminal_set_color(COLOR_RED, COLOR_BLACK);    
                } else if (strlen(buff) > 0 && strcmp(buff, "color text light red") == 0) {
                    terminal_set_color(COLOR_LIGHT_RED, COLOR_BLACK);
                } else if (strlen(buff) > 0 && strcmp(buff, "color text yellow") == 0) {
                    terminal_set_color(COLOR_LIGHT_BROWN, COLOR_BLACK);
                } else if (strlen(buff) > 0 && strcmp(buff, "color text magenta") == 0) {
                    terminal_set_color(COLOR_MAGENTA, COLOR_BLACK);    
                } else if (strlen(buff) > 0 && strcmp(buff, "color text light magenta") == 0) {
                    terminal_set_color(COLOR_LIGHT_MAGENTA, COLOR_BLACK);    
                } else if (strlen(buff) > 0 && strcmp(buff, "color text cyan") == 0) {
                    terminal_set_color(COLOR_CYAN, COLOR_BLACK);
                } else if (strlen(buff) > 0 && strcmp(buff, "color text light cyan") == 0) {
                    terminal_set_color(COLOR_LIGHT_CYAN, COLOR_BLACK);
                } else if (strlen(buff) > 0 && strcmp(buff, "color text brown") == 0) {
                    terminal_set_color(COLOR_BROWN, COLOR_BLACK);
                } else if (strlen(buff) > 0 && strcmp(buff, "color text light grey") == 0) {
                    terminal_set_color(COLOR_LIGHT_GREY, COLOR_BLACK);        
                } else if (strlen(buff) > 0 && strcmp(buff, "color text dark grey") == 0) {
                    terminal_set_color(COLOR_DARK_GREY, COLOR_BLACK);     
                } else if (strlen(buff) > 0 && strcmp(buff, "color text white") == 0) {
                    terminal_set_color(COLOR_WHITE, COLOR_BLACK); 
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg") == 0) {
                    terminal_initialize();
                    printf("\n--Choose a background color by typing: 'color bg' and then the color of choice--");
                    printf("\n-blue-");
                    printf("\n-light blue-");
                    printf("\n-green-");
                    printf("\n-light green-");
                    printf("\n-red-");
                    printf("\n-light red-");
                    printf("\n-yellow-");
                    printf("\n-magenta-");
                    printf("\n-light magenta-");
                    printf("\n-cyan-");
                    printf("\n-light cyan-");
                    printf("\n-brown-");
                    printf("\n-light grey-");
                    printf("\n-dark grey-");
                    printf("\n-white-");
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg blue") == 0) {
                    terminal_set_color(COLOR_WHITE, COLOR_BLUE);
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg light blue") == 0) {
                    terminal_set_color(COLOR_WHITE, COLOR_LIGHT_BLUE);
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg green") == 0) {
                    terminal_set_color(COLOR_WHITE, COLOR_GREEN);
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg light green") == 0) {
                    terminal_set_color(COLOR_WHITE, COLOR_LIGHT_GREEN);    
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg red") == 0) {
                    terminal_set_color(COLOR_WHITE, COLOR_RED);    
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg light red") == 0) {
                    terminal_set_color(COLOR_WHITE, COLOR_LIGHT_RED);
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg yellow") == 0) {
                    terminal_set_color(COLOR_WHITE, COLOR_LIGHT_BROWN);
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg magenta") == 0) {
                    terminal_set_color(COLOR_WHITE, COLOR_MAGENTA);    
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg light magenta") == 0) {
                    terminal_set_color(COLOR_WHITE, COLOR_LIGHT_MAGENTA);    
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg cyan") == 0) {
                    terminal_set_color(COLOR_WHITE, COLOR_CYAN);
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg light cyan") == 0) {
                    terminal_set_color(COLOR_WHITE, COLOR_LIGHT_CYAN);
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg brown") == 0) {
                    terminal_set_color(COLOR_WHITE, COLOR_BROWN);
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg light grey") == 0) {
                    terminal_set_color(COLOR_WHITE, COLOR_LIGHT_GREY);        
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg dark grey") == 0) {
                    terminal_set_color(COLOR_WHITE, COLOR_DARK_GREY);     
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg white") == 0) {
                    terminal_set_color(COLOR_BLACK, COLOR_WHITE);     
                } else {
                    printf("\nError 1: Not a valid command. Type 'help' for commands.");
                }
                
                printprompt();
                memset(&buff[0], 0, sizeof(buff));
                break;
            } else {
                char c = normalmap[byte];
                if (c == '\b') {
                    size_t len = strlen(buff);
                    if (len > 0) {
                        buff[len - 1] = '\0';
                        printf("\b");
                    }
                } else {
                    char *s;
                    s = ctos(s, c);
                    printf("%s", s);
                    strcpy(&buff[strlen(buff)], s);
                }
            }
            move_cursor(get_terminal_row(), get_terminal_col());
        }
    }
    return 0;
}
