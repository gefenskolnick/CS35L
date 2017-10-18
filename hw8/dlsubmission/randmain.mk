OPTIMIZE = -O2

CC = gcc
CFLAGS = $(OPTIMIZE) -g3 -Wall -Wextra -march=native -mtune=native -mrdrnd

randmain:
	$(CC) $(CFLAGS) -c randmain.c -o randmain.o
	$(CC) $(CFLAGS) -c randcpuid.c -o randcpuid.o
	$(CC) $(CFLAGS) -ldl -Wl,-rpath=$(PWD) randmain.o randcpuid.o -o randmain 

randlibhw.so:
	$(CC) $(CFLAGS) -c -fPIC randlibhw.c -o randlibhw.o
	$(CC) $(CFLAGS) -shared randlibhw.o -o randlibhw.so

randlibsw.so:
	$(CC) $(CFLAGS) -c -fPIC randlibsw.c -o randlibsw.o
	$(CC) $(CFLAGS) -shared randlibsw.o -o randlibsw.so
