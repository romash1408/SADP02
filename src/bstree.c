#include "bstree.h"
#include <string.h>

static inline size_t bstree_height(struct BSTree* _tree)
{
	if(!_tree) return 0;
	return _tree->height;
}

static inline size_t max(size_t a, size_t b)
{
	if(a > b) return a;
	else return b;
}

#define bstree_calc_height(a) (a)->height = max(bstree_height((a)->childs[0]), bstree_height((a)->childs[1])) + 1

static inline struct BSTree *bstree_balance(struct BSTree* a)
{
	signed char diff = bstree_height(a->childs[0]) - bstree_height(a->childs[1]);
	if(diff * diff <= 1)
	{
		bstree_calc_height(a);
		return a;
	}
	unsigned char b = (diff < 0);
	struct BSTree* c = a->childs[b];
	if(bstree_height(c->childs[b]) > bstree_height(c->childs[!b]))
	{
		a->childs[b] = c->childs[!b];
		bstree_calc_height(a);
		c->childs[!b] = a;
		bstree_calc_height(c);
		return c;
	}
	else
	{
		struct BSTree* d = c->childs[!b];
		c->childs[!b] = d->childs[b];
		bstree_calc_height(c);
		a->childs[b] = d->childs[!b];
		bstree_calc_height(a);
		d->childs[b] = c;
		d->childs[!b] = a;
		bstree_calc_height(d);
		return d;
	}
}

struct BSTree *bstree_create(char *_key, int _value)
{
	struct BSTree *ret = malloc(sizeof(*ret));
	if(!ret) return 0;
	*ret = (struct BSTree){.value = _value, .childs = {0, 0}, .height = 1};
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

void bstree_free(struct BSTree *_tree)
{
	if(!_tree) return;
	if(_tree->key) free(_tree->key);
	bstree_free(_tree->childs[0]);
	bstree_free(_tree->childs[1]);
	free(_tree);
}

struct BSTree *bstree_add(struct BSTree *_tree, char *_key, int _value)
{
	if(!_tree)
	{
		return bstree_create(_key, _value);
	}
	int to = strcmp(_tree->key, _key);
	if(to == 0) return _tree;
	to = (to < 0);
	_tree->childs[to] = bstree_add(_tree->childs[to], _key, _value);
	return bstree_balance(_tree);
}

void bstree_print(struct BSTree *_tree)
{
	if(!_tree)
	{
		printf("<0>\n");
		return;
	}
	size_t max_length = 1 << _tree->height;
	struct BSTree **old_trees = malloc(sizeof(*old_trees) * max_length);
	if(!old_trees) return;
	struct BSTree **next_trees = malloc(sizeof(*next_trees) * max_length);
	if(!next_trees)
	{
		free(old_trees);
		return;
	}
	next_trees[0] = _tree;
	size_t old, next = 1, count = 1;
	while(count > 0)
	{
		count = 0;
		old = next;
		next = 0;
		struct BSTree **tmp = old_trees;
		old_trees = next_trees;
		next_trees = tmp;
		
		for(size_t i = 0; i < old; ++i)
		{
			char out[8];
			if(old_trees[i] == 0)
			{
				sprintf(out, "<0>");
				next_trees[next++] = 0;
				next_trees[next++] = 0;
			}
			else
			{
				sprintf(out, "%s(%u)", old_trees[i]->key, old_trees[i]->height);
				if((next_trees[next++] = old_trees[i]->childs[0])) ++count;
				if((next_trees[next++] = old_trees[i]->childs[1])) ++count;
			}
			if(out[7] != 0)
			{
				out[6] = '~';
				out[7] = 0;
			}
			printf("%7s ", out);
		}
		printf("\n");
	}
	free(old_trees);
	free(next_trees);
}

struct BSTree *bstree_lookup(struct BSTree *_tree, char *_key)
{
	int to;
	while(_tree && (to = strcmp(_tree->key, _key)) != 0)
	{
		_tree = _tree->childs[to < 0];
	}
	return _tree;
}

struct BSTree *bstree_min(struct BSTree *_tree)
{
	if(!_tree) return 0;
	while(_tree->childs[0]) _tree = _tree->childs[0];
	return _tree;
	return 0;
}

struct BSTree *bstree_max(struct BSTree *_tree)
{
	if(!_tree) return 0;
	while(_tree->childs[1]) _tree = _tree->childs[1];
	return _tree;
	return 0;
}

struct BSTree *bstree_delete(struct BSTree *_tree, char *_key)
{
	if(!_tree) return 0;
	int to = strcmp(_tree->key, _key);
	if(to != 0)
	{
		to = (to < 0);
		_tree->childs[to] = bstree_delete(_tree->childs[to], _key);
		return bstree_balance(_tree);
	}
	to = (bstree_height(_tree->childs[0]) < bstree_height(_tree->childs[1]));
	if(!_tree->childs[to])
	{
		bstree_free(_tree);
		return 0;
	}
	struct BSTree *ret = _tree->childs[to], *up = 0, *down;
	while((down = ret->childs[!to]))
	{
		ret->childs[!to] = up;
		up = ret;
		ret = down;
	}
	down = ret->childs[to];
	ret->childs[!to] = _tree->childs[!to];
	_tree->childs[0] = 0;
	_tree->childs[1] = 0;
	bstree_free(_tree);
	
	if(!(_tree = up)) return ret;
	while((up = _tree->childs[!to]))
	{
		_tree->childs[!to] = down;
		down = bstree_balance(_tree);
		_tree = up;
	}
	_tree->childs[!to] = down;
	ret->childs[to] = bstree_balance(_tree);
	bstree_calc_height(ret);
	return ret;
}