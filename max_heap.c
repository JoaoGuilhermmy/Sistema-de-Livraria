#include "max_heap.h"
#include <stdlib.h>
#include <stdio.h>

Maxheap *create_maxheap(int capacity)
{
    Maxheap *heap = (Maxheap *)malloc(sizeof(Maxheap));
    heap->books = (Book *)malloc(sizeof(Book) * capacity);
    heap->capacity = capacity;
    heap->size = 0;

    return heap;
}

void insert_heap(Maxheap *heap, Book book)
{
    if (heap->size == heap->capacity)
    {
        printf("Heap cheio\n");
        EXIT(EXIT_FAILURE);
    }
    heap->books[heap->size] = book;
    heap->size++;
}