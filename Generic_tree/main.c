/* 
 * File:   main.c
 * Author: Filipi
 *
 * Created on 5 de janeiro de 2022, 00:13
 */
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
    else if(*a > *b)
        return -1;
    else
        return 2;
}

void print(int *elem)
{
    printf("%i\n",*elem);
}

int main(){


    TNo *tree = NULL;
    int *number;
    int *lucky_number;



     number = (int*)malloc(sizeof(int));
    *number = 7;
    tree = insert_tree(tree,number,&comp);

     number = (int*)malloc(sizeof(int));
    *number = 2;
    tree = insert_tree(tree,number,&comp);

     number = (int*)malloc(sizeof(int));
    *number = 9;
    tree = insert_tree(tree,number,&comp);

     number = (int*)malloc(sizeof(int));
    *number = 8;
    tree = insert_tree(tree,number,&comp);

    number = (int*)malloc(sizeof(int));
    *number = 1;
    tree = insert_tree(tree,number,&comp);

    number = (int*)malloc(sizeof(int));
    *number = 3;
    tree = insert_tree(tree,number,&comp);

    number = (int*)malloc(sizeof(int));
    *number = 10;
    tree = insert_tree(tree,number,&comp);



     lucky_number = (int*)malloc(sizeof(int));
    *lucky_number = 9;



    print_tree(tree, &print);

    /* caso retorne um (void*)

    printf("searched value = ");
    print(search_tree(tree,lucky_number,&comp));
    */

    /* caso retorne um nó */
    printf("searched subtree = ");
    print_tree(search_tree(tree,lucky_number,&comp), &print);


    printf("number of nodes = %i\n",count_node_tree(tree));

    printf("height tree = %i\n",find_height_tree(tree));


    return 0;
}
