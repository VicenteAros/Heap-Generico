#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdio.h>
#include <stdlib.h>

typedef void* tipoElem;

typedef struct{
	tipoElem* heap;
	
	int capacity;
	int nElems;
	int error;
}tHeap;

tHeap* newHeap();
void deleteHeap(tHeap* h);

void clearHeap(tHeap* h);
void* topHeap(tHeap* h);
int sizeHeap(tHeap* h);
void popHeap(tHeap* h);
void pushHeap(tHeap* h, tipoElem elem);
int is_goodHeap(tHeap* h);
int emptyHeap(tHeap* h);

void printHeap(tHeap* h);


#endif
