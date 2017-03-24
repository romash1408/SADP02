main: main.o bstree.o
	gcc -o test.exe build/bstree.o build/main.o
	
debug: debug/main.o debug/bstree.o
	gcc -o test debug/main.o debug/bstree.o

main.o: src/main.c
	gcc -Wall -c -o build/main.o src/main.c

bstree.o: src/bstree.c
	gcc -Wall -c -o build/bstree.o src/bstree.c
	
debug/main.o: src/main.c
	gcc -Wall -c -g3 -O0 -o debug/main.o src/main.c

debug/bstree.o: src/bstree.c
	gcc -Wall -c -g3 -O0 -o debug/bstree.o src/bstree.c