#include <ncurses.h>
#include <stdlib.h>
#include "string-getter.h"

char* StringGetter(WINDOW* LocalWin) {
    echo();
    curs_set(1);
    nocbreak();
    mvwaddch(LocalWin, 0, 0, ':');
    char* String = (char*)malloc(100 * sizeof(char));
    int ch;
    for (int i = 0; (ch = wgetch(LocalWin)) != '\n'; i++) {
        String[i] = ch;
        String[i + 1] = '\0';
    }
    curs_set(0);
    return String;
}


//好难, 放弃了
/*
#include "string-getter.h"
#include <ncurses.h>
#include <stdlib.h>

void ResetWin(WINDOW*, char*);
void StringAdd(char*, char);
void StringBackspace(char*);

char* Start;
char* End;

char* StringGetter(WINDOW* LocalWin) {
    noecho();
    char* String = (char*)malloc(102 * sizeof(char));
    for (int i = 0; i < 102; i++) {
        String[i] = '\0';
    }
    char* Cursor = String;
    cbreak();
    int Input = '\0';
    Start = String;
    End = &String[100];
    keypad(LocalWin, true);
    while ((Input = getch()) != '\n') {
        switch (Input) {
            case KEY_LEFT:
                if (Cursor == Start) {
                    fprintf(stderr, "\a");
                } else {
                    Cursor = Cursor - 1;
                }
                break;

            case KEY_RIGHT:
                if ((Cursor + 1) == End) {
                    fprintf(stderr, "\a");
                } else {
                    Cursor = Cursor + 1;
                }
                break;

            case KEY_UP:
            case KEY_DOWN:
                fprintf(stderr, "\a");
                break;

            case KEY_BACKSPACE:
                StringBackspace(Cursor);
                if (Cursor != Start) {
                    Cursor--;
                }
                break;

            default:
                StringAdd(Cursor, Input);
                Cursor++;
                break;
        }
        ResetWin(LocalWin, String);
    }

    return String;
}

void ResetWin(WINDOW* LocalWin, char* String) {
    int y, x;
    getmaxyx(LocalWin, y, x);

    waddch(LocalWin, ':');
    for (int i = 0; i < y * x - 1; i++) {
        waddch(LocalWin, ' ');
    }
    mvwprintw(LocalWin, 0, 1, "%s", String);
}

void StringAdd(char* Cursor, char Input) {
    for (char* p = (End - 1); p != Cursor; p--) {
        *(p + 1) = *p;
    }
    *Cursor = Input;
}

void StringBackspace(char* Cursor) {
    if (Cursor == Start) {
        fprintf(stderr, "\a");
        return;
    }

    for (char* p = (Cursor - 1); p != (End + 1); p++) {
        *p = *(p + 1);
    }
}

*/
