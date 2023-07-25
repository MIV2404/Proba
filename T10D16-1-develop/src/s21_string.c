#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

int s21_strlen(char const *str) {
    int length = 0;
    if (str != NULL) {
        while (str[length] != '\0') {
            length++;
        }
    } else
        length = -1;

    return length;
}

int s21_strcmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(char *)str1 - *(char *)str2;
}

char *s21_strcpy(char *str1, const char *str2) {
    char *original_str = str1;  // Сохраняем указатель на начало str1

    while ((*str1++ = *str2++))
        ;  // Копируем символы из str2 в str1 до символа '\0'

    return original_str;  // Возвращаем указатель на начало str1
}

char *s21_strcat(char *dest, char *addition) {
    int str1_length = s21_strlen(dest);
    int str2_length = s21_strlen(addition);

    for (int i = 0; i <= str2_length; i++) {
        dest[str1_length + i] = addition[i];
    }

    return dest;
}

char *s21_strchr(char *str, int symbol) {
    char *ptr = 0;
    while (*str != '\0') {
        if (*str == symbol) {
            ptr = str;
            break;
        }
        str++;
    }
    return ptr;
}

char *s21_strstr(char *str1, char *str2) {
    char *ptr = 0;
    while (*str1 != '\0') {
        char *tmp = str1;
        char *tmp2 = str2;
        while (*tmp == *tmp2) {
            tmp++;
            tmp2++;
            if (*tmp2 == '\0') {
                ptr = str1;
                break;
            }
        }
        str1++;
    }
    return ptr;
}

int *create_delim_dict(char *delim) {
    int *d = (int *)malloc(10 * sizeof(int));
    int i;
    for (i = 0; i < s21_strlen(delim); i++) {
        d[(int)delim[i]] = 1;
    }
    return d;
}

char *s21_strtok(char *str, char *delim) {
    static char *last, *strToFree;
    int *deliDict = create_delim_dict(delim);
    if (!deliDict) {
        return NULL;
    }
    if (str) {
        last = (char *)malloc(s21_strlen(str) + 1);
        if (!last) {
            free(deliDict);
        }
        strToFree = last;
        s21_strcpy(last, str);
    }
    while (deliDict[(int)*last] && *last != '\0') {
        last++;
    }
    str = last;
    if (*last == '\0') {
        free(deliDict);
        free(strToFree);
        return NULL;
    }
    while (*last != '\0' && !deliDict[(int)*last]) {
        last++;
    }
    *last = '\0';
    last++;

    free(strToFree);
    free(deliDict);
    return str;
}