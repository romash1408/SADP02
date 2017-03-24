#ifndef BSTREE_H
#define BSTREE_H

#include <stdlib.h>
#include <stdio.h>

/*BSTree*/
typedef struct{
	char *key;
	int value;
	struct BSTree *childs[2];
	size_t height;
} BSTree;

BSTree *bstree_create(char *_key, int _value);
void bstree_free(BSTree *_tree);
void bstree_print(BSTree *_tree);
BSTree *bstree_add(BSTree *_tree, char *_key, int _value);
BSTree *bstree_lookup(BSTree *_tree, char *_key);
BSTree *bstree_min(BSTree *_tree);
BSTree *bstree_max(BSTree *_tree);

#endif