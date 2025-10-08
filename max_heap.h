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

#endif