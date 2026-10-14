all: lab5

lab5: main.o funcs.o
	gcc main.o funcs.o -o lab5 -lm

main.o: Source/main.c Header/funcs.h
	gcc -IHeader -c Source/main.c -o main.o

funcs.o: Source/funcs.c Header/funcs.h
	gcc -IHeader -c Source/funcs.c -o funcs.o

clean:
	rm -f *.o lab5 main.exe Source/main.exe