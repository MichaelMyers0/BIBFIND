#ifndef BIBFIND_SYSTEM_H
#define BIBFIND_SYSTEM_H
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
enum {max_len = 255};
enum {table_size = 1024};
enum action{bib_creat, bib_modify};
typedef struct
{
	char author[max_len];
	int key;
}bib_entry_t;
init();
bib_entry(act, key);
bib_key();
bib_find();
bib_update();
#endif
