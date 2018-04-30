all: ES

main.o: ES.c functions.h
	gcc -c ES.c -o main.o

functions.o: functions.c functions.h
	gcc -c functions.c -o functions.o

ES: main.o functions.o
	gcc main.o functions.o -o ES
	rm -f *.o

clean: 
	rm -f onemax 