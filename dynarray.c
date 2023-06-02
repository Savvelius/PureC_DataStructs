#include "dynarray.h"
#include <assert.h>

DA_info* DAInfo(isize_t size, isize_t capacity, isize_t element_size)
{
	DA_info* info_p = customalloc(DA_info, 1);
	info_p->size = size;
	info_p->capacity = capacity;
	info_p->element_size = element_size;
	return info_p;
}

DA DA_setinfo(byte* arr, DA_info* info)
{
	*((DA_info*)arr - 1) = *info;
	return arr;
}

void DA_printinfo(DA arr) {
	DA_info info = DA_getinfo(arr);
	printf("Size = %d, capacity = %d, element size = %d\n", info.size, info.capacity, info.element_size);
}

DA DA_getslice(DA arr, isize_t start, isize_t end) {
	assert(start < end && end < DA_length(arr));
	isize_t elsize = DA_elemsize(arr), len = (end - start) * elsize;
	return DA_setinfo( memcpy(safemalloc(len + isizeof(DA_info)) + isizeof(DA_info), arr + start * elsize, len), DAInfo(end-start, end-start, elsize) ); 
}

DA DA_upsize(DA arr, isize_t addsize) {
	arr = saferealloc((DA_info*)arr - 1, DA_elemsize(arr) * (DA_capacity(arr) + addsize) + isizeof(DA_info)) + isizeof(DA_info);
	((isize_t*)arr)[-2] += addsize;
	return arr;
}

void DA_remove(DA arr, isize_t index) {
	DA_info info = DA_getinfo(arr);
	assert(index >= 0 && index < info.size);
	for (int i = info.element_size * index; i < (info.size - 1) * info.element_size; i++) {
		arr[i] = arr[i + info.element_size];
	}
	((isize_t*)arr)[-3]--;
}

