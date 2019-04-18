#include "basic-command-interpreter.h"
#include <ncurses.h>
#include <stdlib.h>
#include "file-command-interpreter.h"
#include "infoshower.h"
#include "list.h"
#include "ui.h"

void BasicCommandInterpreter(List Commands, WINDOW* LocalWin,
                             WINDOW* _InfoLine) {
    if (Commands->total == 0) {
        return;
    }
    if (strcmp(list_at(Commands, 1), "point") == 0) {
        if (Commands->total > 3) {
            InfoShower(ERROR, "过多参数");
        } else if (Commands->total < 3) {
            InfoShower(ERROR, "过少参数");
        } else {
            mvwprintw(LocalWin, atoi(list_at(Commands, 2)),
                      atoi(list_at(Commands, 3)) * 2, "  ");
        }
    } else if (strcmp(list_at(Commands, 1), "color") == 0) {
        if (Commands->total > 2) {
            InfoShower(ERROR, "过多参数");
        } else if (Commands->total < 2) {
            InfoShower(ERROR, "过少参数");
        } else {
            color_pair = atoi(list_at(Commands, 2));
            wattrset(LocalWin, A_NORMAL);
            wattron(LocalWin, COLOR_PAIR(color_pair));
        }
    } else if (strcmp(list_at(Commands, 1), "exit") == 0) {
        endwin();
        exit(0);
    } else if (strcmp(list_at(Commands, 1), "file") == 0) {
        FileCommandInterpreter(Commands);
    } else if (strcmp(list_at(Commands, 1), "plugin") == 0) {
        InfoShower(INFO, "使用 plugin 命令");
    } else if (strcmp(list_at(Commands, 1), "null") == 0) {
        ;
    } else if (strcmp(list_at(Commands, 1), "info") == 0) {
        if (Commands->total != 3) {
            InfoShower(ERROR, "格式错误");
        } else if (strcmp(list_at(Commands, 2), "error") == 0) {
            InfoShower(ERROR, list_at(Commands, 3));
        } else if (strcmp(list_at(Commands, 2), "warning") == 0) {
            InfoShower(WARNING, list_at(Commands, 3));
        } else if (strcmp(list_at(Commands, 2), "info") == 0) {
            InfoShower(INFO, list_at(Commands, 3));
        } else if (strcmp(list_at(Commands, 2), "common") == 0) {
            InfoShower(COMMON, list_at(Commands, 3));
        }
    } else {
        char* ErrInfo =
            (char*)malloc((strlen("无效命令") +
                           strlen(list_at(Commands, 1) + 1) * sizeof(char)));
        ErrInfo[0] = '\0';
        strcat(ErrInfo, "无效命令 ");
        strcat(ErrInfo, list_at(Commands, 1));
        InfoShower(ERROR, ErrInfo);
        free(ErrInfo);
    }

    InfoLine(_InfoLine);
}
