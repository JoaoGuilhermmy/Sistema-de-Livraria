#include <stdlib.h>
#include <stdio.h>
#include "bst.h"
#include "file_parser.h"

int main()
{
    CategoryNode *categories = load_categories_file("categories.csv");
    if (categories == NULL)
    {
        fprintf(stderr, "Falha ao tentar carregar os arquivos\n");
        return EXIT_FAILURE;
    }

    printf("------ Lista de categorias -------");
    in_ordem_trasversal(categories);
    printf("\n----------------------------------\n");

    return 0;
}