#include "dynarray.h"
#include "hashmap.h"
#include <stdio.h>
#include "memory.h"

int main() {
	MAP map = MAP_init(int, 10);
	int v = 10;
	MAP_insert(map, "hello", v);
	int get = MAP_getitem(map, "hello", int);
	printf("%d", get);
	return 0;
}