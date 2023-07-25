#include <stdio.h>

#define MAX 10

void input(int *buffer, int *length);
void output(int *numbers, int number);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
  int buffer[MAX], length;
  int numbers[MAX], number = 0;

  input(buffer, &length);
  if (length != 0) {
    int summ = sum_numbers(buffer, length);
    if (summ != 0) {
      printf("%d\n", summ);
      output(numbers, find_numbers(buffer, length, number, numbers));
    } else {
      printf("n/a\n");
    }
  } else {
    printf("n/a\n");
  }
  return 0;
}

void input(int *buffer, int *length) {
  char endl;

  if (scanf("%d%c", length, &endl) != 2 || endl != '\n') {
    *length = 0;
  }

  if (*length <= 0 || *length > MAX) {
    *length = 0;
  }

  int i = 0;

  for (int *p = buffer; i < *length; ++p) {
    if (i == *length - 1) {
      if (scanf("%d%c", p, &endl) != 2 || endl != '\n') {
        *length = 0;
      }
    } else if (scanf("%d", p) != 1) {
      *length = 0;
    }
    i++;
  }
}

void output(int *numbers, int number) {
  if (number == 0)
    return;

  for (int i = 0; i < number; i++) {
    if (i == number - 1) {
      printf("%d", *(numbers + i));
    } else {
      printf("%d ", *(numbers + i));
    }
  }
  printf("\n");
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
  int sum = 0;

  for (int i = 0; i < length; i++) {
    if (buffer[i] % 2 == 0) {
      sum += buffer[i];
    }
  }

  return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
  int sum = sum_numbers(buffer, length);

  for (int i = 0; i < length; i++) {
    if (buffer[i] != 0 && sum % buffer[i] == 0) {
      numbers[number] = buffer[i];
      number++;
    }
  }

  return number;
}