#include <ncurses.h>
#include "infoshower.h"

void InfoShower(int Type, char* Info) {
    WINDOW* InfoWin = newwin(1, COLS, LINES - 1, 0);
    if (Type == INFO) {
        wattron(InfoWin, COLOR_PAIR(5) | A_BLINK);
        mvwprintw(InfoWin, 0, 0, "%s", Info);
        wattroff(InfoWin, COLOR_PAIR(5) | A_BLINK);
    } else if (Type == WARNING) {
        wattron(InfoWin, COLOR_PAIR(4) | A_BLINK);
        mvwprintw(InfoWin, 0, 0, "%s", Info);
        wattroff(InfoWin, COLOR_PAIR(4) | A_BLINK);
    } else if (Type == ERROR) {
        wattron(InfoWin, COLOR_PAIR(2) | A_BLINK);
        mvwprintw(InfoWin, 0, 0, "%s", Info);
        wattroff(InfoWin, COLOR_PAIR(2) | A_BLINK);
    } else if (Type == COMMON) {
        wattron(InfoWin, A_BLINK);
        mvwprintw(InfoWin, 0, 0, "%s", Info);
        wattroff(InfoWin, A_BLINK);
    }
    wrefresh(InfoWin);
    halfdelay(10);
    getch();
    cbreak();
    delwin(InfoWin);
}
