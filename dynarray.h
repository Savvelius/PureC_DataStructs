#pragma once
#include "types.h"
#include "memory.h"
#include <stdio.h>

#define DA(arr) byte* arr

typedef struct {
	isize_t size;
	isize_t capacity;
	isize_t element_size;
} DA_info;

void DA_info_print(DA_info info);

DA_info* DAInfo(isize_t size, isize_t capacity, isize_t element_size);

#define DA_init(T, prealloc)   memcpy( safemalloc(isizeof(T) * prealloc + isizeof(DA_info)), DAInfo(0, prealloc, isizeof(T)), isizeof(DA_info) ) + isizeof(DA_info)

#define DA_getinfo(arr)    ((DA_info*)arr)[-1]
#define DA_length(arr)    ((isize_t*)arr)[-3]
#define DA_capacity(arr)    ((isize_t*)arr)[-2]
#define DA_elemsize(arr)    ((isize_t*)arr)[-1]

// can only be called on arrays of int. Idk how to fix it. Good enough for debug
#define DA_print(arr)    putchar('['); for (int i = 0; i < DA_length(arr); i++){ printf("%d, ", ((int*)arr)[i]); }; puts("]\n");

#define DA_printinfo(arr)    DA_info_print(DA_getinfo(arr))

#define DA_getitem(arr, idx, T)    (DA_length(arr) > idx && idx >= 0)?((T*)arr)[idx]:NULL

// TODO: implement a more sophisticated memory reallocation algorythm then just + elemsize * 4.
#define DA_append(arr, el, T)   { DA_info info = DA_getinfo(arr);    \
							      if (info.capacity <= info.size) {    \
								  arr = saferealloc( ((DA_info*)arr-1), DA_elemsize(arr) * (DA_capacity(arr) + 4) + isizeof(DA_info)) + isizeof(DA_info);    \
								  ((isize_t*)arr)[-2] += 4;  }    \
								  memcpy(arr + info.size * info.element_size, &el, info.element_size) ; ((isize_t*)arr)[-3] += 1;		\
						        }

