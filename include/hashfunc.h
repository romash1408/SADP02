typedef struct hashfunc_s HashFunc;
struct hashfunc_s{
	unsigned int (*func)(const char* _key);
	unsigned int maxVal;
};