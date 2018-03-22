all: onemax
main.o: OneMax.c define.h
	gcc -c OneMax.c -o main.o

functions.o: functions.c define.h
	gcc -c functions.c -o functions.o

onemax: main.o functions.o
	gcc main.o functions.o -o onemax
	rm -f *.o 

clean: 
	rm -f onemax