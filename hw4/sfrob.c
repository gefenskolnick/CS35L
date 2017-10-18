#include <stdio.h>
#include <stdlib.h>

int frobcmp(char const *a, char const *b) {
	if (a == NULL || b == NULL){
		fputs("Invalid input for frobcmp", stderr);
		exit(1);
	}
	while ((*a != ' ') & (*b != ' ')) {
		if (((*a) ^ 42) == ((*b) ^ 42)) {
			a++;
			b++;
		}
		else if (((*a) ^ 42) - ((*b) ^ 42) > 0)
			return 1;
		else
			return -1;
	}
	if (*a == ' ') {
		if (*b == ' ')
			return 0;
		return -1;
	}
	return 1;
}

int frobcaller(const void *a, const void *b) {
  return frobcmp(*(const char**)a,*(const char**)b);
}

int main() {
	const int nAlloc = 10;
	int iArr = 0;
	int sizeArr = nAlloc;
	int iStr = 0;
	int sizeStr = 0;
	int i = 0;

	char chr;
	char **words = (char**)malloc(sizeof(char*) * nAlloc);

	if (words == NULL){ //check for words memory allocation
		fputs("Error in memory allocation\n", stderr);
		exit(1);
	}
	
	while (1) {
	  chr = getchar();
	  if (feof(stdin))
	    break;
	  if (ferror(stdin)) { //error in getchar
	    fputs("Error in input\n", stderr);
	    exit(1);
	  }

		if (iArr + 1 > sizeArr) {
			words = (char**)realloc(words, (sizeArr + nAlloc)*sizeof(char*));
			if (words == NULL){
				fputs("Error in memory reallocation\n", stderr);
				exit(1);
			}
			sizeArr += nAlloc;
		}
		if (iStr == 0) {
			words[iArr] = (char*)malloc(sizeof(char) * nAlloc);
			if (words[iArr] == NULL){
				fputs("Error in memory allocation\n", stderr);
				exit(1);
			}
			sizeStr = nAlloc;
		}
		if (iStr + 1 > sizeStr) {
			words[iArr] = (char*)realloc(words[iArr], (sizeStr + nAlloc)*sizeof(char));
			if (words[iArr] == NULL){
				fputs("Error in memory reallocation\n", stderr);
				exit(1);
			}
			sizeStr += nAlloc;
		}

		if (chr == ' ') { //store input char
			words[iArr][iStr] = chr;
			iArr++;
			iStr = 0;
			sizeStr = 0;
		}
		else {
			words[iArr][iStr] = chr;
			iStr++;
		}
	}

	if (iStr != 0) { //in case stdin does not have a trailing space
		words[iArr][iStr] = ' ';
		iArr++;
		iStr = 0;
	}

	qsort(words, iArr, sizeof(char*), frobcaller);

	for (i; i < iArr; i++) {
		while (words[i][iStr] != ' ') {
			if (putchar(words[i][iStr]) == EOF) { //check for error in output
				fputs("Error in output\n", stderr);
				exit(1);
			}
			iStr++;
		}
		if (putchar(' ') == EOF) { //check for error in output
			fputs("Error in output\n", stderr);
			exit(1);
		}
		iStr = 0;
		free(words[i]);
	}
	free(words);

	return 0;
}
