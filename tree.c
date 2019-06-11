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
        else if(result_comp == 2)
        {
            t->left = insert_tree(t->left,elem,comp);
        }
        return t;
    }



}

