#include "hash_table.h"

static bucket_t table[table_size];

static hash(key);

hash_table_init()
{
	int i;
	for (i = 0; i < table_size; i++)
		table[i].status = available;
}

static hash(key)
int key;
{
	return key / table_size;
}

hash_store(key, auth)
int key;
const char* auth;
{
	size_t len;
	int index;
	index = hash(key);
	switch (table[index].status)
	{
		case available :
			len = strlen(auth);
			strcpy(table[index].author, auth);
			table[index].author[len] = 0;
			table[index].key = key;
			table[index].status = unavailable;
			break;
		case unavailable :
			index++;
			len = strlen(auth);
			strcpy(table[index].author, auth);
			table[index].author[len] = 0;
			table[index].key = key;
			table[index].status = unavailable;
			break;
	}
}
