#pragma once
#include "types.h"
#include "memory.h"
#include <stdio.h>

#define UPSIZE 4
typedef byte* DA;
typedef struct {
	isize_t size;
	isize_t capacity;
	isize_t element_size;
} DA_info;

DA_info* DAInfo(isize_t size, isize_t capacity, isize_t element_size);
DA DA_setinfo(byte* arr, DA_info* info);

#define DA_init(T, prealloc)   memcpy( safemalloc(isizeof(T) * prealloc + isizeof(DA_info)), DAInfo(0, prealloc, isizeof(T)), isizeof(DA_info) ) + isizeof(DA_info)

#define DA_getinfo(arr)    ((DA_info*)arr)[-1]
#define DA_length(arr)    ((isize_t*)arr)[-3]
#define DA_capacity(arr)    ((isize_t*)arr)[-2]
#define DA_elemsize(arr)    ((isize_t*)arr)[-1]

// DEBUG, only for int
#define DA_print(arr)    putchar('['); for (int i = 0; i < DA_length(arr); i++){ printf("%d, ", ((int*)arr)[i]); }; puts("]\n"); 
#define DA_getitem(arr, idx, return_type)    (DA_length(arr) > idx && idx >= 0)?*(return_type*)(arr + idx * DA_elemsize(arr)):NULL

DA DA_getslice(DA arr, isize_t start, isize_t end);
void DA_printinfo(DA arr);						 
DA DA_upsize(DA arr, isize_t addsize);
void DA_remove(DA arr, isize_t index);

#define DA_append(arr, el)   { DA_info info = DA_getinfo(arr);    \
							      if (info.size >= info.capacity) { arr = DA_upsize(arr, UPSIZE); }   \
								  memcpy(arr + info.size * info.element_size, &el, info.element_size) ; ((isize_t*)arr)[-3]++;		\
						     }

#define DA_insert(arr, el, index) { DA_info info = DA_getinfo(arr); assert(index < info.size && index >= 0);   \
									if (info.size >= info.capacity){ arr = DA_upsize(arr, UPSIZE); }\
									for (int i = info.size * info.element_size - 1; i >= index * info.element_size; i --){ arr[i + info.element_size] = arr[i]; }  \
									memcpy(arr + index * info.element_size, &el, info.element_size) ; ((isize_t*)arr)[-3]++;  \
 								  }

