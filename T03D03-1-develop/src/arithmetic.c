#include <stdio.h>

int main(void) {
    int a, b;
    char ent;
    if (scanf("%d %d%c", &a, &b, &ent) == 3 && ent == '\n') 
    {
        if (b != 0) 
        {
            printf("%d %d %d %d\n", a + b, a - b, a * b, a / b);
        } 
        else 
        {
            printf("%d %d %d n/a\n", a + b, a - b, a * b);
        }

    }
    else
    {
        printf("n/a\n");
    }
    return 0;
}