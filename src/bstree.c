#include "bstree.h"
#include <string.h>

BSTree *bstree_create(char *_key, int _value)
{
	BSTree *ret = malloc(sizeof(*ret));
	if(!ret) return 0;
	*ret = (BSTree){.value = _value, .parent = 0, .left = 0, .right = 0};
	size_t len = strlen(_key);
	ret->key = malloc(len * sizeof(*_key) + 1);
	if(!ret->key)
	{
		free(ret);
		return 0;
	}
	strcpy(ret->key, _key);
	return ret;
}

void bstree_free(BSTree *_tree)
{
	if(!_tree) return;
	if(_tree->key) free(_tree->key);
	free(_tree);
}

void bstree_print(BSTree *_tree)
{
	printf("BSTree %p(key: %s, value: %d, parent: %p, left: %p, right: %p)\n", _tree, _tree->key, _tree->value, _tree->parent, _tree->left, _tree->right);
}

void bstree_add(BSTree *_tree, char *_key, int _value)
{
	
}

BSTree *bstree_lookup(BSTree *_tree, char *_key)
{
	return 0;
}

BSTree *bstree_min(BSTree *_tree)
{
	return 0;
}

BSTree *bstree_max(BSTree *_tree)
{
	return 0;
}
