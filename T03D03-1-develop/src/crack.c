# include <stdio.h>

int main(void) {
    double x, y;
    char ent;

    if (scanf("%lf %lf%c", &x, &y, &ent) != 3 || ent != '\n')
        { 
            printf("n/a\n");
            return 0;
        }
        if (x * x + y * y <= 25) 
        {
            puts("GOTCHA");
        }
        else 
        {
            puts("MISS");
        }
    return 0;
}