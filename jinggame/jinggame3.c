#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <time.h>
#include <unistd.h>
#include "color.h"
#include "cursor.h"

void DoStep(char PlayerType, char Piece, char* Checkerboard);
void PrintCol(int Color, int Y, int X);
void PrintRow(int Color, int Y, int X);
void PrintCheckerboard(void);
int PlayerStep(char Piece, char* Checkerboard);
int ComputerStep(char Piece, char* Checkerboard);
int ComputerTaoluUse(char Piece, char* Checkerboard);
char WhoWin(char* Checkerboard);
void PrintPiece(int piece, char Point);

int main(void) {
    int re = 0;
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    for (int i = 0; i < w.ws_row - 1; i++) {
        for (int i = 0; i < w.ws_col; i++) {
            printf(BLACK_bg " " RESET);
        }
    }
    for (int i = 0; i < w.ws_col - 1; i++) {
        printf(BLACK_bg " " RESET);
    }
    printf(CURSOR_set, 1, 1);

    if (w.ws_row < 14 || w.ws_col < 11) {
        printf(RED "错误!" RESET "请确定窗口大小大于 14 * 11\n");
        re = 1;
    } else {
        int GameModen;

        printf(
            "选择模式\n\n"
            "1. PvP\n"
            "2. PvC\n"
            "3. CvP\n"
            "4. CvC\n\n"
            "输入代号:");
        scanf("%d", &GameModen);

        srand(time(0));
        int Step = 0;
        char Checkerboard[3][3] = {0};
        int Out = 0;
        char Winer;

        while (!(Out == 1)) {
            PrintCheckerboard();

            if (GameModen > 4) {
                printf(RED "错误!" RESET "没有那个代号 %d\n", GameModen);
                re = 1;
                Out = 1;
            } else if ((GameModen == 1 || GameModen == 2) && Step % 2 == 0) {
                DoStep('P', 'X', &Checkerboard[0][0]);
            } else if ((GameModen == 1 || GameModen == 3) && Step % 2 == 1) {
                DoStep('P', 'O', &Checkerboard[0][0]);
            } else if ((GameModen == 3 || GameModen == 4) && Step % 2 == 0) {
                DoStep('C', 'X', &Checkerboard[0][0]);
            } else if ((GameModen == 2 || GameModen == 4) && Step % 2 == 1) {
                DoStep('C', 'O', &Checkerboard[0][0]);
            } else {
                printf(RED "未知错误\n" RESET);
                re = 1;
                Out = 1;
            }

            if ((Winer = WhoWin(&Checkerboard[0][0])) != 0) {
                if (Winer == 'X') {
                    printf("X 赢了\n");
                } else if (Winer == 'O') {
                    printf("O 赢了\n");
                }

                re = 0;
                Out = 1;
            }

            Step++;

            if (Step == 9) {
                printf("平局\n");
                Out = 1;
            }
        }
    }

    return re;
}

void DoStep(char PlayerType, char Piece, char* Checkerboard) {
    int Point;

    if (PlayerType == 'P') {
        Point = PlayerStep(Piece, Checkerboard);
    } else if (PlayerType == 'C') {
        Point = ComputerStep(Piece, Checkerboard);
    }

    PrintPiece(Piece, Point);
}

void PrintCol(int Color, int Y, int X) {
    for (int i = 0; i < 11; i++) {
        printf(CURSOR_set, Y + i, X);
        printf("\033[%dm  ", Color + 40);
        printf(RESET);
    }
}

void PrintRow(int Color, int Y, int X) {
    for (int i = 0; i < 22; i++) {
        printf(CURSOR_set, Y, X + i);
        printf("\033[%dm ", Color + 40);
        printf(RESET);
    }
}

void PrintCheckerboard(void) {
    for (int i = 0; i < 11; i++) {
        PrintCol(7, 1, 1 + i);
    }
    PrintCol(3, 1, 4);
    PrintCol(3, 1, 8);
    PrintRow(3, 4, 8);
    PrintRow(3, 8, 1);
}

