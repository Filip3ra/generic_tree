#ifndef TREE_H
#define TREE_H

typedef struct no TNo;
struct no
{
    void *elem;
    TNo  *left;
    TNo  *right;
};

TNo *search_tree( TNo *t, void *elem, int (*comp)() );
TNo *insert_tree( TNo *t, void *elem, int (*comp)() );
void  print_tree( TNo *t, void (*print)() );
int   empty_tree( TNo *t );
int find_height_tree( TNo *t );
int count_node_tree ( TNo *t );



#endif /* TREE_H */
