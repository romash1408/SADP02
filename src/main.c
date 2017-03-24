#include <stdio.h>
#include "bstree.h"

const int N = 2;

int main()
{
	struct BSTree *tmp = bstree_create("0", 0);
	for(int i = 0; i < N; ++i)
	{
		char key[3];
		sprintf(key, "%d", i);
		tmp = bstree_add(tmp, key, i);
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