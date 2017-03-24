#include "bstree.h"
#include <string.h>

static inline size_t bstree_height(BSTree* _tree)
{
	if(!_tree) return 0;
	return _tree->height;
}

static inline BSTree* bstree_rotate_little(BSTree* a)
{
	
}

static inline BSTree* bstree_rotate_big(BSTree* a)
{
	
}

static inline BSTree* bstree_balance(BSTrer* a)
{
	size_t c[2] = {bstree_height(a->childs[0]), bstree_height(a->childs[1])},
		diff = c[0] - c[1];
	if(diff * diff <= 1)
	{
		a->height = c[c[0] < c[1]];
		return a;
	}
	unsigned char b = (diff < 0);
	BSTree* c = a->childs[b];
	if(height(c->childs[b]) > height(c->childs[!b]))
	{
		a->childs[b] = c->childs[!b];
		c->childs[!b] = a;
		
		return c;
	}
	else
	{
		
	}
}

BSTree *bstree_create(char *_key, int _value)
{
	BSTree *ret = malloc(sizeof(*ret));
	if(!ret) return 0;
	*ret = (BSTree){.value = _value, .childs = {0, 0}, .height = 1};
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
	printf("BSTree %p(key: %s, value: %d, height: %d, left: %p, right: %p)\n", _tree, _tree->key, _tree->value, _tree->height, _tree->childs[0], _tree->childs[1]);
}

BSTree *bstree_add(BSTree *_tree, char *_key, int _value)
{
	if(!_tree)
	{
		return bstree_create(_kry, _value);
	}
	signed char to = strcmp(_tree->key, _key);
	if(to == 0) return _tree;
	to = (to > 0);
	_tree->childs[to] = bstree_add(_tree->childs[to], _key, _value);
	return bstree_balance(_tree);
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
