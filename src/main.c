#include <stdio.h>
#include "bstree.h"
#include "hashtab.h"

int main()
{
	char s[10];
	ListNode** tmp = hashtab_init(0);
	if(!tmp)
	{
		fprintf(stderr, "Coudn't create ListNode.\n");
		return 1;
	}
	
	for(int i = 0; i <= N; ++i)
	{
		scanf("%s", s);
		hashtab_add(tmp, s, i);
		hashtab_print(tmp);
	}
	
	hashtab_free(tmp);
	return 0;
	
	/* BSTree
	int i = 0;
	char s[256], c;
	struct BSTree *tmp = 0, *fnd;
	
	while(1)
	{
		++i;
		scanf("\n%c %s", &c, s);
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
			fnd = bstree_lookup(tmp, s);
			if(fnd)
				printf("Found %s\n", fnd->key);
			else
				printf("Didn't found\n");
		}
		bstree_print(tmp);
	}=
	bstree_print(tmp);
	bstree_free(tmp);
	return 0;
	*/
}