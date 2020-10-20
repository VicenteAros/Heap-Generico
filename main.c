#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int cmpString(void* a, void* b){
	char* str1=(*(char*)(a));
	char* str2=(*(char*)(b));
	return(strcmp(str1,str2));
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
	return(nmb1-nmb2);
}

void printFlotante(void* a){
	float nmb=(*(float*)(a));
	printf("%f\n",nmb);
}

int cmpArreglo(void* a, void* b){
	int* array1= (*(int**)(a));
	int* array2= (*(int**)(b));
	int sum1=0;
	int sum2=0;
	int i;
	for(i=0; i<aSize; i++){
		sum1+=array1[i];
	}
	for(i=0; i<bSize; i++){
		sum2+=array2[i];
	}
	//menor
	return(sum1-sum2);
}

void printArreglo(void* a, int aSize){
	int* array= (*(int**)(a));
	int i;
	for(i=0; i<aSize; i++){
		printf("%d ",array[i]);
	}
	printf("\n");
}

void heapSort(void** arr, int N, int (*comparador)(void*, void*), void (*printElem)(void*)){
}

typedef struct{
	int base;
	char* numero;
}tBase;

void maxBases(tBase* arr, int N, int CantidadDeMaximos){
}

int main(){
	//do something
	
	return 0;
}
