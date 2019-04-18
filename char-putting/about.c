#include <ncurses.h>
#include "about.h"
#include "ui.h"

void MainAbout(void) {
    erase();
    GameName(0, 0);
    AboutList(2, (COLS - 10) / 2);
    mvprintw(LINES - 1, 0, "<任意键> 了解");
    getch();
}
