#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int empty_tree(TNo *t)
{
    if(t == NULL)
        return 1;
    return 0;
}

TNo *insert_tree(TNo *t, void *elem, int (*comp)())
{
    int result_comp;

    if(empty_tree(t))
    {
        TNo *no   = (TNo*)malloc(sizeof(TNo));
        no->elem  = elem;
        no->left  = NULL;
        no->right = NULL;

        return no;
    }
    else
    {
        result_comp = comp(t->elem,elem);

        if(result_comp == 1)
        {
            t->right = insert_tree(t->right,elem,comp);
        }
        else if(result_comp == -1)
        {
            t->left = insert_tree(t->left,elem,comp);
        }
        return t;
    }
}

/*
*  Uma forma de percorrer a árvore por completo,
*  do menor para o maior elemento.
*/
void print_tree(TNo *t, void (*print)())
{
    if(!empty_tree(t))
    {
        print_tree(t->left,print);
        print(t->elem);
        print_tree(t->right,print);
    }
}

/*
*  Para retornar o elemento (void *) basta modificar
*  o tipo da função e também o "return" quando encontrar
*  o elemento buscado.
*/
TNo *search_tree( TNo *t, void *elem, int (*comp)() )
{
    if(!empty_tree(t))
    {
        if(comp(t->elem,elem) == 2)
        {
            return t;
        }
        else
        {
            if(comp(t->elem,elem) == 1)
                return search_tree(t->right, elem, comp);

            else if(comp(t->elem,elem) == -1)
                return search_tree(t->left,  elem, comp);
        }
    }
    return NULL;

}
/*
* Percorre todos os nós da
* arvore e conta cada um deles.
*/
int count_node_tree( TNo *t)
{
    int count = 0;
    if(!empty_tree(t))
    {
        count += count_node_tree(t->left);
        count++;
        count += count_node_tree(t->right);
        return count;
    }
    return 0;
}

/*
* Percorre todos os nós da
* arvore e conta suas alturas.
* O ramo ou galho que tiver a
* altura maior, será retornado.
*/
int find_height_tree( TNo *t )
{
    int height_left;
    int height_right;

    if(!empty_tree(t))
    {
        if(t->left == NULL && t->right == NULL)
            return 0;

        else
        {
            height_left  = 1 + find_height_tree(t->left);
            height_right = 1 + find_height_tree(t->right);

            if(height_left > height_right)
                return height_left;

            else
                return height_right;
        }
    }
    return 0;

}





