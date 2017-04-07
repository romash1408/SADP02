#include "hashfunc.h"

static const unsigned int maxVal = 15;
static unsigned int func(const char* key)
{
	unsigned int ret = 0;
	while(*key) ret += *key++;
	return ret % maxVal;
}
static HashFunc ret;

HashFunc *HashSimpleLib()
{
	ret.maxVal = maxVal;
	ret.func = &func;
	return &ret;
}