#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	void **heap;
	
	void (*printElem)(void* a);
	int (*comparador)(void* a, void* b);
	int nElems;
	int size;
	int error;
}tHeap;

tHeap* newHeap(int (*comparador)(void*, void*), void (*printElem)(void*));

void deleteHeap(tHeap* h);

void clearHeap(tHeap* h);
void topHeap(tHeap* h);
int sizeHeap(tHeap* h);
void popHeap(tHeap* h);
void pushHeap(tHeap* h, void* elem);
int is_goodHeap(tHeap* h);
int emptyHeap(tHeap* h);

void printHeap(tHeap* h);


#endif
