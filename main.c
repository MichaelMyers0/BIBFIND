#include "bibfind_system.h"
main()
{
	enum action act = bib_creat;
	init();
	bib_entry(act, bib_key());
	bib_entry(act, bib_key());
	bib_entry(act, bib_key());
	exit(0);
}
