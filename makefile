OS = $(shell uname)
CC = gcc
IDIR = ./include
CFLAGS = -Wall -I $(IDIR)
CDBG = -g3 -O0
SRC = $(shell ls src/)
APP_NAME = test.exe

ifeq ("$(OS)","Linux")
	DL_POSTFIX = .os
else
	DL_POSTFIX = .dll
endif

main: $(addprefix build/, $(addsuffix .o, $(SRC)))
	$(CC) -o $(APP_NAME) $^
	
debug: $(addprefix debug/, $(addsuffix .o, $(SRC)))
	$(CC) -o $(APP_NAME) $^

build/%.c.o: src/%.c $(IDIR)/*.h
	$(CC) $(CFLAGS) -c -o $@ $<

debug/%.c.o: src/%.c $(IDIR)/*.h
	$(CC) $(CFLAGS) $(CDBG) -c -o $@ $<
	
clean:
	rm build/* debug/* test.exe