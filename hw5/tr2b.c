#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int norep (char *arr){
  int i;
  int j;
  for (i = 0; i < strlen(arr); i++){
    char tmp = arr[i];
    for (j = i + 1; j < strlen(arr); j++){
      if (tmp == arr[j]){
	return 0;
      }
    }
  }
  return 1;
}

int main(int argc, char *argv[]){
  if (argc != 3){ //first argument is ./tr2b
    fputs("needs 2 arguments\n", stderr);
    exit(1);
  }
  char *from = argv[1];
  char *to = argv[2];
  int sizefrom = strlen(from);
  int sizeto = strlen(to);
  char cget;
  int i;
  if (sizefrom != sizeto){
    fputs("two arguments are not of the same length\n", stderr);
    exit(1);
  }
  if (!norep(from)){
    fputs("repeated characters in arg1, (operand from)\n", stderr);
    exit(1);
  }
  while(1){
    cget = getchar();
    if (ferror(stdin)){
      fputs("error in input", stderr);
      exit(1);
    }
    if (feof(stdin))
      break;
    for (i = 0; i < sizefrom; i++){
      if (cget == from[i]){
	putchar(to[i]);
	break;
      }
    }
    if (i == sizefrom)
      putchar(cget);
  }
  return 0;
}
