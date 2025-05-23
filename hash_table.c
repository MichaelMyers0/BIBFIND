#include "hash_table.h"

static bucket_t table[table_size];
static store_bucket(index, auth, key);

static store_bucket(index, auth, key)
int index;
const char* auth;
int key;
{
	size_t len;
	len = strlen(auth);
	strcpy(table[index].author, auth);
	table[index].author[len] = 0;
	table[index].key = key;
	table[index].status = unavailable;
}

hash_table_init()
{
	int i;
	for (i = 0; i < table_size; i++)
		table[i].status = available;
}

hash(key)
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
			store_bucket(index, auth, key);			
			break;
		case unavailable :
			index++;
			store_bucket(index, auth, key);			
			break;
	}
}

bucket_t hash_table_find(index)
int index;
{
	return table[index];
}
