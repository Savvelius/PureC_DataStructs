#pragma once
#include "types.h"
#include <assert.h>
#include <stdlib.h>

byte* safemalloc(isize_t size);
byte* saferealloc(void* ptr, isize_t size);

#define isizeof(object)    (isize_t)sizeof(object)
#define customalloc(type, length)    (type*)safemalloc(isizeof(type) * length)
#define customrealloc(ptr, length, type)    (type*)saferealloc(ptr, isizeof(type) * length)    


byte* memcpy(void* dest, void* source, isize_t nbytes);
