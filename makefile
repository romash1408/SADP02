main: build/main.o build/bstree.o build/hashtab.o
	gcc -o test.exe build/bstree.o build/main.o build/hashtab.o
	
debug: debug/main.o debug/bstree.o debug/hashtab.o
	gcc -o test debug/main.o debug/bstree.o debug/hashtab.o

build/main.o: src/main.c
	gcc -Wall -c -o build/main.o src/main.c

build/bstree.o: src/bstree.c
	gcc -Wall -c -o build/bstree.o src/bstree.c

build/hashtab.o: src/hashtab.c
	gcc -Wall -c -o build/hashtab.o src/hashtab.c
	
debug/main.o: src/main.c
	gcc -Wall -c -g3 -O0 -o debug/main.o src/main.c

debug/bstree.o: src/bstree.c
	gcc -Wall -c -g3 -O0 -o debug/bstree.o src/bstree.c
	
debug/hashtab.o: src/hashtab.c
	gcc -Wall -c -g3 -O0 -o debug/hashtab.o src/hashtab.c
	
clean:
	rm build/* test.exe