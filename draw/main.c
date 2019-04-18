#include <locale.h>
#include <ncurses.h>
#include <stdlib.h>
#include "ui.h"
#include "string-getter.h"
#include "command-getter.h"
#include "list.h"
#include "basic-command-interpreter.h"
#include "full-pair-init.h"

int main(void) {
    setlocale(LC_ALL, " ");
    initscr();
    if (has_colors() == false) {
        endwin();
        printf("终端不支持颜色\n");
        exit(1);
    }
    start_color();
    noecho();
    cbreak();
    keypad(stdscr, true);
    curs_set(0);
    refresh();

    _ImgShell = newwin(LINES - 2, COLS, 0, 0);
    ImgShell(_ImgShell);

    _ImgShower = newwin(LINES - 5, COLS - 3, 3, 3);
    wrefresh(_ImgShower);

    _CommandLine = newwin(1, COLS, LINES - 2, 0);
    wrefresh(_CommandLine);

    _InfoLine = newwin(1, COLS, LINES - 1, 0);
    InfoLine(_InfoLine);

    FullPairInit();

    int Input;
    char* Com;
    List Commands;

    while ((Input = mvwgetch(_CommandLine, 0, 0)) != 'Q') {
        switch (Input) {
            case 'q':
                endwin();
                exit(0);
                break;

            case ':':
                Com = StringGetter(_CommandLine);
                Commands = CommandGetter(Com);
                BasicCommandInterpreter(Commands, _ImgShower, _InfoLine);
                list_free(Commands);
                free(Com);
                cbreak();
                wclear(_CommandLine);

            case 'r':
                refresh();
                wrefresh(_ImgShell);
                wrefresh(_ImgShower);
                wrefresh(_CommandLine);
                wrefresh(_InfoLine);
                break;

            default:
                wrefresh(_CommandLine);
                fprintf(stderr, "\a");
                break;
        }
        noecho();
    }
    endwin();
    return 0;
}
