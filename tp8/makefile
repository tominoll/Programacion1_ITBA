main: main.o juego.o get_number.o random.o
	gcc main.o juego.o get_number.o random.o -o life -Wall
main.o: main.c juego.h
	gcc main.c -c -Wall
juego.o: juego.c juego.h get_number.h random.h config.h 
	gcc juego.c -c -Wall
random.o: random.c random.h config.h
	gcc random.c -c -Wall
get_number.o: get_number.c get_number.h
	gcc get_number.c -c -Wall
clean:
	rm *.o
