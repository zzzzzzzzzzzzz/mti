/*
*	Calculates last 10 members of ariphmetical sequence
*	params: a1, d, number of elements
*/
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <math.h>

int main(int argc, char **argv) {
	if (argc < 4) {
		fprintf(stdout, "few args, waited for 3, got %d\n", argc-1);
		exit(-1);
	}
	char *endptr = NULL;
	long int quantity = strtol(argv[3], &endptr, 10);

	if ((quantity == LONG_MIN) || (quantity == LONG_MAX)) {
		fprintf(stderr, "%s\n", strerror(errno));
		exit(errno);
	}
	if (endptr == argv[3]) {
		fprintf(stderr, "No digits were found\n");
		exit(errno);
	}
	if (endptr != NULL && *endptr) {
		fprintf(stderr, "Unexpected symbol(s) \"%s\" in argument \"%s\"\n", endptr, argv[3]);
		exit(-1);
	}

	if (quantity < 0) {
		fprintf(stdout, "quantity must be greater than zero\n");
		exit(-1);
	}
	if (quantity < 10) {
		fprintf(stdout, "I need at least 10 members of sequence, last parameter must be >=10\n");
		exit(-1);
	}	

	long double first = strtold(argv[1], &endptr);
	if (first == HUGE_VAL) {
		fprintf(stderr, "%s\n", strerror(errno));
		exit(errno);
	}
	if (endptr == argv[1]) {
		fprintf(stderr, "No digits were found\n");
		exit(errno);
	}
	if (endptr != NULL && *endptr) {
		fprintf(stderr, "Unexpected symbol(s) \"%s\" in argument \"%s\"\n", endptr, argv[1]);
		exit(-1);
	}

	long double difference = strtold(argv[2], &endptr);
	if (difference == HUGE_VAL) {
		fprintf(stderr, "%s\n", strerror(errno));
		exit(errno);
	}
	if (endptr == argv[2]) {
		fprintf(stderr, "No digits were found\n");
		exit(errno);
	}
	if (endptr != NULL && *endptr) {
		fprintf(stderr, "Unexpected symbol(s) \"%s\" in argument \"%s\"\n", endptr, argv[2]);
		exit(-1);
	}

	long double res = 10 * first + difference * (10*quantity - 55);

	fprintf(stdout, "%Lg\n", res);

	return 0;
}