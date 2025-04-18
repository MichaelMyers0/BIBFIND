#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <string.h>
#include <sys/types.h>
enum {table_size = 1024};
enum {max_len = 255};
enum bucket_status{available, unavailable};
typedef struct
{
	char author[max_len];
	int key;
	enum bucket_status status;
}bucket_t;
hash_table_init();
hash(key);
hash_store(key, auth);
bucket_t hash_table_find(key);
#endif
