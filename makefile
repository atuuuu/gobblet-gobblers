choco install makemain : main.o mes_fonctions.o mes_fonctions_SDL.o mon_board.o Secure_SDL.o mes_fonctions_son.o
	gcc main.o mes_fonctions.o mes_fonctions_SDL.o mon_board.o Secure_SDL.o mes_fonctions_son.o -o main -lmingw32 -lSDL2main -lSDL2 -lSDL2_mixer -Wall

main.o : main.c mes_fonctions.c mes_fonctions_SDL.c Secure_SDL.c
	gcc main.c mes_fonctions.c mes_fonctions_SDL.c Secure_SDL.c -c -lmingw32 -lSDL2main -lSDL2

mes_fonctions.o : mes_fonctions.c mon_board.c mes_fonctions.h
	gcc mes_fonctions.c mon_board.c -c

mes_fonctions_SDL.o : mes_fonctions_SDL.c mes_fonctions.c Secure_SDL.c mes_fonctions_SDL.h
	gcc mes_fonctions.c mes_fonctions_SDL.c Secure_SDL.c -c -lmingw32 -lSDL2main -lSDL2

mes_fonctions_son.o : mes_fonctions_son.c mes_fonctions_son.h
	gcc mes_fonctions_son.c -c -lSDL2_mixer -Wall

mon_board.o : mon_board.c mon_board.h
	gcc mon_board.c -c -Wall

Secure_SDL.o : Secure_SDL.c Secure_SDL.h
	gcc Secure_SDL.c -c -lmingw32 -lSDL2main -lSDL2 -Wall

clean :
	rm *.o -rf
