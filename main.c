#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

int cmpString(void* a, void* b){
	char *a1= *(char**)a;
	char *b1= *(char**)b;
	return(strcmp(a1,b1));
}

void printString(void* a){
	char* str=(*(char*)(a));
	printf("%s\n",str);
}

int cmpEntero(void* a, void* b){
	int nmb1= (*(int*)(a));
	int nmb2= (*(int*)(b));
	//menor
	return(nmb1-nmb2);
}

void printEntero(void* a){
	int nmb=(*(int*)(a));
	printf("%d\n",nmb);
}

int cmpFlotante(void* a, void* b){
	float nmb1= (*(float*)(a));
	float nmb2= (*(float*)(b));
	//mayor
	return(nmb2-nmb1);
}

void printFlotante(void* a){
	float nmb=(*(float*)(a));
	printf("%f\n",nmb);
}

//posicion [0] dice el largo xd, habria sido bueno saberlo antes
int cmpArreglo(void* a, void* b){
	int* array1= (*(int**)(a));
	int* array2= (*(int**)(b));
	int sum1=0;
	int sum2=0;
	int i;
	for(i=1; i<array1[0]; i++){
		sum1+=array1[i];
	}
	for(i=1; i<array2[0]; i++){
		sum2+=array2[i];
	}
	//menor
	return(sum1-sum2);
}

void printArreglo(void* a){
	int* array= (*(int**)(a));
	int i;
	for(i=0; i<array[0]; i++){
		printf("%d ",array[i]);
	}
	printf("\n");
}

void heapSort(void** arr, int N, int (*comparador)(void*, void*), void (*printElem)(void*)){
	tHeap* HEAP=newHeap(comparador, printElem);
	int i;
	for(i=0; i<N; i++){
		pushHeap(HEAP, (void*)(arr[i]));
	}
	for(i=0; i<N; i++){
		topHeap(HEAP);
		popHeap(HEAP);
	}
	deleteHeap(HEAP);
}

typedef struct{
	int base;
	char* numero;
}tBase;

int cmpBases(void* a, void* b){
	tBase bba=(*(tBase*)a);
	tBase bbb=(*(tBase*)b);
	int maxA=bba->base;
	int maxB=bbb->base;
	return(maxB-maxA);
}

void printBases(void* a){
	tBase bb=(*(tBase*)a);
	printf("base: %d numero: %s", bb->base, bb->numero);
}

void maxBases(tBase* arr, int N, int CantidadDeMaximos){
	tHeap* HEAP=newHeap(cmpBases, printBases);
	int i;
	for(i=0; i<N; i++){
		pushHeap(HEAP, (void*)(arr[i]));
	}
	for(i=0; i<CantidadDeMaximos; i++){
		topHeap(HEAP);
		popHeap(HEAP);
	}
	deleteHeap(HEAP);
}

int main(){
	int A[5]={2,3,5,7,11};
	heapSort((void**) A, 5, cmpEntero, printEntero);
	
	return 0;
}
