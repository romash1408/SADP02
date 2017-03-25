#include <stdio.h>
#include "bstree.h"

const int N = 32;

int main()
{
	/*struct BSTree *tmp = bstree_create("а", 0);
	bstree_print(tmp);
	
	for(int i = 1; i <= N; ++i)
	{
		char key[3];
		key[0] = "а"[0] + i / 16;
		key[1] = "а"[1] + i % 16;
		tmp = bstree_add(tmp, key, i);
		printf("Added %s (%d)!\n", key, i);
	}
	if(!tmp)
	{
		fprintf(stderr, "Coudn't create BSTree.\n");
		return 1;
	}
	bstree_print(tmp);
	bstree_free(tmp);*/
	
	char *s = "а";
	for(int i = 0; i < sizeof(s); ++i)
	{
		printf("%d ", s[i]);
	}
	printf("\n");
	
	s = "п";
	for(int i = 0; i < sizeof(s); ++i)
	{
		printf("%d ", s[i]);
	}
	printf("\n");
	
	s = "р";
	for(int i = 0; i < sizeof(s); ++i)
	{
		printf("%d ", s[i]);
	}
	printf("\n");
	
	s = "я";
	for(int i = 0; i < sizeof(s); ++i)
	{
		printf("%d ", s[i]);
	}
	printf("\n");
	return 0;
}