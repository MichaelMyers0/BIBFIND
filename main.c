#include "bibfind_system.h"
main()
{
	enum action act = bib_creat;
	int key;
	bucket_t b;
	init();
	bib_entry(act, bib_key());
	bib_entry(act, bib_key());
	key = bib_key();
	bib_entry(act, key);
	b = bib_find(key, "Dr Eckman");
	printf("%s\n", b.author);
	exit(0);
}
