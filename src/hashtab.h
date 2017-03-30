#ifndef HASHTAB_H
#define HASHTAB_H

typedef struct listnode_s ListNode;
typedef ListNode** HashTab;
struct listnode_s{
	char *key;
	int value;
	ListNode *next;
};

void hashtab_init(HashTab _ht);
void hashtab_add(HashTab _ht, char *_key, int _val);
ListNode hashtab_lookup(HashTab _ht, char *_key);
void hashtab_delete(HashTab _ht, char *_key);
void hashtab_print(HashTab _ht);
void hashtab_free(HashTab _ht);

#endif