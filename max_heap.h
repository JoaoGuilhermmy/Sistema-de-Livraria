#ifndef MAX_HEAP_H
#define MAX_HEAP_H
#include "models.h"

typedef struct Maxheap
{
    Book *books;
    int size;
    int capacity;
} Maxheap;

Maxheap *create_maxheap(int capacity);
void insert_heap(Maxheap *heap, Book book);
void print_heap(Maxheap *heap);
void consult_top_one(Maxheap *heap);
void heapify_down(Maxheap *heap, int index);

#endif