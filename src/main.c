#include <stdio.h>
#include "bstree.h"

int main()
{
	int i = 0;
	char s[10], c;
	scanf("%s", s);
	struct BSTree *tmp = bstree_create(s, i);
	if(!tmp)
	{
		fprintf(stderr, "Coudn't create BSTree.\n");
		return 1;
	}
	bstree_print(tmp);
	
	while(1)
	{
		++i;
		scanf("\n%c %c", &c, s);
		if(c == 'q') break;
		switch(c)
		{
		case 'a':
			tmp = bstree_add(tmp, s, i);
			break;
		case 'd':
			tmp = bstree_delete(tmp, s);
			break;
		case 'f':
			tmp = bstree_lookup(tmp, s);
			if(tmp)
				printf("Found %d\n", tmp->value);
			else
				printf("Didn't found\n");
		}
		bstree_print(tmp);
	}
	bstree_print(tmp);
	bstree_free(tmp);
	return 0;
}