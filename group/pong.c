#include <stdio.h>

void draw(float ball_x, float ball_y, int r1_y, int r2_y);

int main(void) {
    char c, tmp;
    int player1 = 0, player2 = 0;
    float ball_x = 40, ball_y = 12;
    int r1_y = 12, r2_y = 12;
    int ball_speed_x = -1, ball_speed_y = 1;
    int game = 1;
    while (game == 1) {
        printf("\033[2J");
        if (player1 > 20) {
            game = 0;
            printf("Player 1 Wins!!!\n");
        }
        if (player2 > 20) {
            game = 0;
            printf("Player 2 Wins!!!\n");
        }

        draw(ball_x, ball_y, r1_y, r2_y);
        printf("\nPlayer 1: %d                                 Player 2: %d\n", player1, player2);

        if ((ball_x == 8) && (ball_y == r1_y || ball_y == r1_y + 1 || ball_y == r1_y - 1))
            ball_speed_x = 1;  //обработка попаданий мяча в ракетки
        if ((ball_x == 72) && (ball_y == r2_y || ball_y == r2_y + 1 || ball_y == r2_y - 1)) ball_speed_x = -1;

        if (ball_y < 2) ball_speed_y = 1;  //обработка попаданий мяча в стенки
        if (ball_y > 22) ball_speed_y = -1;

        scanf("%c%c", &c, &tmp);
        if (tmp == '\n') {
            if ((r1_y < 22) && (c == 'Z' || c == 'z'))  //обработка движения ракеток
                r1_y += 1;
            else if ((r1_y > 2) && (c == 'A' || c == 'a'))
                r1_y -= 1;
            else if ((r2_y < 22) && (c == 'M' || c == 'm'))
                r2_y += 1;
            else if ((r2_y > 2) && (c == 'K' || c == 'k'))
                r2_y -= 1;

            if (c == 'Z' || c == 'z' || c == 'A' || c == 'a' || c == 'M' || c == 'm' || c == 'K' ||
                c == 'k' ||  //обновление координат мяча
                c == ' ') {
                ball_x += ball_speed_x;
                ball_y += ball_speed_y;
            }
        } else
            while ((tmp = getchar()) != '\n')

                if (ball_x == 7 && (r1_y - ball_y == 2) && ball_speed_y == 1) {  //краевые ситуации
                    ball_speed_x = 1;
                    ball_speed_y = -1;
                }
        if (ball_x == 7 && (ball_y - r1_y == 2) && ball_speed_y == -1) {
            ball_speed_x = 1;
            ball_speed_y = 1;
        }
        if (ball_x == 73 && (r2_y - ball_y == 2) && ball_speed_y == 1) {
            ball_speed_x = -1;
            ball_speed_y = -1;
        }
        if (ball_x == 73 && (ball_y - r2_y == 2) && ball_speed_y == -1) {
            ball_speed_x = -1;
            ball_speed_y = 1;
        }
        if (ball_x < 1) {  //обработка голов
            player2++;
            r1_y = 12, r2_y = 12;
            ball_x = 40;
            ball_y = 12;
            ball_speed_x = 1;
            ball_speed_y = -1;
        }
        if (ball_x > 78) {
            player1++;
            r1_y = 12, r2_y = 12;
            ball_y = 12;
            ball_x = 40;
            ball_speed_x = -1;
            ball_speed_y = 1;
        }
    }
    return 0;
}

void draw(float ball_x, float ball_y, int r1_y, int r2_y) {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            if (i == 0 || i == 24)
                printf("-");
            else if (j == 0 || j == 79)
                printf("|");
            else if (j == 7 && (i == r1_y || i == r1_y - 1 || i == r1_y + 1))
                printf("<");
            else if (j == 73 && (i == r2_y || i == r2_y - 1 || i == r2_y + 1))
                printf(">");
            else if (j == (int)ball_x && i == (int)ball_y)
                printf("O");
            else if (j == 40)
                printf("|");
            else
                printf(" ");
        }
        printf("\n");
    }
}
