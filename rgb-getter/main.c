#include "main.h"
#include <locale.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

int cntin(char*);

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, " ");
    if (!(argc == 4 || argc == 1)) {
        printf(
            "%s: 用法\n"
            "%s [r] [g] [b]\n",
            argv[0], argv[0]);
        exit(2);
    }
    initscr();
    if (has_colors() == false) {
        endwin();
        printf("你的终端不支持颜色\n");
        exit(1);
    }
    start_color();
    cbreak();
    noecho();
    srand(time(0));
    curs_set(0);

    RgbInfo UserColor;
    if (argc != 1) {
        UserColor.r = cntin(argv[1]);
        UserColor.g = cntin(argv[2]);
        UserColor.b = cntin(argv[3]);
    }
    if (UserColor.r > 1000) {
        endwin();
        printf("参数 r 过大 (最大1000)\n");
        exit(4);
    }

    if (UserColor.b > 1000) {
        endwin();
        printf("参数 b 过大 (最大1000)\n");
        exit(4);
    }

    if (UserColor.g > 1000) {
        endwin();
        printf("参数 g 过大 (最大1000)\n");
        exit(4);
    }
    do {
        init_color(USERCOLOR, UserColor.r, UserColor.g, UserColor.b);
        init_pair(1, COLOR_BLACK, USERCOLOR);
        attron(COLOR_PAIR(1));
        for (int i = 0; i < LINES * COLS; i++) {
            addch(' ');
        }
        attroff(COLOR_PAIR(1));
        mvprintw(LINES - 1, 0,
                 "r = %d g = %d b = %d <任意键> 随机 <Enter> 了解", UserColor.r,
                 UserColor.g, UserColor.b);
        refresh();

        UserColor.r = rand() % 1001;
        UserColor.g = rand() % 1001;
        UserColor.b = rand() % 1001;

    } while (getch() != '\n');
    endwin();
    return 0;
}

int cntin(char* InputChar) {
    int OutInt = 0;
    for (int i = 0; i < strlen(InputChar); i++) {
        if (InputChar[i] <= '9' && InputChar[i] >= '0') {
            OutInt = OutInt * 10 + (InputChar[i] - '0');
        } else {
            endwin();
            printf("错误的参数%s\n", InputChar);
            exit(3);
        }
    }

    return OutInt;
}
