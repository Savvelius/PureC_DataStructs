#include "dynarray.h"
#include <stdio.h>
#include "memory.h"

int main() {
	
	DA(arr) = DA_init(int, 2);
	for (int i = 0; i < 10; i++) {
		DA_print(arr);
		DA_printinfo(arr);
		DA_append(arr, i, int);
	}
	/*
	DA(arr) = DA_init(int, 2);
	DA_printinfo(arr);
	arr = saferealloc(arr, DA_capacity(arr) * (DA_elemsize(arr) + 4) + isizeof(DA_info));
	*/
	return 0;
}