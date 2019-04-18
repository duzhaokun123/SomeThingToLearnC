#include "file-command-interpreter.h"
#include <ncurses.h>
#include <stdlib.h>
#include "basic-command-interpreter.h"
#include "command-getter.h"
#include "infoshower.h"
#include "list.h"
#include "ui.h"
#include "string.h"

void FileCommandInterpreter(List Commands) {
    for (int i = 2; i <= Commands->total; i++) {
        FILE* File = fopen(list_at(Commands, i), "r");
        if (File == NULL) {
            char* FileName =
                (char*)malloc(strlen("无法打开 ") +
                              strlen(list_at(Commands, i) + 1) * sizeof(char));
            FileName[0] = '\0';
            strcat(FileName, "无法打开 ");
            strcat(FileName, list_at(Commands, i));
            InfoShower(ERROR, FileName);
            free(FileName);
        } else {
            if (strstr(list_at(Commands, 2), ".mp2k") == NULL) {
                InfoShower(WARNING,"警告: 不是 .mp2k 文件");
            }
            char* FileCommands = (char*)malloc(100 * sizeof(char));
            char ch;
            for (int i = 0; i < 50; i++) {
                int i = 0;
                ch = fgetc(File);
                for (; ch != '\n'; i++) {
                    FileCommands[i] = ch;
                    ch = fgetc(File);
                }

                FileCommands[i] = '\0';
                List Commands_ = list_new();
                Commands_ = CommandGetter(FileCommands);
                BasicCommandInterpreter(Commands_, _ImgShower, _InfoLine);
                list_free(Commands_);
            }
            free(FileCommands);
            fclose(File);
        }
    }
}
