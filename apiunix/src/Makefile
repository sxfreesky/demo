all: main clean

main:main.o demo_3_1.o
	cc -o main main.o demo_3_1.o

main.o: main.c
	cc -c main.c

demo_3_1.o: demo_3_1.c demo.h
	cc -c demo_3_1.c

clean:
	rm *.o
