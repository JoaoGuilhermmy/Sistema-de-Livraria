#ifndef MAX_HEAP_H
#define MAX_HEAP_H
#include "models.h"

typedef struct MaxHeap
{
    Book *books;
    int size;
    int capacity;
} MaxHeap;

MaxHeap *create_heap(int capacity);
void insert_heap(MaxHeap *heap, Book book);
void print_heap(MaxHeap *heap);
void consult_top_one(MaxHeap *heap);
void heapify_down(MaxHeap *heap, int index);
void list_top_n(MaxHeap *heap, int n);
void register_sale(MaxHeap *heap, int isbn, int quantity);
void free_heap(MaxHeap *heap);

#endif