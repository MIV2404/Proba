#include <math.h>
#include <stdio.h>

int main(void) {
    double f1, f2, f3, pi = 3.14159265358979323846, ind = -pi;

    freopen("data/door_data.txt", "w", stdout);
    while (ind <= pi) {
        f1 = 1 / (1 + pow(ind, 2));
        f2 = sqrt(sqrt(1 + 4 * pow(ind, 2)) - pow(ind, 2) - 1);
        f3 = 1 / pow(ind, 2);
        if (f2 > 1e-7) {
            printf("%.7lf|%.7lf|%.7lf|%.7lf\n", ind, f1, f1, f1);
        } else {
            printf("%.7lf|%.7lf|-|%.7lf\n", ind, f1, f3);
        }
        ind += 2 * pi / 41;
    }
    fclose(stdout);
    return 0;
}