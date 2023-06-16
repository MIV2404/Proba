// ввод/вывод данных с клавиатуры

// # include <stdio.h>

// int main(void)
// {
//     int var_k = getchar();
//     int var_h = 100;
//     int var_i = -1283;
//     double var_d = 54.34675;
//     long double var_ld = 0.5;

//     int res = putchar(var_k);
//     printf("var_k = %d, var_h = %d, var_i = %d, %Lf\n", res, var_h, var_i, var_ld);
//     printf("*%10d*\n", var_i);
//     printf("[%10d]\n", var_d);

//     return 0;
// }

// # include <stdio.h>

// int main(void)
// {
//     char byte1 = '0', byte2 = '0';

//     int res = scanf("%c %c", &byte1, &byte2); // считывание данных в заданном формате форматная строка

//     printf("res = %d: byte1 = %c, byte2 = %c\n", res, byte1, byte2);
//     return 0;
// }


# include <stdio.h>

int main(void)
{
    long long var_lli = 0;
    float k;
    int res = scanf("%d %d", &var_lli, &k);
    printf("res = %d: var_lli = %lld\n", res, var_lli, k);
    return (0);
}

// #include <stdio.h>
// #include <string.h>

// int main(void) {
// 	char one = '?';
// 	char two = '\?';

// 	printf("Compare chars: %d - %d\n", one, two);
// 	if (one == two){
// 		printf("It's equal!\n\n");
// 	} else {
// 		printf("It isn't equal!\n\n");
// 	}

// 	char tree[] = "?";
// 	char four[] = "\?";

// 	printf("Compare strings: %s - %s\n", tree, four);
// 	if (strcmp(tree, four) == 0){
// 		printf("It's equal!\n");
// 	} else {
// 		printf("It isn't equal!\n");
// 	}
//   return 0;
// }
