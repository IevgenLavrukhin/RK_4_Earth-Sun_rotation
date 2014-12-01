all: compile1 compile2 link clean 

compile1: 
	gcc -Wall -std=c99 elimination.c  -o elimination.o -c 
compile2:
	gcc -Wall -std=c99  main.c -o main.o -c
link:
	gcc -Wall -std=c99   main.o elimination.o -o run

clean:
	rm -f *.o

