#include <stdio.h>

#ifndef CIPHER_H
#define CIPHER_H

void menu(int *menu_n);
char *f_name();
int reader(char *path);
int read_f(FILE *file);
int writer(char *path);
void write_f(FILE *file);
int isFileEmpty(FILE *file);
void cesar_ciphr(int n);
void encrypt(int n, char *path);
void get_symbol(FILE *file, int *flag, char c, int n);
void cesar_ciphr(int n);

#endif