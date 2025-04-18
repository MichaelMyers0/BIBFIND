#include "bibfind_system.h"

static char in_buf[max_len];
static bib_entry_t ent;

static build_string(src, dst);
static read_author(src, key);

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

static read_author(src, key)
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

init()
{
	srand(time(NULL));
}

bib_entry(act, key)
enum action act;
int key;
{
	switch (act)
	{
		case bib_creat :
			read_author(in_buf, key);
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

bib_find()
{

}

bib_update()
{

}
