#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

#include "s21_string_test.h"

void s21_strlen_test(int attempt, const char *str);

int main(void) {
#ifdef Quest_1

    char *str;
    int attempt_1 = 0, attempt_2 = -1, attempt_3 = 6;

    str = "Hello!";
    s21_strlen_test(attempt_3, str);

    str = NULL;
    s21_strlen_test(attempt_2, str);

    str = "";
    s21_strlen_test(attempt_1, str);

#endif

#ifdef Quest_2

    char *str1;
    char *str2;
    int attempt_1 = 1, attempt_2 = -1, attempt_3 = 0, attempt_4 = 72;

    str1 = "Hello!";
    str2 = "Hello!";
    s21_strcmp_test(attempt_3, str1, str2);

    str1 = "Hello1";
    str2 = "Hello2";
    s21_strcmp_test(attempt_2, str1, str2);

    str1 = "Hello2";
    str2 = "Hello1";
    s21_strcmp_test(attempt_1, str1, str2);

    str1 = "Hello2";
    str2 = "";
    s21_strcmp_test(attempt_4, str1, str2);

#endif

#ifdef Quest_3

    char str1[30] = "";
    char str2[30] = "Hello!";
    printf("%s", str1);
    char *result = s21_strcpy(str1, str2);
    s21_strcpy_test(result, str2);

    char str3[30] = "Hello, World!";
    printf("%s", str1);
    result = s21_strcpy(str1, str3);
    s21_strcpy_test(result, str3);

    char str4[30];
    printf("%s", str1);
    result = s21_strcpy(str1, str4);
    s21_strcpy_test(result, str4);

#endif

#ifdef Quest_4

    s21_strcat_test();

#endif

#ifdef Quest_5

    s21_strchr_test();

#endif

#ifdef Quest_6

    s21_strstr_test();

#endif

#ifdef Quest_7

    s21_strtok_test();

#endif

    return 0;
}

void s21_strlen_test(int attempt, const char *str) {
    int len = s21_strlen(str);
    char *res;
    if (len == attempt) {
        res = "SUCCESS";
    } else {
        res = "FAIL";
    }
    if (str != NULL)
        printf("%s\n%d\n%s\n\n", str, len, res);
    else
        printf("NULL\n%d\n%s\n\n", len, res);
}

void s21_strcmp_test(int attempt, const char *str1, const char *str2) {
    int cmp = s21_strcmp(str1, str2);
    char *res;
    if (cmp == attempt) {
        res = "SUCCESS";
    } else {
        res = "FAIL";
    }
    printf("%s | %s\n%d\n%s\n\n", str1, str2, cmp, res);
}

void s21_strcpy_test(char *result, char *str2) {
    char *res;
    if (result) {
        res = "SUCCESS";
    } else {
        res = "FAIL";
    }
    if (str2 != NULL)
        printf(" | %s\n%s\n%s\n\n", str2, result, res);
    else
        printf(" | NULL\n%s\n%s\n\n", result, res);
}

void s21_strcat_test() {
    char *test_cases[][2] = {
        {"SAMPL", "E"},
        {"sampl", "e"},
        {"Spaced ", "sample"},
        {"W i d e ", "S a m p l e"},
        {"FirstIsVeryLong ", "SecondIsShort"},
        {"FirstIsShort", " SecondIsVeryLong"},
    };
    char *results[] = {
        "SAMPLE",
        "sample",
        "Spaced sample",
        "W i d e S a m p l e",
        "FirstIsVeryLong SecondIsShort",
        "FirstIsShort SecondIsVeryLong",
    };
    int count = sizeof(results) / sizeof(char *);

    for (int i = 0; i < count; i++) {
        char test_string[100] = "empty";

        s21_strcpy(test_string, test_cases[i][0]);
        printf("%s | %s\n", test_cases[i][0], test_cases[i][1]);
        s21_strcat(test_string, test_cases[i][1]);
        printf("%s\n", test_string);

        if (s21_strcmp(test_string, results[i]) == 0) {
            printf("SUCCESS");
        } else {
            printf("FAIL");
        }

        if (i != count - 1) {
            printf("\n\n");
        }
    }
}

void s21_strchr_test() {
    char *test_strings[] = {
        "Hello, World!", "abcdefg", "Lorem ipsum sit dolor amet",
        "aabbccdd",      "qwerty",  "segfaults are my life",
        "xyz",           "",
    };
    char test_symbols[] = {
        'l', 'a', 'i', 'b', 'r', 's', 'a', 'x',
    };
    char *results[] = {
        "llo, World!", "abcdefg", "ipsum sit dolor amet", "bbccdd", "rty", "segfaults are my life",
        "(null)",      "(null)",
    };
    int count = sizeof(results) / sizeof(char *);

    for (int i = 0; i < count; i++) {
        printf("%s | %c\n", test_strings[i], test_symbols[i]);
        char *res = s21_strchr(test_strings[i], test_symbols[i]);
        if (res != NULL)
            printf("%s\n", res);
        else
            printf("NULL");

        if ((!res && s21_strcmp(results[i], "(null)") == 0) || s21_strcmp(res, results[i]) == 0) {
            printf("SUCCESS");
        } else {
            printf("FAIL");
        }

        if (i != count - 1) {
            printf("\n\n");
        }
    }
}

void s21_strstr_test() {
    char *test_cases[][2] = {
        {"SAMPLE", "AM"},
        {"sample", "mpl"},
        {"Spaced sample", " s"},
        {"W i d e S a m p l e", "i d e"},
        {"LongNum3ricS4mple", "3r"},
        {"www.google.com", ".g"},
        {"sorry for (null) :/", "ok."},
    };
    char *results[] = {
        "AMPLE", "mple", " sample", "i d e S a m p l e", "3ricS4mple", ".google.com", "(null)",
    };
    int count = sizeof(results) / sizeof(char *);

    for (int i = 0; i < count; i++) {
        printf("%s | %s\n", test_cases[i][0], test_cases[i][1]);
        char *res = s21_strstr(test_cases[i][0], test_cases[i][1]);
        if (res != NULL)
            printf("%s\n", res);
        else
            printf("NULL");

        if ((!res && s21_strcmp(results[i], "(null)") == 0) || s21_strcmp(res, results[i]) == 0) {
            printf("SUCCESS");
        } else {
            printf("FAIL");
        }

        if (i != count - 1) {
            printf("\n\n");
        }
    }
}

void s21_strtok_test() {
    char *test_cases[][2] = {
        {"Hello, my name is kek", ","},     {"Important or not", " "},   {"abcdefg", "d"},
        {"I'm too curious", "o"},           {"LongNum3ricS4mple", "a4"}, {"google.com", "."},
        {"Can't find this letter...", "b"}, {"Full string", ""}};
    char *results[] = {
        "Hello",      "Important", "abc", "I'm t", "LongNum3ricS", "google", "Can't find this letter...",
        "Full string"};
    int count = sizeof(results) / sizeof(char *);

    for (int i = 0; i < count; i++) {
        printf("%s | %s\n", test_cases[i][0], test_cases[i][1]);
        char *res = s21_strtok(test_cases[i][0], test_cases[i][1]);
        printf("%s\n", results[i]);

        if (s21_strcmp(results[i], results[i]) == 0 && res) {
            printf("SUCCESS");
        } else {
            printf("FAIL");
        }

        if (i != count - 1) {
            printf("\n\n");
        }
    }
}
