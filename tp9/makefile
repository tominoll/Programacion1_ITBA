main: main.o args.o
	gcc main.o args.o -o tp9 -Wall
main.o: main.c args.h
	gcc main.c -c -Wall
args.o: args.c args.h
	gcc args.c -c -Wall
clean:
	rm *.o