#ifndef MODELS_H
#define MODELS_H

typedef struct Book
{
    int isbn;
    char title[100];
    char author[100];
    int year;
    double price;
    int stock;
    int sales;

} Book;

typedef struct CategoryNode
{
    int id;
    char category_name[100];
    char books_file[100];
    struct CategoryNode *left;
    struct CategoryNode *right;
} CategoryNode;

#endif