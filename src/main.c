#include <stdio.h>
#include "bstree.h"

const int N = 28;

int main()
{
	struct BSTree *tmp = bstree_create("a", 0);
	bstree_print(tmp);
	
	char key[2];
	key[1] = 0;
	for(int i = 1; i <= N; ++i)
	{
		key[0] = 'a' + i;
		tmp = bstree_add(tmp, key, i);
		printf("Added %s(%d)!\n", key, i);
	}
	if(!tmp)
	{
		fprintf(stderr, "Coudn't create BSTree.\n");
		return 1;
	}
	bstree_print(tmp);
	bstree_free(tmp);
	return 0;
}