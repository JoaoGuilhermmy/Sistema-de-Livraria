#include <stdlib.h>
#include <stdio.h>
#include "bst.h"
#include "file_parser.h"
#include "max_heap.h"

int main()
{

    Maxheap *Maxheap = create_maxheap(10);

    Book book1 = {123, "Book One", "Author A", 2020, 29.99, 100, 50};
    Book book2 = {456, "Book Two", "Author B", 2019, 19.99, 150, 75};
    Book book3 = {789, "Book Three", "Author C", 2021, 39.99, 200, 30};

    insert_heap(Maxheap, book1);
    insert_heap(Maxheap, book2);
    insert_heap(Maxheap, book3);

    print_heap(Maxheap);

    return 0;
}