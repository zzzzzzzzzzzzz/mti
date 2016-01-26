/*
* file format is not being checked.
* File format: xxxx $$$$$...
* xxxx - date
* $$$$$$... - Name
*/

#include <vector>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#define MAXLENGTH 260

struct record
{
	char birthdate[4];
	char name[255];
};

void saveRecord(std::vector<struct record> *base, struct record *subj) {
	base->push_back(*subj);
}

void saveToFile(std::vector<struct record> *base, const char* filename) {
	errno = 0;
	FILE *f = fopen(filename, "w");
	if (errno != 0) {
		fprintf(stderr, "%s\n", strerror(errno));
		exit(errno);
	}
	while (!base->empty()) {
		fwrite(base->back().birthdate, strlen(base->back().birthdate) - strlen(base->back().name), 1, f);
		fwrite(" ", 1, 1, f);
		fwrite(base->back().name, strlen(base->back().name), 1, f);
		fwrite("\n", 1, 1, f);
		base->pop_back(); 
	}
	fclose(f);
}

void loadFromFile(std::vector<struct record> *base, const char* filename) { 
	errno = 0;
	FILE *f = fopen(filename, "r");
	if (errno != 0) {
		fprintf(stderr, "%s\n", strerror(errno));
		exit(errno);
	}
	char buf[MAXLENGTH];
	int i;
	for (i = 0; i < MAXLENGTH; i++) {
		buf[i] = '\n';
	}
	while (fgets(buf, MAXLENGTH, f)) {
		struct record rec;
		for (i = 0; i < 4; i++) {
			rec.birthdate[i] = 0;
		}
		for (i = 0; i < 255; i++) {
			rec.name[i] = 0;
		}
		int i;
		for (i = 0; i < 5; i++) {
			if (buf[i] == ' ') {
				break;
			}
			rec.birthdate[i] = buf[i];
		}
		int j = 0;
		while (buf[++i] != '\n') {
			rec.name[j++] = buf[i];
		}
		for (i = 0; i < MAXLENGTH; i++) {
			buf[i] = 0;
		}
		saveRecord(base, &rec);
	}
	fclose(f);
}

int main() {
	std::vector<struct record> base;
	loadFromFile(&base, "first");
	saveToFile(&base, "second");
	return 0;
}