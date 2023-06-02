#include "memory.h"
#include "types.h"

byte* safemalloc(isize_t size) {
	byte* p = (byte*)malloc(size);
	assert(p);
	return p;
}

byte* saferealloc(void* ptr, isize_t size) {
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