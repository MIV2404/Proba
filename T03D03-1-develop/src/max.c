#include <stdio.h>

int main(void) {
    int a, b;
    char ent;
    if (scanf("%d %d%c", &a, &b, &ent) == 3 && ent == '\n') 
    
        if (a > b) 
        {
            printf("%d\n", a);
        } 
        else 
        {
            printf("%d\n", b);
        }
    else
    {
        printf("n/a\n");
    }
    return 0;
}