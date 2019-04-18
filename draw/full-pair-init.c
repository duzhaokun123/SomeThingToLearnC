#include <ncurses.h>
#include "full-pair-init.h"

void FullPairInit(void) {
    for (int i = 0; i < 300; i++) {
        init_pair(i + 1, COLOR_WHITE, i);
    }
}
