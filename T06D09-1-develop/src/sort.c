#include <stdio.h>
#define NMAX 10

int input(int *a);
void output(int *a);
void sorting(int *a);

int main() {
  int data[NMAX];
  if (input(data)) {
    printf("n/a\n");
  } else {
    sorting(data);
    output(data);
  }

  return 0;
}

int input(int *a) {
  char ent;
  int err = 0;

  for (int p = 0; p < NMAX; p++) {
    if (p != NMAX - 1) {
      if (scanf("%d", &a[p]) != 1) {
        err = 1;
      }
    } else if (scanf("%d%c", &a[p], &ent) != 2 || ent != '\n') {
      err = 1;
    }
  }

  return err;
}

void output(int *a) {
  for (int i = 0; i < NMAX; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void sorting(int *a) {
  int p;
  for (int i = 0; i < NMAX - 1; i++) {
    for (int j = 0; j < NMAX - 1; j++) {
      if (a[j] > a[j + 1]) {
        p = a[j];
        a[j] = a[j + 1];
        a[j + 1] = p;
      }
    }
  }
}