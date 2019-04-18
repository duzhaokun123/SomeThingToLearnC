OBJ = main.o ui.o list.o command-getter.o string-getter.o \
	  basic-command-interpreter.o infoshower.o full-pair-init.o \
	  file-command-interpreter.o

ALL: draw

draw: $(OBJ)
	gcc -l ncursesw -o $@ $(OBJ)

main.o: main.c
ui.o: ui.c
list.o: list.c
command-getter: command-getter.c
string-getter: string-getter.c
infoshower.o: infoshower.c
basic-command-infoshower.o: basic-command-infoshower.c
infoshower.o: infoshower.c
full-pair-init.o: full-pair-init.c
file-command-interpreter.o: file-command-interpreter.c

.PHONY: ALL clean

clean:
	-rm -rf $(OBJ) draw


