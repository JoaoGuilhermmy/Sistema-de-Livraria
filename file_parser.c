#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_parser.h"
#include "max_heap.h"

CategoryNode *load_categories_file(const char *filename)
{

    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo de categorias");
        return NULL;
    }

    printf("Arquivo '%s' aberto com sucesso.\n", filename);

    CategoryNode *tree_root = NULL;

    char line_buffer[256];

    while (fgets(line_buffer, sizeof(line_buffer), file))
    {

        char *token = strtok(line_buffer, ";");
        int id = atoi(token);

        token = strtok(NULL, ";");
        char *name = token;

        token = strtok(NULL, ";\n");
        char *file_name = token;

        tree_root = insert_category_node(tree_root, id, name, file_name);
    }

    fclose(file);

    printf("Leitura do arquivo de categorias concluída.\n");

    return tree_root;
}

Maxheap *load_books_file(const char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo de categorias");
        return NULL;
    }

    char line_buffer[269];
    int row_count = 0;
    while (fgets(line_buffer, sizeof(line_buffer), file))
    {
        row_count++;
    }
    rewind(file);

    int capacity = row_count;
    Maxheap *heap = create_maxheap(capacity);

    while (fgets(line_buffer, sizeof(line_buffer), file))
    {
        Book book;
        char *receptor = strtok(line_buffer, ";");
        book.isbn = atoi(receptor);

        receptor = strtok(NULL, ";");
        strcpy(book.title, receptor);

        receptor = strtok(NULL, ";");
        strcpy(book.author, receptor);

        receptor = strtok(NULL, ";");
        book.year = atoi(receptor);

        receptor = strtok(NULL, ";");
        book.price = atof(receptor);

        receptor = strtok(NULL, ";");
        book.stock = atoi(receptor);

        receptor = strtok(NULL, ";");
        book.sales = atoi(receptor);

        insert_heap(heap, book);
    }

    return heap;
}