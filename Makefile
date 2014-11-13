all: compile1 compile2 link clean 

compile1: 
	gcc -Wall -std=c99 integrator.c  -o integrator.o -c 
compile2:
	gcc -Wall -std=c99  main.c -o main.o -c
link:
	gcc -Wall -std=c99   integrator.o main.o -o run

clean:
	rm -f *.o

