#include "dynarray.h"
#include <stdio.h>
#include "memory.h"

int main() {
	DA arr = DA_init(int, 2);
	for (int i = 0; i < 10; i++) {
		DA_append(arr, i);
	}
	DA_print(arr);
	int i = 1000;
	DA_insert(arr, i, 5);
	DA_print(arr);
	DA_printinfo(arr);
	DA_remove(arr, 3);
	DA_print(arr);
	DA_printinfo(arr);
	printf("%d\n", DA_getitem(arr, 5, int));
	DA slice = DA_getslice(arr, 2, 6);
	DA_print(slice);
	DA_printinfo(slice);
	return 0;
}