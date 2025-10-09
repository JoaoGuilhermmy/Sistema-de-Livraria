#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include "bst.h"

CategoryNode *load_categories_file(const char *filename);
Maxheap *load_books_file(const char *filename);

#endif