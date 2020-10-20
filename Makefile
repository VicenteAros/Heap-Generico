output: main.o heap.o
    gcc main.o heap.o -o output

main.o: main.c heap.h
    gcc -c main.c

heap.o: heap.c heap.h
    gcc -c heap.c

clear:
    rm *.o output
