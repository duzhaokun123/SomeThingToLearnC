OBJ = main.o

ALL: rgb-getter

rgb-getter: $(OBJ)
	gcc -l ncursesw $(OBJ) -o rgb-getter

main.o: main.c main.h

.PHONY: ALL clean

clean:
	rm -rf $(OBJ) rgb-getter
