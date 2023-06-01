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
	return 0;
}