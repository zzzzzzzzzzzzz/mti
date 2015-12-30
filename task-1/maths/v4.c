/*
*	Calculates golden section using two neighbour fibonacci numbers
*	params: n - number of member of fibonacci sequence
*/
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

long double goldenSection(long int quantity) {
	if (quantity == 1) {
		return 1;
	}
	if (quantity == 2) {
		return 2;
	}
	long double previous = 1;
	long double current = 1;
	int i = 2;
	for (; i <= quantity; i++) {
		long double summated = previous + current;
		previous = current;
		current = summated;
	}
	return current / previous;
}

int main(int argc, char **argv) {
	if (argc < 2) {
		fprintf(stdout, "few args, waited for 1, got %d\n", argc-1);
		exit(-1);
	}
	char *endptr = NULL;
	long int quantity = strtol(argv[1], &endptr, 10);

	if ((quantity == LONG_MIN) || (quantity == LONG_MAX)) {
		fprintf(stderr, "%s\n", strerror(errno));
		exit(errno);
	}
	if (endptr == argv[1]) {
		fprintf(stderr, "No digits were found\n");
		exit(errno);
	}
	if (endptr != NULL && *endptr) {
		fprintf(stderr, "Unexpected symbol(s) \"%s\" in argument \"%s\"\n", endptr, argv[3]);
		exit(-1);
	}
	fprintf(stdout, "%Lf\n", goldenSection(quantity));
	return 0;
}