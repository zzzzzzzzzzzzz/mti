/*
* File format regexp: [a-zA-Z]->[a-zA-Z] (rules of type 0 grammar in Chomsky's hierarchy)
*/

#include <list>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <regex.h> //POSIX regular expressions for checking file format        

#define MAXLENGTH 512
#define FORMAT "[a-zA-Z]->[a-zA-Z]"

struct record
{
	char from[255];
	char to[255];
};

void saveRecord(std::list<struct record> *rules, struct record *subj) {
	rules->push_front(*subj);
}

void saveToFile(std::list<struct record> *rules, const char* filename) {
	errno = 0;
	FILE *f = fopen(filename, "w");
	if (errno != 0) {
		fprintf(stderr, "%s\n", strerror(errno));
		exit(errno);
	}
	while (!rules->empty()) {
		printf("%s\n", rules->back().from);
		fwrite(rules->back().from, strlen(rules->back().from), 1, f);
		fwrite("->", 2, 1, f);
		fwrite(rules->back().to, strlen(rules->back().to), 1, f);
		rules->pop_back(); 
	}
	fclose(f);
}

void loadFromFile(std::list<struct record> *rules, const char* filename) { 
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
	unsigned long string_number = 0;
	while (fgets(buf, MAXLENGTH, f)) {
		string_number++;
		//Check format of the string
	    regex_t regex;
	    int reti;
	    /*Compile regular expression*/
	    reti = regcomp(&regex, FORMAT, 0);
	    if (reti) {
	        printf("Could not compile regex\n");
	        exit(errno);
	    }
	    /* Execute regular expression */
	    reti = regexec(&regex, buf, 0, NULL, 0);
	    if (reti != 0) {
	      if (reti == REG_NOMATCH) {
	          printf("Incorrect format on line %lu\n", string_number);
	          exit(errno);
	      }
	      else {
	          printf("Regex match failed!\n");
	          exit(errno);
	      }
	    }

	    /* Free compiled regular expression*/
	    regfree(&regex);

	    int i = 0;
	    while (buf[i] != '-') {i++;}
		struct record rec;
		memset(&rec,0,sizeof(struct record));
		strncpy(rec.from, buf, i);
		strncpy(rec.to, &buf[i+2], strlen(&buf[i+2])+1);
		saveRecord(rules, &rec);
		memset(&rec, 0, i+1);
	}
	fclose(f);
}

int main() {
	std::list<struct record> rules;
	loadFromFile(&rules, "input");
	saveToFile(&rules, "output");
	return 0;
}