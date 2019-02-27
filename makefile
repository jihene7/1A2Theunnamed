p:men.o
	gcc men.o -o p -lSDL -lSDL_image -lSDL_mixer 
men.o:men.c
	gcc -c men.c -lSDL -lSDL_image -lSDL_mixer

