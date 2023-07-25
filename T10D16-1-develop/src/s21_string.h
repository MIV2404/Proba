#ifndef S21_STRING_H
#define S21_STRING_H

int s21_strlen(char const *str);
int s21_strcmp(const char *str1, const char *str2);
char *s21_strcpy(char *str1, const char *str2);
char *s21_strcat(char *dest, char *addition);
char *s21_strchr(char *str, int symbol);
char *s21_strstr(char *str1, char *str2);
int *create_delim_dict(char *delim);
char *s21_strtok(char *str, char *delim);

#endif