CC = gcc
FLAGS = -Wall -Werror -Wextra -fsanitize=address -fsanitize=leak
CLANGI = clang-format -i
CLANGN = clang-format -n

GRAPH = ../build/graph

.PHONY: all clean rebuild graph # указывает на фиктивные цели (phony targets) в Make-системе.

all: graph

rebuild: clean all

graph: graph.c parser.c counting.c parser.h counting.h structure_lib
	$(CC) $(FLAGS) -c graph.c parser.c counting.c
	$(CC) $(FLAGS) graph.o parser.o counting.o structure_lib.a -o $(GRAPH)

structure_lib: structure_lib.o
	ar rc structure_lib.a structure.o

structure_lib.o: structure.c structure.h
	$(CC) $(FLAGS) -c structure.c

clangi :
	@cp ../materials/linters/.clang-format .
	@$(CLANGI) *.c
	@$(CLANGI) *.h
	@rm -rf .clang-format
	@echo "\033[37;41;1m Стиль кода исправлен \033[0m"

clangn :
	@cp ../materials/linters/.clang-format .
	@$(CLANGN) *.c 
	@$(CLANGN) *.h
	@rm -rf .clang-format
	@echo "\033[37;41;1m Проверка стиля выполнена \033[0m"

clean:
	rm *.o
	rm *.a
	rm $(GRAPH)