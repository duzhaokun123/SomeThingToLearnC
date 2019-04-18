#include <ncurses.h>
#include <stdlib.h>
#include "command-getter.h"
#include "list.h"

List CommandGetter(char* str) {
    char* Temp[100] = {NULL};
    List Commands = list_new();
    char* p = NULL;
    int i = 0;
    Temp[i] = str;
    int strl = strlen(str);
    for (p = str; i <= strl; i++) {
        if (*p == ' ') {
            *p = '\0';
            Temp[i] = (p + 1);
        }
        p++;
    }

    for (int i = 0; i < 100; ) {
        if(Temp[i] != '\0') {
            list_add(Commands, Temp[i]);
        }
        i++;
    }
    
    return Commands;
}

