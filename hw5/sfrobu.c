#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>

void errHandler(const char* err, int size) {
	write(2, err, size);
	exit(1);
}

int frobcmp(char const *a, char const *b) {
	if (a == NULL || b == NULL) {
		char tmp[] = "Invalid input for frobcmp\n";
		errHandler(tmp, sizeof(tmp));
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

int frobcmpupper(char const *a, char const *b) {
	if (a == NULL || b == NULL) {
		char tmp[] = "Invalid input for frobcmp\n";
		errHandler(tmp, sizeof(tmp));
	}
	while ((*a != ' ') & (*b != ' ')) {
		char first = (*a) ^ 42;
		char second = (*b) ^ 42;
		if (first >= -1)
			first = toupper(first);
		if (second >= -1)
			second = toupper(second);
		if (first == second) {
			a++;
			b++;
		}
		else if (first - second > 0)
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
	return frobcmp(*(const char**)a, *(const char**)b);
}

int frobcallerupper(const void *a, const void *b) {
	return frobcmpupper(*(const char**)a, *(const char**)b);
}

void to2d(const char* words1d, int n, int fswitch) {
	const int nAlloc = 10;
	int iArr = 0;
	int sizeArr = nAlloc;
	int iStr = 0;
	int sizeStr = 0;
	int i;

	char chr;
	char **words = (char**)malloc(sizeof(char*) * nAlloc);

	if (words == NULL) { //check for words memory allocation
		char tmp[] = "Error in memory allocation\n";
		errHandler(tmp, sizeof(tmp));
	}

	for (i = 0; i < n; i++) {
		chr = words1d[i];

		if (iArr + 1 > sizeArr) {
			words = (char**)realloc(words, (sizeArr + nAlloc) * sizeof(char*));
			if (words == NULL) {
				char tmp[] = "Error in memory reallocation\n";
				errHandler(tmp, sizeof(tmp));
			}
			sizeArr += nAlloc;
		}
		if (iStr == 0) {
			words[iArr] = (char*)malloc(sizeof(char) * nAlloc);
			if (words[iArr] == NULL) {
				char tmp[] = "Error in memory reallocation\n";
				errHandler(tmp, sizeof(tmp));
			}
			sizeStr = nAlloc;
		}
		if (iStr + 1 > sizeStr) {
			words[iArr] = (char*)realloc(words[iArr], (sizeStr + nAlloc) * sizeof(char));
			if (words[iArr] == NULL) {
				char tmp[] = "Error in memory reallocation\n";
				errHandler(tmp, sizeof(tmp));
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

	if (fswitch)
		qsort(words, iArr, sizeof(char*), frobcallerupper);
	else
		qsort(words, iArr, sizeof(char*), frobcaller);

	for (i = 0; i < iArr; i++) {
		while (words[i][iStr] != ' ') {
			char cwrite = words[i][iStr];
			if (write(1, &cwrite, 1) == -1) { //check for error in output
				char tmp[] = "Error in output\n";
				errHandler(tmp, sizeof(tmp));
			}
			iStr++;
		}
		char tmp = ' ';
		if (write(1, &tmp, 1) == -1) { //check for error in output
			char tmp[] = "Error in output\n";
			errHandler(tmp, sizeof(tmp));
		}
		iStr = 0;
		free(words[i]);
	}
	free(words);
}


int main(int argc, char *argv[]) {
	//check argument
	int fswitch = 0;
	if (argc > 2) {
		char tmp[] = "Can only take one option: -f\n";
		errHandler(tmp, sizeof(tmp));
	}
	else if (argc == 2) {
		if (strcmp(argv[1], "-f") == 0)
			fswitch = 1;
		else {
			char tmp[] = "Can only take one option: -f\n";
			errHandler(tmp, sizeof(tmp));
		}
	}


	//check regular file and size
	struct stat buffer;
	long rawSize;
	const int nAlloc = 10;

	if (fstat(0, &buffer) == -1){ 
		char tmp[] = "Error in getting file status\n";
		errHandler(tmp, sizeof(tmp));
	}
	if (S_ISREG(buffer.st_mode))
		rawSize = buffer.st_size;
	else
		rawSize = nAlloc;

	char *words1d = (char*)malloc(sizeof(char)*rawSize);


	//read input
	int n = 0;
	char cget;
	int readstat;
	while ((readstat = read(0, &cget, 1)) == 1) {
		if (n == rawSize){
			words1d = (char*)realloc(words1d, sizeof(char)*(rawSize + nAlloc));
			rawSize += nAlloc;
		}
		words1d[n] = cget;
		n++;
	}
	if (readstat == -1) {
		char tmp[] = "Error in reading input\n";
		errHandler(tmp, sizeof(tmp));
	}

	//convert to 2d array and qsort
	to2d(words1d, n, fswitch);

	return 0;
}