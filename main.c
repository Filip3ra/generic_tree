#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void free_elem(void *elem)
{
    free(elem);
}

int comp(int *a, int *b)
{
    if(*a < *b)
        return 1;
    else if(a > b)
        return -1;
    else
        return 3;
}

int main(int argc, char *argv[]){

    TNo *tree = NULL; /* inicializar a arvore! */
    int *number;

    argc = argc;
    argv[1] = " [OK] ";
    printf("%s\n",argv[1]);



     number = (int*)malloc(sizeof(int));
    *number = 7;
    tree = insert_tree(tree,number,&comp);

    free_elem(number);
    free(tree);

    return 0;
}
