/*
*	Calculates sum of first 20 fibonacci numbers
*/
#include <stdlib.h>
#include <stdio.h>

unsigned long long fibosum(size_t quantity) {
	if (quantity == 1) {
		return 1;
	}
	if (quantity == 2) {
		return 2;
	}
	unsigned long long previous = 1;
	unsigned long long current = 1;
	unsigned long long res = previous + current;
	int i = 2;
	for (; i < quantity; i++) {
		unsigned long long summated = previous + current;
		previous = current;
		current = summated;
		res += summated;

	}
	return res;
}

int main() {
	fprintf(stdout, "%llu\n", fibosum(20));
	return 0;
}