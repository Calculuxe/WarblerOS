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
                    printf("\n-Goodbye!-");
                    outb(0x604, 0x2000);
                } else if (strlen(buff) > 0 && strcmp(buff, "about") == 0) {
                    printf("\n--About WarblerOS--");
                    printf("\n-WarblerOS Pre-Alpha Build 2608.30-");
                    printf("\n-Created by Gavin Elias-");
                } else if (strlen(buff) > 0 && strcmp(buff, "help") == 0) {
                    printf("\n--Commands--");
                    printf("\n-exit: Exit WarblerOS-");
                    printf("\n-about: View info about WarblerOS-");
                    printf("\n-devlog: View the WarblerOS devlog-");
                    printf("\n-bugs: View the known bugs of this build-");
                } else if (strlen(buff) > 0 && strcmp(buff, "devlog") == 0) {
                    printf("\n--Devlog--");
                    printf("\n-Current Build: 2608.30-");
                    printf("\n-Added 'help' command-");
                    printf("\n-Added 'about' command-");
                    printf("\n-Added 'devlog' command-");
                    printf("\n-Fixed terminal column issue-");
                } else if (strlen(buff) > 0 && strcmp(buff, "bugs") == 0) {
                    printf("\n--Known Bugs For Build 2608.30--");
                    printf("\n-Arrow keys count as the 6 key-");
                    printf("\n-Backspace counts as a character and can mess up commands");
                } else {
                    printf("\nNot a valid command. Type 'help' for commands.");
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
