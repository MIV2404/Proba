#include "cipher.h"

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int menu_n;
    char *path = NULL;
    do {
        menu(&menu_n);      // считываем пункт меню
        if (menu_n == 1) {  // чтение
            if (path != NULL) free(path);
            path = f_name();
            if (path == NULL || reader(path)) continue;
        } else if (menu_n == 2) {  // запись
            if (path == NULL || writer(path)) {
                free(f_name());
                printf("n/a\n");
                continue;
            }
            reader(path);
        } else if (menu_n == 3) {  // шифрование
            rewind(stdin);
            int n;
            menu(&n);
            if (n != -2) {
                cesar_ciphr(n);
            } else
                printf("n/a\n");
        } else if (menu_n == -1)
            continue;
        else
            printf("n/a\n");
    } while (menu_n != -1);
    free(path);
    return 0;
}

void menu(int *menu_n) {
    rewind(stdin);

    char c;

    scanf("%d%c", menu_n, &c);

    if (c != '\n') {
        *menu_n = -2;
    }
}

char *f_name() {
    char *path = NULL;
    int i = 0;
    char ch = '\0';  // Инициализируем переменную ch

    while (ch != '\n') {
        if (scanf("%c", &ch) != EOF) {
            char *temp = (char *)realloc(path, (i + 1) * sizeof(char));
            if (temp == NULL) {
                free(path);
                printf("n/a\n");
                path = NULL;  // Возвращаем NULL в случае ошибки realloc
            } else {
                path = temp;
            }

            if (ch != '\n') {
                path[i] = ch;
                i++;
            } else {
                path[i] = '\0';
            }
        } else {
            path = NULL;
        }
    }

    return path;
}

int reader(char *path) {
    int flag = 1;
    FILE *file = NULL;
    file = fopen(path, "r");

    if (file == NULL) {
        printf("n/a\n");
        flag = 0;
    } else {
        if (read_f(file) == 0) {
            printf("n/a\n");
            flag = 0;
        }

        fclose(file);
    }

    return flag;
}

int read_f(FILE *file) {
    int empty_f = 0;
    char text[256];

    while ((fgets(text, 256, file)) != NULL) {
        printf("%s", text);
        empty_f++;
    }

    if (empty_f) {
        printf("\n");
    }

    return empty_f;
}

int writer(char *path) {
    rewind(stdin);
    int flag = 0;

    FILE *file = NULL;
    file = fopen(path, "r+");

    if (file == NULL) {
        flag = 1;
    } else {
        char text[256];
        while ((fgets(text, 256, file)) != NULL) {
            continue;
        }

        write_f(file);
        fclose(file);

        text[0] = '\n';
    }

    return flag;
}

void write_f(FILE *file) {
    char *input;

    input = f_name();

    if (input != NULL) {
        // if (isFileEmpty(file)) {
        fputs(input, file);
        // } else {
        //     fprintf(file, "\n%s", input);
        // }
    }
    free(input);
}

// int isFileEmpty(FILE *file) {
//     fseek(file, 0, SEEK_END);
//     long fileSize = ftell(file);
//     return (fileSize == 0) ? 1 : 0;
// }

void encrypt(int n, char *path) {
    FILE *file_1 = NULL;
    FILE *file_2 = NULL;

    file_1 = fopen(path, "r");
    file_2 = fopen(path, "r+");

    int flag;
    char c;
    c = getc(file_1);

    while (!feof(file_1)) {
        flag = 0;
        get_symbol(file_2, &flag, c, n);
        c = getc(file_1);
    }

    fclose(file_1);  // закрываем первый файл
    fclose(file_2);  // закрываем второй файл
}

void get_symbol(FILE *file, int *flag, char c, int n) {
    if (c >= 'A' && c <= 'Z') {
        c = c + (n % 26);

        if (c > 'Z') {
            c = 'A' + (c - 'Z') - 1;
        }

        fputc(c, file);
        *flag = 1;
    }

    if (c >= 'a' && c <= 'z') {
        c = c + (n % 26);
        if (c > 'z') {
            c = 'a' + (c - 'z') - 1;
        }

        fputc(c, file);
        *flag = 1;
    }

    if (!*flag) {
        fputc(c, file);
    }
}

void cesar_ciphr(int n) {
    DIR *dir = opendir("../src/ai_modules/");
    struct dirent *elem;
    while ((elem = readdir(dir)) != 0) {
        if (strstr(elem->d_name, ".c") != NULL) {
            char tmp[1024] = "";
            strcat(tmp, "../src/ai_modules/");
            strcat(tmp, elem->d_name);
            encrypt(n, tmp);
        }
        if (strstr(elem->d_name, ".h") != NULL) {
            char tmp[1024] = "";
            strcat(tmp, "../src/ai_modules/");
            strcat(tmp, elem->d_name);
            FILE *file = NULL;
            file = fopen(tmp, "w");
            fclose(file);
        }
    }
    closedir(dir);
}
