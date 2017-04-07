OS = $(shell uname)
ifeq ("$(OS)", "Linux")
	DL_POSTFIX = so
	CDL = -fPIC -shared
else
	DL_POSTFIX = dll
endif

CC = gcc
IDIR = ./include
CFLAGS = -Wall -I $(IDIR) -D DL_POSTFIX=$(DL_POSTFIX)
CDBG = -g3 -O0
OBJ = $(patsubst src/%.c, %.o, $(wildcard src/*.c))
LIBS = $(patsubst src/libs/%.c, %.$(DL_POSTFIX), $(wildcard src/libs/*.c))

APP_NAME = test.exe

all: LibBuild AppBuild

debug: LibDebug AppDebug

AppBuild: $(addprefix build/s-, $(OBJ))
	$(CC) -o $(APP_NAME) $^
	
LibBuild: $(addprefix build/libs/, $(LIBS))
ifneq ("$(LIBS)", "")
	cp $^ libs/
endif


AppDebug: $(addprefix debug/s-, $(OBJ))
	$(CC) -o $(APP_NAME) $^
	
LibDebug: $(addprefix debug/libs/, $(LIBS))
ifneq ("$(LIBS)", "")
	cp $^ libs/
endif

build/s-%.o: src/%.c $(IDIR)/*.h
	$(CC) $(CFLAGS) -c -o $@ $<
	
build/libs/%.$(DL_POSTFIX): src/libs/%.c
	$(CC) $(CFLAGS) $(CDL) -o $@ $<

debug/s-%.o: src/%.c $(IDIR)/*.h
	$(CC) $(CFLAGS) $(CDBG) -c -o $@ $<
	
debug/libs/%.$(DL_POSTFIX): src/libs/%.c
	$(CC) $(CFLAGS) $(CDBG) -$(CDL) -o $@ $<

clean:
	rm build/s-* debug/s-* build/libs/* debug/libs/* test.exe libs/*