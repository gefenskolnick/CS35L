#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

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
  if (argc != 3){ //the first operand is ./tr2u
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
  while (read(0, &cget, 1) == 1){ //0 is the file descriptor for stdin
    for (i = 0; i < sizefrom; i++){
      if (cget == from[i]){
	write(1, &to[i], 1);
	break;
      }
    }
    if (i == sizefrom)
      write(1, &cget, 1);
  }
  return 0;
}
