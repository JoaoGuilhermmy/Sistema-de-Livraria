#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_parser.h"

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