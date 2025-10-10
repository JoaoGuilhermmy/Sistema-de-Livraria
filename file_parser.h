#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include "bst.h"
#include "max_heap.h"

CategoryNode *load_categories_file(const char *filename);
MaxHeap *load_books_file(const char *filename);

#endif