CC=cc
CCFLAGS=-Wall -Wextra
bibfind_system.o:bibfind_system.c
	$(CC) $(CCFLAGS) -g -c $< -o $@
main:main.c bibfind_system.o
	$(CC) $(CCFLAGS) -g -O $^ -o $@

