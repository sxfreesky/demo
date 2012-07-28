all: main clean

main:main.o 03_1.o
	cc -o main main.o 03_1.o

main.o: main.c
	cc -c main.c

03_1.o: 03_1.c demo.h
	cc -c 03_1.c

clean:
	rm *.o
