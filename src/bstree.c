#include <bstree.h>
#include <stdlib.h>
#include <stdio.h>

BStree *bstree_create(){
    BStree *T = (BStree*)malloc(sizeof(*T));
    T->root = NULL;
    
    return T;
}

void bstree_add(BStree *T, int key, char value){
    struct bstnode *node = (struct bstnode*)malloc(sizeof(*node));
    
    node->key = key;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    struct bstnode *y = NULL;
    struct bstnode *x = T->root;
    while(x!=NULL){
        y=x;
        if(key<x->key) x = x->left;
        else x = x->right;
    }
    node->parent = y;
    if(y==NULL) T->root = node;
    else if(key<y->key) y->left = node;
    else y->right = node;
}

struct bstnode *bstree_lookup(BStree *tree, int key){
    struct bstnode *node = tree->root;
    while(node!=NULL && key!=node->key){
        if(key<node->key) node = node->left;
        else node = node->right;
    }
    return node;
}

struct bstnode *bstree_min(struct bstnode *node){
    while(node!=NULL){
        node = node->left;
    }
    return node;
}

struct bstnode *bstree_max(struct bstnode *node){
    while(node!=NULL){
        node = node->right;
    }
    return node;
}

void bstree_transplant(BStree *T,struct bstnode *u,struct bstnode *v){
    if(u->parent == NULL) T->root = v;
    else if(u == u->parent->left) u->parent->left = v;
    else u->parent->right = v;
    if(v!=NULL) v->parent = u->parent;
}

void bstree_delete(BStree *T, int key){
    struct bstnode *z = bstree_lookup(T, key);
    if(z->left == NULL) bstree_transplant(T,z,z->right);
    else if(z->right == NULL) bstree_transplant(T,z,z->left);
    else{
        struct bstnode *y = bstree_min(z->right);
        if(y->parent!=z){
            bstree_transplant(T,y,y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        bstree_transplant(T,z,y);
        y->left = z->left;
        y->left->parent = y;
    }
    free(z);

}

void bstree_free(BStree *T){
    bst_recursion_free(T->root);
    free(T);

}
void bst_recursion_free(struct bstnode *node){
    if(node == NULL) return;
    bst_recursion_free(node->left);
    bst_recursion_free(node->right);
    free(node);
}