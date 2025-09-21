#ifndef BSTREE_H
#define BSTREE_H

struct bstnode{
    struct bstnode* parent;
    struct bstnode* left;
    struct bstnode* right;
    int key;
    char value;
};


typedef struct{
    struct bstnode* root;
}BStree;



BStree *bstree_create();
void bstree_add(BStree *tree, int key, char value);
void bstree_transplant(BStree *T,struct bstnode *u, struct bstnode *v);
struct bstnode *bstree_lookup(BStree *tree, int key);
void bstree_delete(BStree *tree, int key);
struct bstnode *bstree_min(struct bstnode *node);
struct bstnode *bstree_max(struct bstnode *node);
void bstree_free(BStree *T);
void bst_recursion_free(struct bstnode *node);

#endif