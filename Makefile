CFLAGS = -Wall -Werror -Wextra 
CPPFLAGS =  -MMD -I includes/ 

SRC = src/

.PHONY: all
all: Lab1

-include main.d rbtree.d bstree.d

Lab1: build/main.o build/librbtree.a build/libbst.a
	gcc -Iincludes/   $(CFLAGS)  $^ -o $@
	rm build/main.o;
	rm build/main.d;
	rm build/rbtree.o;
	rm build/rbtree.d ;

build/main.o: src/main.c
	gcc -c $(CFLAGS) $(CPPFLAGS) $< -o $@

build/librbtree.a: build/rbtree.o
	ar rcs $@ $^

build/libbst.a: build/bstree.o
	ar rcs $@ $^

build/rbtree.o: src/rbtree.c
	gcc -c  $(CPPFLAGS) $< -o $@

build/bstree.o: src/bstree.c
	gcc -c  $(CPPFLAGS) $< -o $@

.PHONY: clean
clean:
	rm build/main.o;
	rm build/main.d;
	rm build/rbtree.o;
	rm build/rbtree.d;
	rm build/bstree.d;
	rm build/bstree.o;
	rm build/libbst.a;
	rm build/librbtree.a;
