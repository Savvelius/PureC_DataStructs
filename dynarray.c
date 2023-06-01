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

void DA_info_print(DA_info info)
{
	printf("Size = %d, capacity = %d, element size = %d\n", info.size, info.capacity, info.element_size);
}
