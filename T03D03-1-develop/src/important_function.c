#include <stdio.h>
#include <math.h>

int main(void) {
    char ent;
    double x;
    if (scanf("%lf%c", &x, &ent) == 2 && ent == '\n')
        {
            double y = 7e-3 * pow(x, 4) + ((22.8 * pow(x, (1 / 3)) - 1e3) * x + 3) / (pow(x, 2) / 2) - x * pow((10 + x), (2 / x)) - 1.01;
            printf("%.1lf\n", y);
        }
        else
        {
            printf("n/a\n");
        }
    return 0;
} 
