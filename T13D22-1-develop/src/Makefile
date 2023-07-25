CC = gcc
FLAGS = -Wall -Werror -Wextra -fsanitize=address -fsanitize=leak
CLANGI = clang-format -i
CLANGN = clang-format -n

CIPHER = ../build/cipher
LOGGER = ../build/logging_cipher


.PHONY: all clean rebuild cipher

all: cipher logging_cipher

cipher: cipher.c
	$(CC) $(FLAGS) -c cipher.c
	$(CC) $(FLAGS) cipher.o -o $(CIPHER)

logging_cipher:
	$(CC) $(FLAGS) -c logger.c
	$(CC) $(FLAGS) logger.o -o $(LOGGER)


clangi:
	@cp ../materials/linters/.clang-format .
	@$(CLANGI) *.c
	@$(CLANGI) *.h
	@rm -rf .cilang-format

clangn:
	@cp ../materials/linters/.clang-format .
	@$(CLANGN) *.c
	@$(CLANGN) *.h
	@rm -rf .cilang-format

cpp:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

leaks:
	leaks -atExit -- ./$(CIPHER)

clean:
	rm *.o
	# rm *.a
	rm $(CIPHER)
	rm $(LOGGER)

