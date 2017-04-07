#include "hashtab.h"
#include <dlfcn.h>

#define GET_HF(_ht) ((HashFunc **)((char *)_ht - sizeof(HashFunc *)))

static HashFunc* hashtab_get_hashfunc(const char *const _name)
{
	do{
		if(strcmp(_name, "HASH_SIMPLE") == 0) break;
		char name[256];
		sprintf(name, "libs/%s.so" , _name);
		void *lib = dlopen(name, RTLD_LAZY);
		if(!lib) break;
		HashFunc* (*tmp)();
		if(!(tmp = dlsym(lib, _name))) break;
		return tmp();
	} while(0);
	return HASH_SIMPLE();
}

ListNode** hashtab_init(char *_hf)
{
	if(!_hf) _hf = "HASH_SIMPLE";
	HashFunc *hf = hashtab_get_hashfunc(_hf);
	char *ret = malloc(sizeof(HashFunc *) + hf->maxVal * sizeof(ListNode *));
	if(!ret) return 0;
	*((HashFunc **)ret) = hf;
	ret += sizeof(HashFunc *);
	memset(ret, 0, hf->maxVal * sizeof(ListNode *));
	return (ListNode **)ret;
}

void hashtab_add(ListNode **_ht, char *_key, int _val)
{
	HashFunc *hf = *GET_HF(_ht);
	ListNode **to = _ht + hf->func(_key);
	while(*to) to = &((*to)->next);
	*to = malloc(sizeof(ListNode));
	if(!*to) return;
	char *tmp = malloc(strlen(_key) + 1);
	if(!tmp)
	{
		free(*to);
		*to = 0;
		return;
	}
	strcpy(tmp, _key);
	**to = (ListNode){
		.key = tmp,
		.value = _val,
		.next = 0
	};
}

ListNode* hashtab_lookup(ListNode **_ht, char *_key)
{
	HashFunc *hf = *GET_HF(_ht);
	ListNode* ret = _ht[hf->func(_key)];
	while(ret && strcmp(ret->key, _key) != 0)
	{
		ret = ret->next;
	}
	return ret;
}

void hashtab_delete(ListNode **_ht, char *_key)
{
	HashFunc *hf = *GET_HF(_ht);
	ListNode **place = _ht + hf->func(_key), *del;
	while((del = *place))
	{
		if(strcmp(del->key, _key) == 0)
		{
			*place = del->next;
			free(del->key);
			free(del);
		}
		else
		{
			place = &del->next;
		}
	}
}


void hashtab_print(ListNode **_ht)
{
	HashFunc *hf = *GET_HF(_ht);
	for(unsigned int i = 0; i < hf->maxVal; ++i)
	{
		ListNode *next = _ht[i];
		if(!next) continue;
		printf("\t%d:", i);
		do{
			printf(" (\"%s\" -> %d)", next->key, next->value);
			next = next->next;
		}while(next);
		printf("\n");
	}
}

static void hashtab_free_nodes(ListNode *_node)
{
	if(!_node) return;
	hashtab_free_nodes(_node->next);
	free(_node->key);
	free(_node);
}

void hashtab_free(ListNode **_ht)
{
	HashFunc **hf = GET_HF(_ht);
	for(unsigned int i = 0; i < (*hf)->maxVal; ++i)
	{
		hashtab_free_nodes(_ht[i]);
	}
	free(hf);
}

static const unsigned int HASH_SIMPLE_M = 10;
static unsigned int HASH_SIMPLE_F(const char* key)
{
	unsigned int ret = 0;
	while(*key) ret += *key++;
	return ret % HASH_SIMPLE_M;
}
static HashFunc HASH_SIMPLE_B;

HashFunc *HASH_SIMPLE()
{
	HASH_SIMPLE_B.maxVal = HASH_SIMPLE_M;
	HASH_SIMPLE_B.func = &HASH_SIMPLE_F;
	return &HASH_SIMPLE_B;
}