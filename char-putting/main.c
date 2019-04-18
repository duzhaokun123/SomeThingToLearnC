#include <locale.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include "about.h"
#include "game.h"
#include "leaderboard.h"
#include "menuchooser.h"
#include "ui.h"

int main(void) {
    //初始化
    setlocale(LC_ALL, " ");
    initscr();
    start_color();
    raw();
    noecho();
    keypad(stdscr, true);
    curs_set(0);
    int choice;

    //窗口是否合格
    if (COLS < 28 || LINES < 11) {
        endwin();
        fprintf(stderr, "错误! 窗口太小\n");
        exit(1);
    }
    while (1) {
        //主界面
        erase();
        GameName(0, 0);
        Logo(2, (COLS - 17) / 2);
        MainMenu(6, (COLS - 10) / 2);
        mvprintw(LINES - 1, 0, "<Up> <Down> 滚动 <Enter> 选择");
        refresh();
        switch (MenuChooser(7, (COLS - 10) / 2 - 1, 3)) {
            case 0:
                MainGame();
                break;
            case 1:
                MainLeaderboard();
                break;
            case 2:
                MainAbout();
                break;
            case 3:
                endwin();
                exit(0);
                break;
        }
    }

    getch();
    endwin();

    return 0;
}
