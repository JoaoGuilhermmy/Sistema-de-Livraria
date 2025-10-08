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
        return;
    }
    heap->books[heap->size] = book;
    heap->size++;

    int s = heap->size - 1;

    while (s > 0 && heap->books[s].sales > heap->books[(s - 1) / 2].sales)
    {
        Book temp = heap->books[s];
        heap->books[s] = heap->books[(s - 1) / 2];
        heap->books[(s - 1) / 2] = temp;
        s = (s - 1) / 2;
    }
}

void print_heap(Maxheap *heap)
{
    printf("-------------------------------\n");
    for (int i = 0; i < heap->size; i++)
    {
        printf("ISBN: %d, Title: %s, Author: %s, Year: %d, Price: %.2f, Stock: %d, Sales: %d\n",
               heap->books[i].isbn,
               heap->books[i].title,
               heap->books[i].author,
               heap->books[i].year,
               heap->books[i].price,
               heap->books[i].stock,
               heap->books[i].sales);
        printf("-------------------------------\n");
    }
}

void consult_top_one(Maxheap *heap)
{
    if (heap->size == 0)
    {
        printf("Heap vazio\n");
        return;
    }

    printf("Top 1 Book:\n");
    printf("Nome: %s\n , Autor: %s\n , Vendas: %d\n", heap->books[0].title, heap->books[0].author, heap->books[0].sales);
}


void heapify_down(Maxheap *heap, int index)
{
    int largest = index;
    int son_left = 2 * index + 1;
    int son_right = 2 * index + 2;

    if (son_left < heap->size && heap->books[son_left].sales > heap->books[largest].sales)
    {
        largest = son_left;
    }
    
    if (son_right < heap->size && heap->books[son_right].sales > heap->books[largest].sales)
    {
        largest = son_right;
    }

    if (largest != index)
    {
        Book temp = heap->books[index];
        heap->books[index] = heap->books[largest];
        heap->books[largest] = temp;
        heapify_down(heap, largest);
    }
}
