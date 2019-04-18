#include "record.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ui.h"
#include <string.h>

void MainRecord(int gtade) {
    erase();
    GameName(0, 0);
    PlayerName(2, (COLS - 10) / 2);
    mvprintw(3, (COLS - 10) / 2 + 1, "%8d", gtade);
    mvprintw(LINES - 1, 0, "<Enter> 输入");
    move(8, (COLS - 10) / 2 + 1);
    refresh();
    echo();
    char* Name = (char*)malloc(100 * sizeof(char));
    scanw("%s", Name);
    raw();

    if (strlen(Name) > 100) {
        endwin();
        fprintf(stderr, "错误! 玩家名过长\n ");
        exit(1);
    }
    time_t temp;
    time(&temp);
    struct tm* Time = gmtime(&temp);

    FILE* fp = fopen("data", "a");
    fprintf(fp, "date:%04d.%02d.%02d time:%02d:%02d:%02d gtade:%8d name:%s\n",
            Time->tm_year + 1900, Time->tm_mon + 1, Time->tm_mday,
            Time->tm_hour, Time->tm_min, Time->tm_sec, gtade, Name);
    fclose(fp);
    free(Name);

    mvprintw(9, (COLS - 8) / 2, "保存成功");
    mvprintw(LINES - 1, 0, "<Enter> 了解");

    while (getch() != 10) {
        ;
    }
}
