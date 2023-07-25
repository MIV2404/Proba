CC = gcc
CFLAGS = -Wall -Wextra -Werror
CLANGI = clang-format -i
CLANGN = clang-format -n
QUEST_1 = ../build/Quest_1
QUEST_2 = ../build/Quest_2
QUEST_3 = ../build/Quest_3

.PHONY: all clean rebuild clangi clangn door_struct list_test stack_test

all: door_struct list_test stack_test

door_struct:
	$(CC) $(CFLAGS) dmanager_module.c -o $(QUEST_1) -D Quest_1

list_test:
	$(CC) $(CFLAGS) list_test.c list.c -o $(QUEST_2) -D Quest_2

stack_test:
	$(CC) $(CFLAGS) stack.c stack_test.c -o $(QUEST_3) -D Quest_3

clean:
	rm -rf $(QUEST_1)
	rm -rf $(QUEST_2)
	rm -rf $(QUEST_3)

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

rebuild: clean all