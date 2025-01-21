all: main

main: main.o generatesignal.o createarray.o transpose.o search.o
		gcc main.o generatesignal.o createarray.o transpose.o search.o -o main -lm -lpthread -lrt

main.o: main.c
		gcc -c main.c

generatesignal.o: generatesignal.c
		gcc -c generatesignal.c 

createarray.o: createarray.c 
		gcc -c createarray.c 

transformsignal.o: transpose.c 
		gcc -c transpose.c 

search.o: search.c 
		gcc -c search.c 

clean:
		rm -rf *.o main