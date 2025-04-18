#include "bibfind_system.h"

static char in_buf[max_len];
static bib_entry_t ent;

static build_string(src, dst);
static read_author(src, key);
static store_bibfind_entry(ent);

static build_string(src, dst)
char* src;
char* dst;
{
	size_t len;
	len = strlen(src);
	*(src + len - 1) = 0;
	strcpy(dst, src);
	*(dst + len) = 0;
}

static creat_bib_entry(src, key)
char* src;
int key;
{
	char* s;
        errno = 0;
        s = fgets(src, max_len, stdin);
        if (!s)
        {
                perror("ERROR: Failed to read authors name\n");
                exit(1);
        }
        build_string(src, ent.author);
        ent.key = key;
}

static store_bibfind_entry(ent)
bib_entry_t* ent;
{
	hash_store(ent->key, ent->author);
}

init()
{
	srand(time(NULL));
	hash_table_init();
}

bib_entry(act, key)
enum action act;
int key;
{
	switch (act)
	{
		case bib_creat :
			creat_bib_entry(in_buf, key);
			store_bibfind_entry(&ent);
			break;
		case bib_modify :
			break;
	}
}

bib_key()
{
	int key;
	key = rand() % ((table_size << 2)+ 1 - 0) + 0;
	return key;
}

bucket_t bib_find(key, author)
int key;
const char* author;
{
	bucket_t b;
	int index;
	index = hash(key);
	for (;;)
	{
		b = hash_table_find(index);
		if (0 == strcmp(b.author, author))
			return b;
		index++;
	}
	return b;
}

bib_update()
{

}
