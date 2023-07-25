#include <stdio.h>
int fibonacci(int n) {
    if (n == 1 || n == 2) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main() {
    int n;
    char c;
    if (scanf("%d%c", &n, &c) == 2 && c == '\n' && n > 0) {
        printf("%d\n", fibonacci(n));
    } else {
        printf("n/a\n");
    }

    return 0;
}