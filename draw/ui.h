#ifndef __UI_H__
#define __UI_H__
#include <ncurses.h>

void ImgShell(WINDOW*);
void InfoLine(WINDOW*);

WINDOW* _ImgShell;
WINDOW* _ImgShower;
WINDOW* _CommandLine;
WINDOW* _InfoLine;

int color_pair;

#endif
