#ifndef HASHTAB_H
#define HASHTAB_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct listnode_s ListNode;
struct listnode_s{
	char *key;
	int value;
	ListNode *next;
};

typedef struct hashfunc_s HashFunc;
struct hashfunc_s{
	unsigned int (*func)(const char* _key);
	unsigned int maxVal;
};

ListNode** hashtab_init(char *_hf);
void hashtab_add(ListNode **_ht, char *_key, int _val);
ListNode* hashtab_lookup(ListNode **_ht, char *_key);
void hashtab_delete(ListNode **_ht, char *_key);
void hashtab_print(ListNode **_ht);
void hashtab_free(ListNode **_ht);

HashFunc *HASH_SIMPLE();

#endif