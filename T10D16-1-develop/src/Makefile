CC = gcc
CFLAGS = -Wall -Wextra -Werror
QUEST_1 = ../build/Quest_1
QUEST_2 = ../build/Quest_2
QUEST_3 = ../build/Quest_3
QUEST_4 = ../build/Quest_4
QUEST_5 = ../build/Quest_5
QUEST_6 = ../build/Quest_6
QUEST_7 = ../build/Quest_7
QUEST_8 = ../build/Quest_8

.PHONY: all clean rebuild strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests strstr_tests s21_strtok text_processor

all: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests strstr_tests s21_strtok text_processor

strlen_tests:
	$(CC) $(CFLAGS) s21_string.c s21_string_test.c -o $(QUEST_1) -D Quest_1

strcmp_tests:
	$(CC) $(CFLAGS) s21_string.c s21_string_test.c -o $(QUEST_2) -D Quest_2

strcpy_tests:
	$(CC) $(CFLAGS) s21_string.c s21_string_test.c -o $(QUEST_3) -D Quest_3

strcat_tests:
	$(CC) $(CFLAGS) s21_string.c s21_string_test.c -o $(QUEST_4) -D Quest_4

strchr_tests:
	$(CC) $(CFLAGS) s21_string.c s21_string_test.c -o $(QUEST_5) -D Quest_5

strstr_tests:
	$(CC) $(CFLAGS) s21_string.c s21_string_test.c -o $(QUEST_6) -D Quest_6

s21_strtok:
	$(CC) $(CFLAGS) s21_string.c s21_string_test.c -o $(QUEST_7) -D Quest_7

text_processor:
	$(CC) $(CFLAGS) text_processor.c -o $(QUEST_8) -D Quest_8

clean:
	rm -rf $(QUEST_1)
	rm -rf $(QUEST_2)
	rm -rf $(QUEST_3)
	rm -rf $(QUEST_4)
	rm -rf $(QUEST_5)
	rm -rf $(QUEST_6)
	rm -rf $(QUEST_7)
	rm -rf $(QUEST_8)

rebuild: clean all