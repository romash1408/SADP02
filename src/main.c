#include <stdio.h>
#include "bstree.h"
#include "hashtab.h"

int main()
{
	int i = 0;
	char s[256], c;
	struct BSTree *tree = 0, *tree_fnd;
	ListNode** tab = hashtab_init(0), *tab_fnd;
	if(!tab)
	{
		fprintf(stderr, "Coudn't create ListNode.\n");
		return 1;
	}
	
	
	while(1)
	{
		++i;
		scanf("\n%c", &c);
		if(c == 'q') break;
		if(c != 'p') scanf("%s", s);
		switch(c)
		{
		case 'a':
			tree = bstree_add(tree, s, i);
			hashtab_add(tab, s, i);
			break;
		case 'd':
			tree = bstree_delete(tree, s);
			hashtab_delete(tab, s);
			break;
		case 'f':
			tree_fnd = bstree_lookup(tree, s);
			if(tree_fnd)
				printf("BSTree found %s -> %d\n", tree_fnd->key, tree_fnd->value);
			else
				printf("BSTree didn't found\n");
			
			tab_fnd = hashtab_lookup(tab, s);
			if(tab_fnd)
				printf("HashTab found %s -> %d\n", tab_fnd->key, tab_fnd->value);
			else
				printf("HashTab didn't found\n");
			break;
		case 'p':
			printf("BSTree:\n");
			bstree_print(tree);
			printf("HashTab:\n");
			hashtab_print(tab);
			break;
		}
			
	}
	
	bstree_free(tree);
	hashtab_free(tab);
	return 0;
}