#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <time.h>
#include <unistd.h>

int whoWin(char p[]);
void step(int player, int playerType, char checkerboard[]);
void printCheckerboard(char checkerboard[]);
void end(void);

int main(void) {
    char checkerboard[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int mode = 0;
    int winer = 0;
    srand(time(0));

    printf("1: PvP\n2: PvC\n3: CvP\n4: CvC\n");
    printf("P-Player\nC-Computer\n\n");
    printf("Choose a MODE\n");
    scanf("%d", &mode);
    if (mode == 1 || mode == 2 || mode == 3 || mode == 4) {
        printf("Game Start\n");
    } else {
        printf("NO THAT MODE!!!\n");
        return 1;
    }

    for (int i = 1; i < 10; i++) {
        printCheckerboard(checkerboard);

        if (i % 2 == 1 && (mode == 1 || mode == 2)) {
            step(1, 1, checkerboard);
        } else if (i % 2 == 1 && (mode == 3 || mode == 4)) {
            step(1, 2, checkerboard);
        } else if (i % 2 == 0 && (mode == 1 || mode == 3)) {
            step(2, 1, checkerboard);
        } else if (i % 2 == 0 && (mode == 2 || mode == 4)) {
            step(2, 2, checkerboard);
        }

        winer = whoWin(checkerboard);
        sleep(1);
        if (winer != 0) {
            break;
        }
    }

    printCheckerboard(checkerboard);

    if (winer == 1) {
        printf("X win\n");
    } else if (winer == 2) {
        printf("O win\n");
    } else {
        printf("DRAW\n");
    }

    sleep(2);
    end();

    return 0;
}

void step(int player, int playerType, char checkerboard[]) {
    int p, exit = 1;
    char piece = ' ';
    if (player == 1) {
        piece = 'X';
    } else {
        piece = 'O';
    }
    do {
    top:
        if (playerType == 1) {
            scanf("%d", &p);
        } else {
            p = rand() % 10;
        }

        if (playerType == 1 && p > 9) {
            printf("无效位置\n");
            goto top;
        } else if (playerType == 2 && p > 9) {
            goto top;
        }

        if (checkerboard[p - 1] == ' ') {
            checkerboard[p - 1] = piece;
            exit = 0;
        } else {
            if (playerType == 1) {
                printf("位置被占用\n");
            }
            goto top;
        }

    } while (exit);
}

int whoWin(char p[]) {
    int player = 0;
    int winer = 0;
    char examine = ' ';
    for (int i = 0; i < 2; i++) {
        if (i == 1) {
            examine = 'X';
            player = 1;
        } else {
            examine = 'O';
            player = 2;
        }

        if (p[0] == examine && p[1] == examine && p[2] == examine) {
            winer = player;
            break;
        } else if (p[3] == examine && p[4] == examine && p[5] == examine) {
            winer = player;
            break;
        } else if (p[6] == examine && p[7] == examine && p[8] == examine) {
            winer = player;
            break;
        } else if (p[0] == examine && p[3] == examine && p[6] == examine) {
            winer = player;
            break;
        } else if (p[1] == examine && p[4] == examine && p[7] == examine) {
            winer = player;
            break;
        } else if (p[2] == examine && p[5] == examine && p[8] == examine) {
            winer = player;
            break;
        } else if (p[0] == examine && p[4] == examine && p[8] == examine) {
            winer = player;
            break;
        } else if (p[2] == examine && p[4] == examine && p[6] == examine) {
            winer = player;
            break;
        }
    }

    return winer;
}

void printCheckerboard(char checkerboard[]) {
    printf("%c|%c|%c\n", checkerboard[0], checkerboard[1], checkerboard[2]);
    printf("-+-+-\n");
    printf("%c|%c|%c\n", checkerboard[3], checkerboard[4], checkerboard[5]);
    printf("-+-+-\n");
    printf("%c|%c|%c\n\n", checkerboard[6], checkerboard[7], checkerboard[8]);
}

void end(void) {
    int x, y, color;
    struct winsize w;
    for (int i = 0; i < 50000; i++) {
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        x = rand() % w.ws_col;
        y = rand() % w.ws_row;
        color = rand() % 8;
        printf("\033[%d;%dH\033[%dm ", y, x, color + 40);
    }
    printf("\033[0m");
}
