#include "ui.h"
#include <ncurses.h>
#include <stdlib.h>

void ImgShell(WINDOW* LocalWin) {
    int Maxy, Maxx;
    getmaxyx(LocalWin, Maxy, Maxx);

    mvwaddch(LocalWin, 0, 2, '|');
    mvwaddch(LocalWin, 1, 2, '|');
    mvwprintw(LocalWin, 2, 0, "--+");
    wmove(LocalWin, 2, 3);

    for (int i = 0; i < (COLS - 4) / 2; i++) {
        wprintw(LocalWin, "-^");
    }

    for (int i = 0; i < COLS - 4; i++) {
        if ((i % 4) == 3) {
            mvwaddch(LocalWin, 1, i + 3, '|');
        }
    }

    for (int i = 0; i < (COLS - 4) / 2; i++) {
        if ((i % 2) == 1) {
            mvwprintw(LocalWin, 0, 2 * i + 3, "%02d", i);
        } else {
            mvwprintw(LocalWin, 1, 2 * i + 3, "%02d", i);
        }
    }

    for (int i = 0; i < Maxy - 3; i++) {
        mvwprintw(LocalWin, i + 3, 0, "%02d|", i);
    }

    wrefresh(LocalWin);
}

void InfoLine(WINDOW* LocalWin) {
    int Maxy, Maxx;
    getmaxyx(LocalWin, Maxy, Maxx);
    wattron(LocalWin, COLOR_PAIR(color_pair));
    for (int i = 0; i < Maxx; i++) {
        mvwaddch(LocalWin, 0, i, ' ');
    }
    wattroff(LocalWin, COLOR_PAIR(color_pair));
    mvwprintw(LocalWin, 0, 0, "color = %d", color_pair);

    wrefresh(LocalWin);
}
