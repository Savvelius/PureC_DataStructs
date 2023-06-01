#include <stdlib.h>
#include "memory.h"
#include "types.h"

/*
Everything is unifed to be byte*.
One pointer type to point to them all!
*/

byte* safemalloc(isize_t size) {
	byte* p = (byte*)malloc(size);
	assert(p);
	return p;
}

byte* saferealloc(void* ptr, isize_t size)
{
	byte* new_ptr = (byte*)realloc(ptr, size);
	assert(new_ptr);
	return new_ptr;
}

byte* memcpy(void* dest, void* source, isize_t nbytes) {
	for (int i = 0; i < nbytes; ++i) {
		((byte*)dest)[i] = ((byte*)source)[i];
	}
	return (byte*)dest;
}