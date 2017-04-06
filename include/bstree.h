#ifndef BSTREE_H
#define BSTREE_H

#include <stdlib.h>
#include <stdio.h>

/*BSTree*/
struct BSTree{
	char *key;
	int value;
	struct BSTree *childs[2];
	size_t height;
};

struct BSTree *bstree_create(char *_key, int _value);
void bstree_free(struct BSTree *_tree);
void bstree_print(struct BSTree *_tree);
struct BSTree *bstree_add(struct BSTree *_tree, char *_key, int _value);
struct BSTree *bstree_lookup(struct BSTree *_tree, char *_key);
struct BSTree *bstree_min(struct BSTree *_tree);
struct BSTree *bstree_max(struct BSTree *_tree);
struct BSTree *bstree_delete(struct BSTree *_tree, char *_key);

#endif