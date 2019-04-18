#include "game.h"
#include <ncurses.h>
#include <unistd.h>
#include "record.h"
#include "ui.h"

void MainGame(void) {
    erase();
    GameName(0, 0);
    Description(2, (COLS - 14) / 2);
    mvprintw(LINES - 1, 0, "<Enter> 开始");
    move(0, 0);

    while (getch() != 10) {
        ;
    }

    erase();
    refresh();
    halfdelay(1);
    echo();
    sleep(1);
    int n;

    for (n = 0; getch() != ERR; n++) {
        ;
    }
    noecho();
    
    mvprintw(LINES -1, 0, "<Enter> 结算");
    while (getch() != 10) {
        ;
    }

    refresh();

    MainRecord(n);
}
