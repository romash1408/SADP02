#include <stdio.h>
#include "bstree.h"

int main()
{
	BSTree *tmp = bstree_create("key", 123);
	if(!tmp)
	{
		fprintf(stderr, "Coudn't create BSTree.\n");
		return 1;
	}
	bstree_print(tmp);
	bstree_free(tmp);
	return 0;
}