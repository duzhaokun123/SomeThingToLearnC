OBJ = main.o ui.o menuchooser.o leaderboard.o game.o about.o record.o \
	  compile-info.o

ALL: char-putting

char-putting: $(OBJ) Make_compile-info.o
	gcc $(OBJ) -lncursesw -o char-putting

main.o: main.c game.h menuchooser.h ui.h about.h leaderboard.h about.h
ui.o: ui.c ui.h
menuchooser.o: menuchooser.c menuchooser.h
leaderboard.o: leaderboard.c leaderboard.h ui.h
gmae.o: game.c game.h ui.h record.h
about.o: about.c about.h ui.h
record.o: record.c record.h ui.h
Make_compile-info.o:
	gcc -c -o compile-info.o compile-info.c

.PHONY: clean ALL compile-info.o

clean:
	-rm -rf $(OBJ) char-putting
