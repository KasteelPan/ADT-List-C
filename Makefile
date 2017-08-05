#The makefile of list program
objects = main.o list.o

main.out:$(objects)
	gcc $(objects) -o main.out
main.o:main.c list.h
	gcc -c main.c -o main.o
list.o:list.c list.h
	gcc -c list.c -o list.o
clean:
	rm -rf $(objects)