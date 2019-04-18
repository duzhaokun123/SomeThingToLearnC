#include "ui.h"
#include "compile-info.h"
#include <ncurses.h>

void GameName(int y, int x) {
    mvprintw(y, x, "Char-putting Game");
    refresh();
}

void Logo(int y, int x) {
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(2));
    mvprintw(y + 0, x, "[               ]");
    mvprintw(y + 1, x, "[此处应该有 LOGO]");
    mvprintw(y + 2, x, "[               ]");
    attroff(COLOR_PAIR(2));
    refresh();
}

void MainMenu(int y, int x) {
    mvprintw(y + 0, x, "   菜单   ");
    mvprintw(y + 1, x, "0.开始游戏");
    mvprintw(y + 2, x, "1.排 行 榜");
    mvprintw(y + 3, x, "2. 关  于 ");
    mvprintw(y + 4, x, "3. 退  出 ");
    refresh();
}

void AboutList(int y, int x) {
    mvprintw(y + 0, x, "   Char-  ");
    mvprintw(y + 1, x, "  putting ");
    mvprintw(y + 2, x, "   Game   ");
    mvprintw(y + 3, x, "          ");
    mvprintw(y + 4, x, "一个测试你");
    mvprintw(y + 5, x, "手速的游戏");
    mvprintw(y + 6, x, "          ");
    mvprintw(y + 7, x, "by 杜兆琨 ");
    mvprintw(y + 8, x, " 编译信息 ");
    mvprintw(y + 9, x, "%s", GetCompileDate());
    mvprintw(y +10, x, "%s", GetCompileTime());
}

void PlayerName(int y, int x) {
    mvprintw(y + 0, x, "   成绩   ");
    mvprintw(y + 1, x, "*        *");
    mvprintw(y + 2, x, "          ");
    mvprintw(y + 3, x, "输入玩家名");
    mvprintw(y + 4, x, "最多 8字符");
    mvprintw(y + 5, x, "          ");
    mvprintw(y + 6, x, "[________]");
    refresh();
}

void Description(int y, int x) {
    mvprintw(y + 0, x, "     玩法     ");
    mvprintw(y + 1, x, "在 1秒内尽可能");
    mvprintw(y + 2, x, " 多的输入字符 ");
    mvprintw(y + 3, x, "              ");
    mvprintw(y + 4, x, " 按<Enter>开始");
    refresh();
}

void LeaderboardMenu(int y, int x);

