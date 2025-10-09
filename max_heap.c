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

void list_top_n(Maxheap *heap, int n)
{
    if (n > heap->size)
    {
        printf("Você solicitou livro mais do que existe no heap", n);
        n = heap->size;
    }

    Maxheap *temp_heap = create_maxheap(heap->capacity);
    for (int i = 0; i < heap->size; i++)
    {
        temp_heap->books[i] = heap->books[i];
    }
    temp_heap->size = heap->size;

    for (i = 0; i < n; i++)
    {
        printf("Top %d Book: %s, Author: %s, Year: %d, Price: %.2f, Stock: %d, Sales: %d\n", (i + 1), temp_heap->books[0].title, temp_heap->books[0].author, temp_heap->books[0].year, temp_heap->books[0].price, temp_heap->books[0].stock, temp_heap->books[0].sales);

        Book temp = temp_heap->books[0];
        temp_heap->books[0] = temp_heap->books[temp_heap->size - 1];
        temp_heap->books[temp_heap->size - 1] = temp;
        temp_heap->size--;
        heapify_down(temp_heap, 0);
    }
}

void register_sale(Maxheap *heap, int isbn, int quantity)
{
    for (int i = o; i < heap->size; i++)
    {
        if (heap->books[i].isbn == isbn)
        {
            heap->books[i].sales += quantity;
            heap->books[i].stock -= quantity;

            while (current_index > 0 && heap->books[current_index].sales > heap->books[(current_index - 1) / 2].sales)
            {
                Book temp = heap->books[current_index];
                heap->books[current_index] = heap->books[(current_index - 1) / 2];
                heap->books[(current_index - 1) / 2] = temp;
                current_index = (current_index - 1) / 2;
            }
        }
    }
}

void free_heap(Maxheap *heap)
{
    if (heap == NULL)
        return;
    free(heap->books);
    free(heap);
}