all: main

main: main.o generatesignal.o transformsignal.o global.o
		gcc main.o generatesignal.o transformsignal.o global.o -o main -lm -lfftw3 -lpthread

main.o: main.c global.c
		gcc -c main.c

generatesignal.o: generatesignal.c global.c
		gcc -c generatesignal.c

transformsignal.o: transformsignal.c global.c
		gcc -c transformsignal.c

global.o: global.c
		gcc -c global.c
clean:
		rm -rf *.o main
