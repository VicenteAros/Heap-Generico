#include "heap.h"

tHeap* newHeap(int (*comparador)(void*, void*), void (*printElem)(void*)){
    tHeap* h = (tHeap*)malloc(sizeof(tHeap));
    if(h == NULL){
        return NULL;
    }
    
    h->printElem=printElem;
    h->comparador=comparador;
    h->error = 0;
    h->size = 1;
    h->nElems = 0;
    h->heap = malloc(sizeof(void*)*(h->size+1));
    if(h->heap == NULL) h->error = 1;

    return h;
}

void deleteHeap(tHeap* h){
    free(h->heap);
    free(h);
    return;
}

void growHeap(tHeap* h){
    h->size *= 2;
    void* temp = realloc(h->heap, sizeof(void*)*(h->size+1));
    if(temp == NULL){
        h->error = 1;
        return;
    }
    h->heap = temp;
    return;
}

void clearHeap(tHeap* h){
    h->nElems = 0;
    return;
}

void* topHeap(tHeap* h){
    h->printElem(h->heap[1]);
}

int sizeHeap(tHeap* h){
    return h->nElems;
}

int emptyHeap(tHeap* h){
    return !(h->nElems > 0);
}

int is_goodHeap(tHeap* h){
    return !h->error;
}

void swapElemsHeap(tHeap* h, int i, int j){
    void* tmp = h->heap[i];
    h->heap[i] = h->heap[j];
    h->heap[j] = tmp;
    return;
}

void pushHeap(tHeap* h, void* elem){
    int i = h->nElems+1;
    if(i > h->size){
        growHeap(h);
        if(!is_goodHeap(h)){
            printf("Error al expandir la memoria del heap\n");
            return;
        }
    }
    h->heap[i] = elem;
    while (i > 1) {
        int j = i/2;
        if (h->comparador(h->heap[i], h->heap[j])>0) {
            swapElemsHeap(h, i, j);
        }
        i = j;
    }
    h->nElems++;
}

void popHeap(tHeap* h){
    int i = 1;
    h->heap[i] = h->heap[h->nElems];
    h->nElems--;
    while (2*i <= h->nElems) {
        int izq = 2*i;
        int der = 2*i + 1;

        if (der > h->nElems || h->comparador(h->heap[izq] , h->heap[der])>0) {
            if (h->comparador(h->heap[izq] , h->heap[i])<0) break;

            swapElemsHeap(h, i, izq);
            i = izq;
        }
        else {
            if (h->comparador(h->heap[der] , h->heap[i])<0) break;

            swapElemsHeap(h, i, der);
            i = der;
        }
    }
}

void printHeap(tHeap* h){
    printf("Heap:\n");
    printf("\tCapacidad: %d\n\tnElems: %d\n", h->size, h->nElems);
    printf("\telems: [");
    for(int i = 1; i < h->nElems; i++) h->printElem(h->heap[i]);
    if (h->nElems > 0) printf("%d", h->heap[h->nElems]);
    printf("]\n");
    return;
}
