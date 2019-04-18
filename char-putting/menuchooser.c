#include "menuchooser.h"
#include <ncurses.h>
#include <stdbool.h>

int MenuChooser(int y, int x, int choiceNumber) {
    int choice = 0;
    int input;
    bool out = false;

    while (out == false) {
        raw();
        mvaddch(y + choice, x, '>');
        refresh();
        switch (getch()) {
            case KEY_UP:
                mvaddch(y + choice, x, ' ');
                if (choice == 0) {
                    choice = choiceNumber;
                } else {
                    choice = choice - 1;
                }
                break;

            case KEY_DOWN:
                mvaddch(y + choice, x, ' ');
                if (choice == choiceNumber) {
                    choice = 0;
                } else {
                    choice = choice + 1;
                }
                break;

            case 10:
                out = true;
                break;
        }
    }

    return choice;
}
