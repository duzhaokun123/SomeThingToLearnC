#include "leaderboard.h"
#include <ncurses.h>
#include <stdlib.h>
#include "ui.h"

void MainLeaderboard(void) {
    erase();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    GameName(0, 0);

    char ch;
    FILE* fp = fopen("data", "r");
    move(3, 0);
    if (fp != NULL) {
        while (feof(fp) == false) {
            addch(fgetc(fp));
        }
        fclose(fp);
    } else {
        printw("错误:无法打开 './data' \n");
        printw("文件不存在或没有权限");
        mvchgat(3, 0, -1, A_BOLD, 1, NULL);
        mvchgat(4, 0, -1, A_BOLD, 1, NULL);
    }
    refresh();
    mvprintw(LINES - 1, 0, "<Enter> 了解");
    while (getch() != 10) {
        ;
    }
}
