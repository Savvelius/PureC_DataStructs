#include "hashmap.h"
#include <stdio.h>

isize_t hash_function(byte* key, isize_t modulo) {
	isize_t FNV_offset_basis = 2166136261, FNV_prime = 16777619;
	isize_t hash = FNV_offset_basis;
	for (int i = 0; key[i] != '\0'; i++) {
		hash = hash ^ key[i];
		hash *= FNV_prime;
	}
	hash = hash % modulo;
	printf("%d\n", hash);
	return hash;
}

