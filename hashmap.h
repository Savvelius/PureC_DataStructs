#pragma once
#include "dynarray.h"
/*
For now can't handle collisions (to be fixed).
Can't exceed the given length limit due to modulo hash calculation.
Doesn't have 'keyerrors' when accessing by non-existing keys.
*/
typedef DA MAP;

isize_t hash_function(byte* key, isize_t modulo);

#define MAP_init(T, length)   memcpy( safemalloc(isizeof(T) * length + isizeof(DA_info)), DAInfo(0, length, isizeof(T)), isizeof(DA_info) ) + isizeof(DA_info)

#define MAP_insert(map, key, value)    memcpy( map + DA_elemsize(map) * hash_function(key, DA_capacity(map)), &value, DA_elemsize(map) ); 

#define MAP_getitem(map, key, return_type)    *(return_type*)(map + hash_function(key, DA_capacity(map)) * DA_elemsize(map))