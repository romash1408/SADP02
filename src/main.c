#include <stdio.h>
#include "bstree.h"

const int N = 16;

int main()
{
	int i = 0;
	char s[10];
	scanf("%s", s);
	struct BSTree *tmp = bstree_create(s, i);
	bstree_print(tmp);
	
	for(i = 1; i <= N; ++i)
	{
		scanf("%s", s);
		tmp = bstree_add(tmp, s, i);
		bstree_print(tmp);
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