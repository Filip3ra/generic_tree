#ifndef TREE_H
#define TREE_H

typedef struct no TNo;
struct no
{
    void *elem;
    TNo  *left;
    TNo  *right;
};

TNo *insert_tree(TNo *t, void *elem, int (*comp)());
int empty_tree(TNo *t);

#endif /* TREE_H */
